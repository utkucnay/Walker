#pragma once

#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render
{
  struct FTransitionBarrierDesc
  {
    IResourceHandle m_resource;

    EResourceState m_beforeState;
    EResourceState m_afterState;
  };

  class ITransitionBarrier : public IResourceBarrier
  {
  public:
    virtual ~ITransitionBarrier() override = default;
  };

  using ITransitionBarrierHandle = mem::TRef<ITransitionBarrier>;
}
