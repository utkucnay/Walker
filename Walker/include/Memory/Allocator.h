#pragma once

namespace wkr::memory
{
  class Allocator
  {
    virtual void* Allocate(int size) = 0;
    virtual void* Reallocate(void* ptr, int newSize) = 0;
    virtual void* Deallocate(void* ptr) = 0;
  };
}