#pragma once

#include <Render/Resource/ResourceBuilder.h>
#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  class Texture1D : public Texture
  {
  public:
    virtual ~Texture1D() override {}

  public:
    std::string GetTypeName() override final { return "Texture1D"; }

    virtual uint64_t  GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1D"; }
  };

  class Texture1DBuilder : public ResourceBuilder<Texture1D>
  {
  public:
    virtual mem::Scope<Factory<Texture1D, ResourceBuilder<Texture1D>*>> GetFactory();

  private:
    virtual Resource::Dimension GetDimension()
    { return Resource::Dimension::Texture1D; }
  };

  class GenericTexture1DBuilder : Builder<Texture1D>
  {

  };
}
