#include "Render/Core/RendererAPI.h"
#include <Render/Resource/Heap.h>

namespace wkr::render::rsc
{
  HeapBuilder& HeapBuilder::SetSize(u64 size)
  {
    m_size = size;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetType(IHeap::Type type)
  {
    m_type = type;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetCPUPageProperty(
      IHeap::CPUPageProperty cpuPageProperty)
  {
    m_cpuPageProperty = cpuPageProperty;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetMemoryPool(IHeap::MemoryPool memoryPool)
  {
    m_memoryPool = memoryPool;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetAlignment(u64 alignment)
  {
    m_alignment = alignment;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetFlag(IHeap::Flag flag)
  {
    m_flag = flag;
    return *this;
  }

  REGISTER_BUILDER(I, Heap);
}
