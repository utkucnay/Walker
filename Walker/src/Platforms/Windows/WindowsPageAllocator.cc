#include "Platforms/Windows/Memory/WindowsPageAllocator.h"

namespace wkr::os::windows {

UPageAllocator::UPageAllocator(const FPageAllocatorDesc& desc) {
  m_pageSize = desc.pageSize;
}

void* UPageAllocator::Allocate(int size) {
  void* ret = VirtualAlloc(0, size, MEM_RESERVE | MEM_COMMIT |
                      m_pageSizeMap[m_pageSize], PAGE_READWRITE);

  WKR_CORE_ERROR_COND(ret == NULL, "%d", GetLastError());
  return ret;
}

void* UPageAllocator::Reallocate(void* ptr, int newSize) {
  Deallocate(ptr);
  return Allocate(newSize);
}

void UPageAllocator::Deallocate(void* ptr) {
  VirtualFree(ptr, 0, MEM_RELEASE);
}

FPageAllocatorDesc UPageAllocator::GetDesc() const {
  FPageAllocatorDesc desc;
  desc.pageSize = m_pageSize;
  return desc;
}

}  // namespace wkr::os::windows
