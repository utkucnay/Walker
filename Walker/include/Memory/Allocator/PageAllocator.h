#pragma once

namespace wkr::mem
{
  enum class EPageSize
  {
    Default   ,
    LargePage ,
  };

  class IPageAllocator
  {
  public:
    virtual void* Allocate(int size) = 0;
    virtual void* Allocate(int size, EPageSize pageSize) = 0;
    virtual void* Reallocate(void* ptr, int newSize) = 0;
    virtual void Deallocate(void* ptr) = 0;
  };

  using PageAllocatorHandle = mem::TRef<IPageAllocator>;
}
