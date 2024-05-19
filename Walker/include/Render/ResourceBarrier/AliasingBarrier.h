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

  class AliasingBarrierBuilder : IBuilder<IAliasingBarrier>
  {
  public:
    AliasingBarrierBuilder(
        mem::WeakRef<IResource> beforeResource,
        mem::WeakRef<IResource> afterResource);

  public:
    [[nodiscard]] IAliasingBarrier*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<IAliasingBarrier>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<IAliasingBarrier>  BuildScope()  override final;

  public:
    mem::WeakRef<IResource> resourceBefore;
    mem::WeakRef<IResource> resourceAfter;
  };
}
