#pragma once

#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render
{
  struct AliasingBarrierDesc
  {
    IResourceHandle resourceBefore;
    IResourceHandle resourceAfter;
  };

  class IAliasingBarrier : IResourceBarrier
  {
  public:
    virtual ~IAliasingBarrier() override = default;
  };

  using IAliasingBarrierHandle = mem::TRef<IAliasingBarrier>;
}
