#pragma once

#include "OS/Memory/IPageAllocator.h"

namespace wkr::mem {

class UMemoryPool {
 public:
  explicit UMemoryPool(u32 initialSize);

 public:
 private:
  os::IPageAllocatorHandle m_pageAllocator;
};

}  // namespace wkr::mem
