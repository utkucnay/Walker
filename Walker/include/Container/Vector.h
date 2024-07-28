#pragma once

#include <Memory/Allocator.h>

namespace wkr::ctnr
{
  template<typename T>
  class TVector
  {

  private:
    mem::TScope<mem::IAllocator> m_allocator;
    T* ptr;
  };
}
