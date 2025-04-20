#include "Memory/Allocator/USlabAllocater.h"

namespace wkr::mem {

int RoundToUpperPowerOfTwo(int n) {
  if (n <= 0)
    return -1;

  if ((n & (n - 1)) == 0)
    return n;

  int lowerPower = __builtin_ctz(~n);
  int upperPower = 1 << lowerPower;

  return upperPower;
}

void* USlabAllocator::Allocate(i32 size) {
  size = RoundToUpperPowerOfTwo(size);

  FSlabCacheGroup slabCacheGroup = m_SlabSizeMap[size];

  if (slabCacheGroup.AvailableSlabCache == nullptr) {
    slabCacheGroup.AvailableSlabCache = new FSlabCache(
        m_MemoryPool.Allocate(size * FSlabCache::kObjectSize), size);
  }

  FSlabCache* slabCache = slabCacheGroup.AvailableSlabCache;
  FSlabObject& slabObject = slabCache->SlabObjects[slabCache->SlabObjectIndex];

  slabObject.isUsed = true;
  slabCache->SlabObjectIndex = slabObject.nextSlabObjectIndex;

  if (slabObject.nextSlabObjectIndex == -1) {
    slabCacheGroup.AvailableSlabCache = slabCache->nextSlabCache;

    FSlabCache* swapSlabCache = slabCacheGroup.FullSlabCache;
    slabCacheGroup.FullSlabCache = slabCache;
    slabCache->nextSlabCache = swapSlabCache;
  }

  return reinterpret_cast<void*>(slabObject.MemoryAdress);
}

void USlabAllocator::Deallocate(void* ptr) {

}

}  // namespace wkr::mem
