#pragma once

#include <Memory/Allocator/PageAllocator.h>

namespace wkr::mem
{
  class UMemoryPool
  {
  public:
    UMemoryPool(u32 initialSize);

  public:

  private:
    PageAllocatorHandle m_pageAllocator;
  };
}

