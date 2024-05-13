#pragma once

#include <Render/Core/Fence.h>
#include <Render/Core/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12Fence : public IFence
  {
  public:
    UDX12Fence(FenceBuilder& fb);
    ~UDX12Fence() override;

  public:
    void FenceEvent(int frameIndex) override final;
    void IncFenceValue(int frameIndex) { m_fenceValue[frameIndex]++; }

    NativeHandle GetNativeHandle(int frameIndex) override final { return m_fence[frameIndex]; }

  protected:
    void Clone(IFence& fence)     override final;

  private:
    static void CreateWithBuilder(UDX12Fence& fence, FenceBuilder& fb);

  public:
    std::vector<u64>  m_fenceValue;
    HANDLE            m_fenceEvent;

  private:
    IFence::Flag m_flag;
    std::vector<ID3D12Fence*> m_fence;
  };
}
