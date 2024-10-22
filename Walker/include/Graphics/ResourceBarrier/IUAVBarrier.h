#pragma once

#include "Graphics/Resource/IResource.h"
#include "Graphics/ResourceBarrier/IResourceBarrier.h"

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
