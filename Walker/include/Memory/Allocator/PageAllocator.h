#pragma once

#include <Memory/Allocator.h>

namespace wkr::mem
{
  class IPageAllocator : public IAllocator
  {
  public:
    enum class PageSize
    {
      Default   ,
      LargePage ,
    };

  public:
    virtual void* Allocate(int size) override = 0;
    virtual void* Allocate(int size, PageSize pageSize) = 0;
    virtual void* Reallocate(void* ptr, int newSize) override = 0;
    virtual void* Deallocate(void* ptr) override = 0;
  };
}
