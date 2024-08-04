#pragma once

#include <Render/Resource/Texture.h>

namespace wkr::render
{
  class ITexture1DArray : public ITexture
  {
  public:
    virtual ~ITexture1DArray() override = default;

  public:
    std::string GetTypeName() override final { return "Texture1DArray"; }

    virtual uint64_t  GetSize() = 0;
    virtual uint64_t  GetArraySize() = 0;

  public:
    static std::string GetStaticTypeName() { return "Texture1DArray"; }
  };

  using ITexture1DArrayHandle = mem::TRef<ITexture1DArray>;
}
