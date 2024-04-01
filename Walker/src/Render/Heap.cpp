#include "Render/Core/RendererAPI.h"
#include <Render/Resource/Heap.h>

namespace wkr::render::rsc
{
  HeapBuilder& HeapBuilder::SetSize(uint64_t size)
  {
    m_size = size;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetType(Heap::Type type)
  {
    m_type = type;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetCPUPageProperty(
      Heap::CPUPageProperty cpuPageProperty)
  {
    m_cpuPageProperty = cpuPageProperty;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetMemoryPool(Heap::MemoryPool memoryPool)
  {
    m_memoryPool = memoryPool;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetAlignment(uint64_t alignment)
  {
    m_alignment = alignment;
    return *this;
  }

  HeapBuilder& HeapBuilder::SetFlag(Heap::Flag flag)
  {
    m_flag = flag;
    return *this;
  }

  Heap* HeapBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetHeapFactory()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<Heap> HeapBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetHeapFactory()
      ->CreateFactoryRef(this);
  }

  mem::Scope<Heap> HeapBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetHeapFactory()
      ->CreateFactoryScope(this);
  }
}
