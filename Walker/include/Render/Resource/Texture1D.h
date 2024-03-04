#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Texture2D : public Resource
  {
  public:
    virtual ~Texture2D() override {}

  public:
    std::string GetTypeName() override final { return "Texture1D"; }

    virtual uint64_t  GetSize() = 0;
  };
}
