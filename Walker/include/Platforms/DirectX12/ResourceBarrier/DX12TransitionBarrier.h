#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceBarrier/TransitionBarrier.h>

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
