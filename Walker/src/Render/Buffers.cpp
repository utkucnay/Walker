#include <Render/Core/RendererAPI.h>
#include <Platforms/DirectX12/Resource/DX12Buffers.h>

namespace wkr::render::rsc
{
  mem::Scope<IFactory<IBuffers, ResourceBuilder<IBuffers>&>>
    BuffersBuilder::GetFactory()
  {
    return RendererAPI::GetAbstractFactory().GetBuffersFactory();
  }

  GenericBuffersBuilder::GenericBuffersBuilder()
  {
    m_buffersBuilder = mem::Scope<BuffersBuilder>::Create();

    m_buffersBuilder.Get()
      .SetType(ResourceBuilderType::Reserved)
      .SetAlignment(0)
      .SetHeight(1)
      .SetDepthOrArraySize(1)
      .SetMipLevels(1)
      .SetFormat(IResource::Format::UNKNOWN)
      .SetSample(FSample(1, 0))
      .SetTextureLayout(ITexture::Layout::RowMajor)
      .SetFlag(IResource::Flag::None);
  }

  GenericBuffersBuilder& GenericBuffersBuilder::SetCommittedType(
      IHeap::Type heapType, IHeap::Flag flag)
  {
    HeapBuilder hb;
    hb
      .SetType(heapType)
      .SetCPUPageProperty(IHeap::CPUPageProperty::Unknown)
      .SetMemoryPool(IHeap::MemoryPool::Unknown)
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
      mem::WeakRef<IHeap> heap,
      uint64_t heapOffset)
  {
    m_buffersBuilder.Get()
      .SetHeap(heap)
      .SetHeapOffset(heapOffset)
      .SetType(ResourceBuilderType::Placed);
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
      IResource::Flag flag)
  {
    m_buffersBuilder->SetFlag(flag);
    return *this;
  }
}
