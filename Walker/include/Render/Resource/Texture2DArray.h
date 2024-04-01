#pragma once

#include <Render/Resource/Texture.h>

namespace wkr::render::rsc
{
  class Texture2DArray : public Texture
  {
  public:
    virtual ~Texture2DArray() override {}

  public:
    std::string GetTypeName() override final { return "Texture2DArray"; }

    virtual uint64_t    GetWidth()  = 0;
    virtual uint64_t    GetHeight() = 0;
    virtual SampleDesc  GetMSAA()   = 0;
    virtual uint64_t    GetArraySize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture2DArray"; }
  };
}
