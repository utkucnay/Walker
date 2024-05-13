#include "Render/Core/RendererAPI.h"
#include <Render/ResourceBarrier/TransitionBarrier.h>

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

  IResourceBarrier* TransitionBarrierBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetResourceBarrierTransition()
      ->CreateRaw(*this);
  }

  mem::Ref<IResourceBarrier> TransitionBarrierBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetResourceBarrierTransition()
      ->CreateRef(*this);
  }

  mem::Scope<IResourceBarrier> TransitionBarrierBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetResourceBarrierTransition()
      ->CreateScope(*this);
  }
}
