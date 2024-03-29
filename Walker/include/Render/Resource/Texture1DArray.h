#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Texture1DArray : public Resource
  {
  public:
    virtual ~Texture1DArray() override {}

  public:
    std::string GetTypeName() override final { return "Texture1DArray"; }

    virtual uint64_t  GetSize() = 0;
    virtual uint64_t  GetArraySize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1DArray"; }
  };
}
