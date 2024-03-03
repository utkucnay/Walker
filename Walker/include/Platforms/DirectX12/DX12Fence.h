#pragma once

#include <Render/Core/Fence.h>
#include <Render/Core/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12Fence : public Fence
  {
  public:
    DX12Fence(mem::Visitor<Device> device,
        mem::Visitor<FenceBuilder> fb);
    ~DX12Fence() override;

  public:
    void FenceEvent() override final;
    void* GetNativeHandle() override final { return m_fence; }

  private:
    ID3D12Fence*  m_fence;
    uint64_t      m_fenceValue;
    HANDLE        m_fenceEvent;
  };
}
