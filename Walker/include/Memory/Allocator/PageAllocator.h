#pragma once

#include <Memory/Allocator.h>

namespace wkr::mem
{
  enum class EPageSize
  {
    Default   ,
    LargePage ,
  };

  struct FPageAllocatorDesc
  {
    EPageSize pageSize;
  };

  class IPageAllocator : IAllocator
  {
  public:
    virtual void* Allocate(int size) = 0;
    virtual void* Reallocate(void* ptr, int newSize) = 0;
    virtual void Deallocate(void* ptr) = 0;

    virtual FPageAllocatorDesc GetDesc() const = 0;
  };

  using PageAllocatorHandle = mem::TRef<IPageAllocator>;
}
