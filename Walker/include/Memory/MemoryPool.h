#pragma once

#include <Memory/Allocator/PageAllocator.h>

namespace wkr::mem
{
  class UMemoryPool
  {
  public:
    UMemoryPool(i32 size, PageAllocatorHandle pageAllocator);
  };
}

