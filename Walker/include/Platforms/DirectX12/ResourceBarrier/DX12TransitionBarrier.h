#pragma once

#include "Graphics/ResourceBarrier/ITransitionBarrier.h"

namespace wkr::render::dx12
{
  class UTransitionBarrier : public ITransitionBarrier
  {
  public:
    UTransitionBarrier(FTransitionBarrierDesc& desc);
    ~UTransitionBarrier();

  public:
    NativeObject GetNativeObject() override final { return &m_resourceBarrier; }

  private:
    D3D12_RESOURCE_BARRIER m_resourceBarrier;
  };
}
