#pragma once

#include<Memory/Allocator.h>

namespace wkr::ctnr
{
  template<typename T>
  class Vector
  {

  private:
    mem::Scope<mem::Allocator> m_allocator;
    T* ptr;
  };
}
