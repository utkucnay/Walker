#include <Platforms/Windows/WindowsPageAllocator.h>

namespace wkr::mem
{
  void* UWindowPageAllocator::Allocate(int size)
  {
    return VirtualAlloc(
        0,
        size,
        MEM_RESERVE | MEM_COMMIT,
        m_pageSizeMap[m_pageSize]);
  }

  void* UWindowPageAllocator::Allocate(int size, EPageSize pageSize)
  {
    return VirtualAlloc(
        0,
        size,
        MEM_RESERVE | MEM_COMMIT,
        m_pageSizeMap[pageSize]);
  }

  void* UWindowPageAllocator::Reallocate(void* ptr, int newSize)
  {
    Deallocate(ptr);
    return Allocate(newSize);
  }

  void UWindowPageAllocator::Deallocate(void* ptr)
  {
    VirtualFree(
        ptr,
        0,
        MEM_RELEASE);
  }
}
