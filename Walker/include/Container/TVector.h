#pragma once

#include "Memory/Core/IAllocator.h"

namespace wkr::ctnr {

template <typename T>
class TVector {

 private:
  mem::TScope<mem::IAllocator> m_allocator;
  T* ptr;
};

}  // namespace wkr::ctnr
