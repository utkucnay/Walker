#pragma once

#include "Graphics/Resource/ResourceType.h"

namespace wkr::render {

struct FHeapDesc {
  u64 m_size;
  u64 m_alignment;
  EHeapType m_type;
  EMemoryPool m_memoryPool;
  ECPUPageProperty m_cpuPageProperty;
  EHeapF m_flag;
};

class IHeap {
 public:
  virtual ~IHeap() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;

 public:
  virtual u64 GetSize() = 0;
  virtual u64 GetAlignment() = 0;
  virtual EHeapType GetType() = 0;
  virtual EHeapF GetFlag() = 0;
  virtual EMemoryPool GetMemoryPool() = 0;
  virtual ECPUPageProperty GetCPUPageProperty() = 0;
};

using IHeapHandle = mem::TRef<IHeap>;

}  // namespace wkr::render
