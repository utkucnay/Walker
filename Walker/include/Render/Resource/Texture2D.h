#pragma once

#include <Render/Resource/Texture.h>

namespace wkr::render
{
  struct FTexture2DDesc
  {

  };

  class ITexture2D : public ITexture
  {
  public:
    virtual ~ITexture2D() override = default;

  public:
    std::string GetTypeName() override final { return "Texture2D"; }

    virtual uint64_t    GetWidth()  = 0;
    virtual uint64_t    GetHeight() = 0;
    virtual FSample  GetMSAA()   = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture2D"; }
  };

  using ITexture2DHandle = mem::TRef<ITexture2D>;
}
