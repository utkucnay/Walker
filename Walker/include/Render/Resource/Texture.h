#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render
{
  class ITexture : public IResource
  {
  public:
    virtual ~ITexture() override = default;
  };
}
