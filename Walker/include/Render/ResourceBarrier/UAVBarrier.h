#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class UAVBarrier : public ResourceBarrier
  {
  public:
    virtual ~UAVBarrier() {}
  };

  class UAVBarrierBuilder : Builder<UAVBarrier>
  {
  public:
    UAVBarrierBuilder& SetResource(Resource* resource);

  public:
    UAVBarrier*             BuildRaw()    override final;
    mem::Ref<UAVBarrier>    BuildRef()    override final;
    mem::Scope<UAVBarrier>  BuildScope()  override final;

  public:
    Resource* m_resource;
  };
}
