#pragma once

#include "OS/Memory/IPageAllocator.h"

namespace wkr::os::windows {

class UPageAllocator : public IPageAllocator {
 public:
  UPageAllocator(const FPageAllocatorDesc& desc);

 public:
  void* Allocate(int size) override final;
  void* Reallocate(void* ptr, int newSize) override final;
  void Deallocate(void* ptr) override final;

  FPageAllocatorDesc GetDesc() const override;

 private:
  EPageSize m_pageSize;
  static inline std::unordered_map<EPageSize, DWORD> m_pageSizeMap = {
      {EPageSize::kDefault, 0},
      {EPageSize::kLargePage, MEM_LARGE_PAGES}};
};

}  // namespace wkr::os::windows
