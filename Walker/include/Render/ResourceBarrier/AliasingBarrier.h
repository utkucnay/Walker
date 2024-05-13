#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class IAliasingBarrier : public IResourceBarrier
  {
  public:
    virtual ~IAliasingBarrier() override {}
  };

  class AliasingBarrierBuilder : public BarrierBuilder
  {
  public:
    AliasingBarrierBuilder(
        mem::WeakRef<IResource> beforeResource,
        mem::WeakRef<IResource> afterResource);

  public:
    [[nodiscard]] IResourceBarrier*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<IResourceBarrier>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<IResourceBarrier>  BuildScope()  override final;

  public:
    mem::WeakRef<IResource> resourceBefore;
    mem::WeakRef<IResource> resourceAfter;
  };
}
