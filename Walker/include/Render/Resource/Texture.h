#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc
{
  class ITexture : public IResource
  {
  public:
    virtual ~ITexture() override {}
  };
}
