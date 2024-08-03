#pragma once

#include <Render/Resource/Texture.h>

namespace wkr::render
{
  class ITexture1D : public ITexture
  {
  public:
    virtual ~ITexture1D() override = default;

  public:
    std::string GetTypeName() override final { return "Texture1D"; }

    virtual uint64_t GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1D"; }
  };

  using ITexture1DHandle = mem::TRef<ITexture1D>;
}
