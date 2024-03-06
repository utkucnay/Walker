#pragma once

#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/ResourceBarrier.h>

namespace wkr::render::rsc::bar
{
  class AliasingBarrier : public ResourceBarrier
  {
  public:
    virtual ~AliasingBarrier() override {}
  };

  class AliasingBarrierBuilder : Builder<AliasingBarrier>
  {
  public:
    AliasingBarrierBuilder& SetResourceBefore(Resource* resource);
    AliasingBarrierBuilder& SetResourceAfter(Resource* resource);

  public:
    AliasingBarrier*             BuildRaw()    override final;
    mem::Ref<AliasingBarrier>    BuildRef()    override final;
    mem::Scope<AliasingBarrier>  BuildScope()  override final;

  public:
    Resource* resourceBefore;
    Resource* resourceAfter;
  };
}
