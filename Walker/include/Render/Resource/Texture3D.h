#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Texture3D : public Resource
  {
  public:
    virtual ~Texture3D() override {}

  public:
    std::string GetTypeName() override final { return "Texture3D"; }

    virtual uint64_t  GetWidth()  = 0;
    virtual uint64_t  GetHeight() = 0;
    virtual uint64_t  GetDepth()  = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture3D"; }
  };
}
