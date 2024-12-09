#pragma once

#include "OS/Memory/IPageAllocator.h"

namespace wkr::mem
{
  class UMemoryPool
  {
  public:
    UMemoryPool(u32 initialSize);

  public:

  private:
    os::mem::PageAllocatorHandle m_pageAllocator;
  };
}

