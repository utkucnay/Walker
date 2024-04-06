#pragma once

#include <Render/Core/Fence.h>
#include <Render/Core/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12Fence : public Fence
  {
  public:
    DX12Fence(FenceBuilder* fb);
    ~DX12Fence() override;

  public:
    void FenceEvent(int frameIndex) override final;
    void* GetNativeHandle(int frameIndex) override final { return m_fence[frameIndex]; }
    void IncFenceValue(int frameIndex) { m_fenceValue[frameIndex]++; }

  public:
    std::vector<uint64_t> m_fenceValue;
    HANDLE        m_fenceEvent;

  private:
    std::vector<ID3D12Fence*> m_fence;
  };
}
