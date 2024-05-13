#pragma once

#include <Render/Resource/ResourceBuilder.h>
#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class IBuffers : public IResource
  {
  public:
    virtual ~IBuffers() override {}

  public:
    std::string GetTypeName() override final { return "Buffers"; }

    virtual u64 GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Buffers"; }
  };

  class BuffersBuilder : public ResourceBuilder<IBuffers>
  {
  public:
    virtual mem::Scope<IFactory<IBuffers, ResourceBuilder<IBuffers>&>> GetFactory();

  private:
    virtual IResource::Dimension GetDimension()
    { return IResource::Dimension::Buffer; }
  };

  class GenericBuffersBuilder : IBuilder<IBuffers>
  {
  public:
    GenericBuffersBuilder();

  public:
    GenericBuffersBuilder& SetCommittedType(IHeap::Type heapType, IHeap::Flag flag);
    GenericBuffersBuilder& SetReservedType();
    GenericBuffersBuilder& SetPlacedType(mem::WeakRef<IHeap> heap, u64 heapOffset);

    GenericBuffersBuilder& SetSize(u64 size);
    GenericBuffersBuilder& SetAlignment(u64 alignment);
    GenericBuffersBuilder& SetFlag(IResource::Flag flag);

    [[nodiscard]] BuffersBuilder& GetBuilder() { return m_buffersBuilder.Get(); }

  public:
    [[nodiscard]] IBuffers*            BuildRaw()   { return m_buffersBuilder->BuildRaw(); }
    [[nodiscard]] mem::Ref<IBuffers>   BuildRef()   { return m_buffersBuilder->BuildRef(); }
    [[nodiscard]] mem::Scope<IBuffers> BuildScope() { return m_buffersBuilder->BuildScope(); }

  private:
    mem::Scope<BuffersBuilder> m_buffersBuilder;
  };
}
