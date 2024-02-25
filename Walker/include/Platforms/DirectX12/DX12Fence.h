#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Fence.h>
#include <Render/Device.h>

namespace wkr::render
{
  class DX12Fence : public Fence
  {
  public:
    DX12Fence(mem::Ref<Device> device, Fence::Flag fenceFlag);
    ~DX12Fence() override;

  public:
    void* GetNativeHandle() override { return fence; }

  private:
    ID3D12Fence* fence;
  };
}
