#pragma once

#include <Render/Resource/ResourceBuilder.h>
#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Buffers : public Resource
  {
  public:
    virtual ~Buffers() override {}

  public:
    std::string GetTypeName() override final { return "Buffers"; }

    virtual uint64_t GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Buffers"; }
  };

  class BuffersBuilder : public ResourceBuilder<Buffers>
  {
  public:
    virtual mem::Scope<Factory<Buffers, ResourceBuilder<Buffers>*>> GetFactory();

  private:
    virtual Resource::Dimension GetDimension()
    { return Resource::Dimension::Buffer; }
  };

  class GenericBuffersBuilder : Builder<Buffers>
  {
  public:
    GenericBuffersBuilder();

  public:
    GenericBuffersBuilder& SetCommittedType(Heap::Type heapType, Heap::Flag flag);
    GenericBuffersBuilder& SetReservedType();
    GenericBuffersBuilder& SetPlacedType(Heap* heap, uint64_t heapOffset);

    GenericBuffersBuilder& SetSize(uint64_t size);
    GenericBuffersBuilder& SetAlignment(uint64_t alignment);
    GenericBuffersBuilder& SetFlag(Resource::Flag flag);

    BuffersBuilder* GetBuilder() { return m_buffersBuilder.Get(); }

  public:
    Buffers* BuildRaw() { return m_buffersBuilder->BuildRaw(); }
    mem::Ref<Buffers> BuildRef() { return m_buffersBuilder->BuildRef(); }
    mem::Scope<Buffers> BuildScope() { return m_buffersBuilder->BuildScope(); }

  private:
    mem::Scope<BuffersBuilder> m_buffersBuilder;
  };
}
