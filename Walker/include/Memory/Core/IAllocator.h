#pragma once

namespace wkr::mem {

class IAllocator {
 public:
  virtual ~IAllocator() = default;

 public:
  virtual void* Allocate(int size) = 0;
  virtual void* Reallocate(void* ptr, int newSize) = 0;
  virtual void Deallocate(void* ptr) = 0;
};

}  // namespace wkr::mem
