#pragma once

#include "Memory/Core/IAllocator.h"
#include "Memory/Core/UMemoryPool.h"

namespace wkr::mem {

class WALKER_API USlabAllocator : public IAllocator {
 public:
  explicit USlabAllocator(UMemoryPool memoryPool) : m_MemoryPool(memoryPool) {}

 public:
  void* Allocate(int size) override final;
  void* Reallocate(void* ptr, int newSize) override final;
  void Deallocate(void* ptr) override final;

 private:
  UMemoryPool m_MemoryPool;
};

}  // namespace wkr::mem
