#include <Platforms/Windows/WindowsPageAllocator.h>

namespace wkr::os::windows
{
  UPageAllocator::UPageAllocator(FPageAllocatorDesc& desc)
  {
    m_pageSize = desc.pageSize;
  }

  void* UPageAllocator::Allocate(int size)
  {
    return VirtualAlloc(
        0,
        size,
        MEM_RESERVE | MEM_COMMIT,
        m_pageSizeMap[m_pageSize]);
  }

  void* UPageAllocator::Reallocate(void* ptr, int newSize)
  {
    Deallocate(ptr);
    return Allocate(newSize);
  }

  void UPageAllocator::Deallocate(void* ptr)
  {
    VirtualFree(
        ptr,
        0,
        MEM_RELEASE);
  }

  FPageAllocatorDesc UPageAllocator::GetDesc() const
  {
    FPageAllocatorDesc desc;
    desc.pageSize = m_pageSize;
    return desc;
  }
}
