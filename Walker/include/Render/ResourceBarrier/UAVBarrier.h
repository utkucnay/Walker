#pragma once

#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render
{
  struct UAVBarrierDesc
  {
    IResourceHandle resource;
  };

  class IUAVBarrier : public IResourceBarrier
  {
  public:
    virtual ~IUAVBarrier() = default;
  };

  using IUAVBarrierHandle = mem::TRef<IUAVBarrier>;
}
