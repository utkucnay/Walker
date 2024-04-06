#pragma once

#include <Memory/Allocator.h>

namespace wkr::mem
{
  class PageAllocator : public Allocator
  {
    enum class PageSize
    {
      Default,
      LargePage
    };

    virtual void* Allocate(int size) override = 0;
    virtual void* Allocate(int size, PageSize pageSize) = 0;
    void* Reallocate(void* ptr, int newSize) override { return NULL; }
    virtual void* Deallocate(void* ptr) override = 0;
  };
}
