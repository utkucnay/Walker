#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class Resource;

  class Texture : public Resource
  {
  public:
    enum class Layout
    {
      Unknown               = 0,
      RowMajor              = 1,
      UndefinedSwizzle64KB  = 2,
      StandardSwizzle64KB   = 3,
    };

  public:
    virtual ~Texture() override {}
  };
}
