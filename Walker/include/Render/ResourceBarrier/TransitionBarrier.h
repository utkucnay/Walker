#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class ITransitionBarrier : public IResourceBarrier
  {
  public:
    virtual ~ITransitionBarrier() override {}
  };

  class TransitionBarrierBuilder : IBuilder<ITransitionBarrier>
  {
  public:
    TransitionBarrierBuilder(mem::WeakRef<IResource> resource);

  public:
    TransitionBarrierBuilder& SetBeforeState(IResource::State beforeState);
    TransitionBarrierBuilder& SetAfterState(IResource::State afterState);

  public:
    [[nodiscard]] ITransitionBarrier*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<ITransitionBarrier>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<ITransitionBarrier>  BuildScope()  override final;

  public:
    mem::WeakRef<IResource> m_resource;

    IResource::State m_beforeState;
    IResource::State m_afterState;
  };
}
