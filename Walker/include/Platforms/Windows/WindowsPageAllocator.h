#pragma once

#include <Memory/Allocator/PageAllocator.h>

using namespace wkr::mem;

namespace wkr::os::windows
{
  class UPageAllocator : public IPageAllocator
  {
  public:
    UPageAllocator(FPageAllocatorDesc& desc);

  public:
    void* Allocate(int size) override final;
    void* Reallocate(void* ptr, int newSize) override final;
    void Deallocate(void* ptr) override final;

    FPageAllocatorDesc GetDesc() const override;

  private:
    EPageSize m_pageSize;
    std::unordered_map<EPageSize, DWORD> m_pageSizeMap =
    {
      {EPageSize::Default, 0},
      {EPageSize::LargePage, MEM_LARGE_PAGES}
    };
  };
}
