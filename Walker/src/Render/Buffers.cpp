#include "Render/Resource/Heap.h"
#include <Render/Core/RendererAPI.h>
#include <Platforms/DirectX12/Resource/DX12Buffers.h>

namespace wkr::render::rsc
{
  mem::Scope<Factory<Buffers, ResourceBuilder<Buffers>*>>
    BuffersBuilder::GetFactory()
  {
    return RendererAPI::GetAbstractFactory()->GetBuffersFactory();
  }

  GenericBuffersBuilder::GenericBuffersBuilder()
  {
    m_buffersBuilder = mem::Scope<BuffersBuilder>::Create();

    m_buffersBuilder->SetType(ResourceBuilderType::Reserved);
    m_buffersBuilder->SetAlignment(0);
    m_buffersBuilder->SetHeight(1);
    m_buffersBuilder->SetDepthOrArraySize(1);
    m_buffersBuilder->SetMipLevels(1);
    m_buffersBuilder->SetFormat(Format::UNKNOWN);
    m_buffersBuilder->SetSample(SampleDesc(1, 0));
    m_buffersBuilder->SetTextureLayout(Texture::Layout::RowMajor);
    m_buffersBuilder->SetFlag(Resource::Flag::None);
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetCommittedType(
      Heap::Type heapType, Heap::Flag flag)
  {
    HeapBuilder hb;
    hb
      .SetType(heapType)
      .SetCPUPageProperty(Heap::CPUPageProperty::Unknown)
      .SetMemoryPool(Heap::MemoryPool::Unknown)
      .SetAlignment(0)
      .SetFlag(flag);


    m_buffersBuilder->SetHeapBuilder(hb);
    m_buffersBuilder->SetType(ResourceBuilderType::Committed);
    return *this;
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetReservedType()
  {
    m_buffersBuilder->SetType(ResourceBuilderType::Reserved);
    return *this;
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetPlacedType(
      Heap* heap, uint64_t heapOffset)
  {
    m_buffersBuilder->SetHeap(heap);
    m_buffersBuilder->SetHeapOffset(heapOffset);
    m_buffersBuilder->SetType(ResourceBuilderType::Placed);
    return *this;
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetSize(uint64_t size)
  {
    m_buffersBuilder->SetWidth(size);
    return *this;
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetAlignment(
      uint64_t alignment)
  {
    m_buffersBuilder->SetAlignment(alignment);
    return *this;
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetFlag(
      Resource::Flag flag)
  {
    m_buffersBuilder->SetFlag(flag);
    return *this;
  }
}
