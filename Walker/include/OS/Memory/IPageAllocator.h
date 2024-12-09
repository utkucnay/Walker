#pragma once

#include "Memory/Core/IAllocator.h"

namespace wkr::os {

struct WALKER_API FPageAllocatorDesc {
  EPageSize pageSize;
};

class WALKER_API IPageAllocator : wkr::mem::IAllocator {
 public:
  virtual void* Allocate(int size) = 0;
  virtual void* Reallocate(void* ptr, int newSize) = 0;
  virtual void Deallocate(void* ptr) = 0;

  virtual FPageAllocatorDesc GetDesc() const = 0;
};

using PageAllocatorHandle = wkr::mem::TRef<IPageAllocator>;

}  // namespace wkr::os::mem
