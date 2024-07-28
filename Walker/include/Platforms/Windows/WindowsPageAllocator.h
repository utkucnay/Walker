#pragma once

#include <Memory/Allocator/PageAllocator.h>

namespace wkr::mem
{
  class UWindowPageAllocator : public IPageAllocator
  {
  public:
    UWindowPageAllocator() { m_pageSize = EPageSize::Default; };
    UWindowPageAllocator(EPageSize pageSize) { m_pageSize = pageSize; };

  public:
    void* Allocate(int size) override final;
    void* Allocate(int size, EPageSize pageSize) override final;
    void* Reallocate(void* ptr, int newSize) override final;
    void Deallocate(void* ptr) override final;

  private:
    EPageSize m_pageSize;
    std::unordered_map<EPageSize, DWORD> m_pageSizeMap =
    {
      {EPageSize::Default, 0},
      {EPageSize::LargePage, MEM_LARGE_PAGES}
    };
  };
}
