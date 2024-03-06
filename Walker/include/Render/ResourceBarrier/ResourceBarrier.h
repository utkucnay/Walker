#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc::bar
{
  class ResourceBarrier
  {
  public:
    virtual ~ResourceBarrier() {}

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
