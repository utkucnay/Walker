#pragma once

#include <Render/Resource/ResourceBuilder.h>
#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  class ITexture1D : public ITexture
  {
  public:
    virtual ~ITexture1D() override {}

  public:
    std::string GetTypeName() override final { return "Texture1D"; }

    virtual uint64_t GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1D"; }
  };

  class Texture1DBuilder : public ResourceBuilder<ITexture1D>
  {
  public:
    virtual mem::Scope<IFactory<ITexture1D, ResourceBuilder<ITexture1D>&>> GetFactory();

  private:
    virtual IResource::Dimension GetDimension()
    { return IResource::Dimension::Texture1D; }
  };

  class GenericTexture1DBuilder : IBuilder<ITexture1D>
  {
  public:
    GenericTexture1DBuilder();

  public:
    GenericTexture1DBuilder& SetCommittedType(IHeap::Type heapType, IHeap::Flag flag);
    GenericTexture1DBuilder& SetReservedType();
    GenericTexture1DBuilder& SetPlacedType(IHeap& heap, uint64_t heapOffset);

  public:
    GenericTexture1DBuilder& SetTextureFormat(IResource::Format format);
    GenericTexture1DBuilder& SetWidth(u64 width);
    GenericTexture1DBuilder& SetArraySize(u16 arraySize);
    GenericTexture1DBuilder& SetMipLevels(u16 mipLevels);
    GenericTexture1DBuilder& SetResourceFlag(IResource::Flag flag);
    GenericTexture1DBuilder& SetLayout(IResource::Layout layout);
    GenericTexture1DBuilder& SetAlignment(u64 alignment);

    [[nodiscard]] Texture1DBuilder& GetBuilder() { return m_texture1DBuilder.Get(); }

  public:
    mem::Scope<Texture1DBuilder> m_texture1DBuilder;
  };
}
