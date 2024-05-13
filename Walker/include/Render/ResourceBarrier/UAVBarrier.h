#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class IUAVBarrier : public IResourceBarrier
  {
  public:
    virtual ~IUAVBarrier() {}
  };

  class UAVBarrierBuilder : IBuilder<IUAVBarrier>
  {
  public:
    UAVBarrierBuilder(mem::WeakRef<IResource> resource);

  public:
    [[nodiscard]] IUAVBarrier*             BuildRaw()    override final;
    [[nodiscard]] mem::Ref<IUAVBarrier>    BuildRef()    override final;
    [[nodiscard]] mem::Scope<IUAVBarrier>  BuildScope()  override final;

  public:
    mem::WeakRef<IResource> m_resource;
  };
}
