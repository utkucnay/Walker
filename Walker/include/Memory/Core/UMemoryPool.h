#pragma once

#include "Memory/Core/IAllocator.h"

namespace wkr::mem {

class UMemoryPool {
 public:
  explicit UMemoryPool(u32 size, IAllocator& allocator);

 public:
  void* Allocate(i32 size) { return m_Allocator->Allocate(size); }

 public:
  mem::TScope<IAllocator> m_Allocator;
};

}  // namespace wkr::mem
