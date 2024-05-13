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

  class TransitionBarrierBuilder : public BarrierBuilder
  {
  public:
    TransitionBarrierBuilder(mem::WeakRef<IResource> resource);

  public:
    TransitionBarrierBuilder& SetBeforeState(IResource::State beforeState);
    TransitionBarrierBuilder& SetAfterState(IResource::State afterState);

  public:
    [[nodiscard]] IResourceBarrier*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<IResourceBarrier>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<IResourceBarrier>  BuildScope()  override final;

  public:
    mem::WeakRef<IResource> m_resource;

    IResource::State m_beforeState;
    IResource::State m_afterState;
  };
}
