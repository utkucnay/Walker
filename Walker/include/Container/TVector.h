#pragma once

#include "Memory/Core/IAllocator.h"

namespace wkr::ctnr {

template <typename T>
class TVector {
 public:
  explicit TVector(mem::IAllocator& allocator) {
    m_Allocator = allocator;
    m_Size = 0;
    m_Reserved = 0;
    m_Pointer = nullptr;
  }

  explicit TVector(size_t size) {

    m_Reserved = size;
    m_Size = size;
    m_Pointer = nullptr;
  }

 private:
  mem::IAllocator& m_Allocator;
  mem::TScope<T> m_Pointer;
  u32 m_Size;
  u32 m_Reserved;
};

}  // namespace wkr::ctnr
