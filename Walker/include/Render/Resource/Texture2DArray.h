#pragma once

#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  class ITexture2DArray : public ITexture
  {
  public:
    virtual ~ITexture2DArray() override {}

  public:
    std::string GetTypeName() override final { return "Texture2DArray"; }

    virtual uint64_t    GetWidth()  = 0;
    virtual uint64_t    GetHeight() = 0;
    virtual FSample  GetMSAA()   = 0;
    virtual uint64_t    GetArraySize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture2DArray"; }
  };
}
