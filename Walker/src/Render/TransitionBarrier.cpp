#include <Render/ResourceBarrier/TransitionBarrier.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render::rsc::bar
{
  TransitionBarrierBuilder::TransitionBarrierBuilder(
      mem::WeakRef<IResource> resource)
  {
    m_resource = resource;
  }

  TransitionBarrierBuilder& TransitionBarrierBuilder::SetBeforeState(
      IResource::State beforeState)
  {
    m_beforeState = beforeState;
    return *this;
  }

  TransitionBarrierBuilder& TransitionBarrierBuilder::SetAfterState(
      IResource::State afterState)
  {
    m_afterState = afterState;
    return *this;
  }

  REGISTER_BUILDER(I, TransitionBarrier);
}
