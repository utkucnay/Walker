#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/ResourceBarrier/TransitionBarrier.h>

namespace wkr::render::rsc::bar
{
  class DX12TransitionBarrier : public TransitionBarrier
  {
  public:
    DX12TransitionBarrier(TransitionBarrierBuilder* tbb);
    ~DX12TransitionBarrier();

  public:
    void* GetNativeHandle() override final { return &m_resourceBarrier; }

  private:
    D3D12_RESOURCE_BARRIER m_resourceBarrier{};
  };
}
