#pragma once

#include <Render/Resource/Resource.h>

namespace wkr::render::rsc::bar
{
  class IResourceBarrier
  {
  public:
    virtual ~IResourceBarrier() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
  };

  using BarrierBuilder = IBuilder<IResourceBarrier>;
}
