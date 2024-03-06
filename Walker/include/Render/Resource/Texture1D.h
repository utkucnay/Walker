#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Texture1D : public Resource
  {
  public:
    virtual ~Texture1D() override {}

  public:
    std::string GetTypeName() override final { return "Texture1D"; }

    virtual uint64_t  GetSize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1D"; }
  };
}
