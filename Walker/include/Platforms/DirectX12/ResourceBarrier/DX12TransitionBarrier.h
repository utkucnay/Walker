#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceBarrier/TransitionBarrier.h>

namespace wkr::render::rsc::bar
{
  class UDX12TransitionBarrier : public ITransitionBarrier
  {
  public:
    UDX12TransitionBarrier(TransitionBarrierBuilder& tbb);
    ~UDX12TransitionBarrier();

  public:
    NativeHandle GetNativeHandle() override final { return &m_resourceBarrier; }

  private:
    D3D12_RESOURCE_BARRIER m_resourceBarrier{};
  };
}
