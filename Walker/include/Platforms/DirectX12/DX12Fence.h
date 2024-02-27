#pragma once

#include <Render/Fence.h>
#include <Render/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12Fence : public Fence
  {
  public:
    DX12Fence(mem::Ref<Device> device, Fence::Flag fenceFlag);
    ~DX12Fence() override;

  public:
    void FenceEvent() override;
    void* GetNativeHandle() override { return m_fence; }

  private:
    ID3D12Fence* m_fence;
    uint64_t m_fenceValue;
    HANDLE m_fenceEvent;
  };
}
