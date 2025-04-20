#pragma once

#include "Memory/Core/IAllocator.h"
#include "Memory/Core/UMemoryPool.h"

namespace wkr::mem {

struct FSlabObject {
  b8 IsUsableAtomic = false;
  b8 isUsed = false;
  i8 nextSlabObjectIndex = -1;
  u64 MemoryAdress = 0;
};

struct FSlabCache {
  enum { kObjectSize = 32 };

  u16 ObjectSize;
  i8 SlabObjectIndex;
  FSlabObject SlabObjects[kObjectSize];

  FSlabCache* nextSlabCache;

  explicit FSlabCache(void* memoryAdress, u16 objectSize) {
    u64 memoryAdrressInt = reinterpret_cast<u64>(memoryAdress);
    ObjectSize = objectSize;

    for (int i = 0; i < kObjectSize; ++i) {
      FSlabObject& slabObject = SlabObjects[i];
      slabObject.IsUsableAtomic = (memoryAdrressInt & 64) == 0;
      slabObject.nextSlabObjectIndex = i + 1 >= kObjectSize ? -1 : i + 1;
      slabObject.MemoryAdress = memoryAdrressInt;

      memoryAdrressInt += ObjectSize;
    }
  }
};

struct FSlabCacheGroup {
  FSlabCache* FullSlabCache;
  FSlabCache* AvailableSlabCache;
};

class WALKER_API USlabAllocator : public IAllocator {
 public:
  explicit USlabAllocator(UMemoryPool& memoryPool) : m_MemoryPool(memoryPool) {}

 public:
  void* Allocate(int size) override final;
  void* Reallocate(void* ptr, int newSize) override final;
  void Deallocate(void* ptr) override final;

 private:
  std::unordered_map<u16, FSlabCacheGroup> m_SlabSizeMap;
  UMemoryPool& m_MemoryPool;
};

}  // namespace wkr::mem
