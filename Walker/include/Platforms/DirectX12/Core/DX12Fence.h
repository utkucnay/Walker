#pragma once

#include <Render/Core/Fence.h>
#include <Render/Core/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UFence : public IFence
  {
  public:
    UFence(FFenceDesc& desc);
    ~UFence() override;

  public:
    void FenceEvent(int frameIndex) override final;
    void IncFenceValue(int frameIndex) { m_fenceValue[frameIndex]++; }

    NativeObject GetNativeObject(int frameIndex) override final { return m_fence[frameIndex]; }

  public:
    std::vector<u64>  m_fenceValue;
    HANDLE            m_fenceEvent;

  private:
    EFenceFlag m_flag;
    std::vector<ID3D12Fence*> m_fence;
  };
}
