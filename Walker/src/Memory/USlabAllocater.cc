#include "Memory/Allocator/USlabAllocater.h"

namespace wkr::mem {

int RoundToUpperPowerOfTwo(int n) {
    if (n <= 0) return -1;

    if ((n & (n - 1)) == 0) return n;

    int lowerPower = __builtin_ctz(~n);
    int upperPower = 1 << lowerPower;

    return upperPower;
}

void* USlabAllocator::Allocate(i32 size) {
  size = RoundToUpperPowerOfTwo(size);

  FSlabCacheGroup slabCacheGroup = m_SlabSizeMap[size];
  FSlabCache slabCache;

  if (!slabCacheGroup.PartialSlabCache.empty()) {
    slabCache = slabCacheGroup.PartialSlabCache.front();
  } else if (!slabCacheGroup.EmptySlabCache.empty()) {
    slabCache = slabCacheGroup.EmptySlabCache.front();
  } else {
    slabCache = FSlabCache{
        .SlabObjectFlag = 0,
        .SlabObjectCount = 16,
        .MemoryAdrress = m_MemoryPool.Allocate(size * 16),
    };

    slabCacheGroup.PartialSlabCache.push_back(slabCache);
  }


}

}  // namespace wkr::mem
