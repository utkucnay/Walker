#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class TransitionBarrier : public ResourceBarrier
  {
  public:
    virtual ~TransitionBarrier() override {}
  };

  class TransitionBarrierBuilder : Builder<TransitionBarrier>
  {
  public:
    TransitionBarrierBuilder& SetResource(Resource* resource);
    TransitionBarrierBuilder& SetBeforeState(Resource::State beforeState);
    TransitionBarrierBuilder& SetAfterState(Resource::State afterState);

  public:
    TransitionBarrier*             BuildRaw()    override final;
    mem::Ref<TransitionBarrier>    BuildRef()    override final;
    mem::Scope<TransitionBarrier>  BuildScope()  override final;

    TransitionBarrierBuilder* operator->()
    {
      return this;
    }

  public:
    Resource*       m_resource;
    Resource::State m_beforeState;
    Resource::State m_afterState;
  };
}
