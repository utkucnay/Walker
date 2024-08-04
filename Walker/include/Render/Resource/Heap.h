#pragma once

#include <Render/Resource/ResourceTypes.h>

namespace wkr::render
{
  struct FHeapDesc
  {
    u64 m_size;
    u64 m_alignment;
    EHeapType m_type;
    EHeapFlag m_flag;
    EMemoryPool m_memoryPool;
    ECPUPageProperty m_cpuPageProperty;
  };

  class IHeap
  {
  public:
    virtual ~IHeap() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;

  public:
    virtual u64 GetSize()       = 0;
    virtual u64 GetAlignment()  = 0;
    virtual EHeapType GetType() = 0;
    virtual EHeapFlag GetFlag() = 0;
    virtual EMemoryPool GetMemoryPool() = 0;
    virtual ECPUPageProperty GetCPUPageProperty()  = 0;
  };

  using IHeapHandle = mem::TRef<IHeap>;
}
