#include "Render/Core/RendererAPI.h"
#include <Render/ResourceBarrier/TransitionBarrier.h>

namespace wkr::render::rsc::bar
{
  TransitionBarrierBuilder& TransitionBarrierBuilder::SetResource(Resource* resource)
  {
    m_resource = resource;
    return *this;
  }

  TransitionBarrierBuilder& TransitionBarrierBuilder::SetBeforeState(
      Resource::State beforeState)
  {
    m_beforeState = beforeState;
    return *this;
  }

  TransitionBarrierBuilder& TransitionBarrierBuilder::SetAfterState(
      Resource::State afterState)
  {
    m_afterState = afterState;
    return *this;
  }

  TransitionBarrier* TransitionBarrierBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory()->GetResourceBarrierTransition()
      ->CreateFactoryRaw(this);
  }

  mem::Ref<TransitionBarrier> TransitionBarrierBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory()->GetResourceBarrierTransition()
      ->CreateFactoryRef(this);
  }

  mem::Scope<TransitionBarrier> TransitionBarrierBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory()->GetResourceBarrierTransition()
      ->CreateFactoryScope(this);
  }
}
