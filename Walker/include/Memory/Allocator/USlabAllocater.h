#pragma once

#include "Memory/Core/IAllocator.h"
#include "Memory/Core/UMemoryPool.h"

namespace wkr::mem {

struct FSlabCache {
  u16 SlabObjectFlag;
  u16 SlabObjectCount;
  void* MemoryAdrress;
};

struct FSlabCacheGroup {
  std::list<FSlabCache> FullSlabCache;
  std::list<FSlabCache> PartialSlabCache;
  std::list<FSlabCache> EmptySlabCache;
};

class WALKER_API USlabAllocator : public IAllocator {
 public:
  explicit USlabAllocator(UMemoryPool& memoryPool) : m_MemoryPool(memoryPool) {}

 public:
  void* Allocate(int size) override final;
  void* Reallocate(void* ptr, int newSize) override final;
  void Deallocate(void* ptr) override final;

 private:
  std::unordered_map<u8, FSlabCacheGroup> m_SlabSizeMap;
  UMemoryPool& m_MemoryPool;
};

}  // namespace wkr::mem
