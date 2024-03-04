#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Texture2D : public Resource
  {
  public:
    virtual ~Texture2D() override {}

  public:
    std::string GetTypeName() override final { return "Texture3D"; }

    virtual uint64_t  GetWidth()  = 0;
    virtual uint64_t  GetHeight() = 0;
    virtual uint64_t  GetDepth()  = 0;
  };
}
