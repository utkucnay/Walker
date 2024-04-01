#pragma once

#include <Render/Resource/Resource.h>
#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  template<typename T>
  class ResourceBuilder : Builder<T>
  {
  public:
    enum Type
    {
      Committed ,
      Reserved  ,
      Placed    ,
    };

  public:
    ResourceBuilder& SetType(ResourceBuilder::Type type)
    { m_type = type; return *this; }
    ResourceBuilder& SetWidth(uint64_t width)
    { m_width = width; return *this; }
    ResourceBuilder& SetHeight(uint32_t height)
    { m_height = height; return *this; }
    ResourceBuilder& SetDepthOrArraySize(uint16_t depthOrArraySize)
    { m_depthOrArraySize = depthOrArraySize; return *this; }
    ResourceBuilder& SetMipLevels(uint16_t mipLevels)
    { m_mipLevels = mipLevels; return *this; }
    ResourceBuilder& SetFormat(Format format)
    { m_format = format; return *this; }
    ResourceBuilder& SetSample(SampleDesc sample)
    { m_sample = sample; return *this; }
    ResourceBuilder& SetTextureLayout(Texture::Layout layout)
    { m_layout = layout; return *this;}
    ResourceBuilder& SetFlag(Resource::Flag flag)
    { m_flag = flag; return *this; }

  public:
    T*            BuildRaw()   override { return GetFactory()->CreateFactoryRaw(this); }
    mem::Ref<T>   BuildRef()   override { return GetFactory()->CreateFactoryRef(this); }
    mem::Scope<T> BuildScope() override { return GetFactory()->CreateFactoryScope(this);}

  private:
    virtual Resource::Dimension GetDimension() = 0;
    virtual mem::Scope<Factory<T, ResourceBuilder*>> GetFactory() = 0;

  public:
    ResourceBuilder::Type m_type;
    uint64_t m_width;
    uint32_t m_height;
    uint16_t m_depthOrArraySize;
    uint16_t m_mipLevels;
    Format m_format;
    SampleDesc m_sample;
    Texture::Layout m_layout;
    Resource::Flag m_flag;
  };
}
