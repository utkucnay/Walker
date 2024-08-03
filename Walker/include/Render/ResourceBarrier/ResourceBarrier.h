#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render
{
  class IResourceBarrier
  {
  public:
    virtual ~IResourceBarrier() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
  };

  using IResourceBarrierHandle = mem::TRef<IResourceBarrier>;
}
