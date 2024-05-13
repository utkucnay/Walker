#pragma once

#include <Memory/Allocator/PageAllocator.h>

namespace wkr::mem
{
  class UWindowPageAllocator : public IPageAllocator
  {
    void* Allocate(int size) override final;
    void* Allocate(int size, IPageAllocator::PageSize pageSize) override final;
    void* Reallocate(void* ptr, int newSize) override final;
    void* Deallocate(void* ptr) override final;
  };
}
