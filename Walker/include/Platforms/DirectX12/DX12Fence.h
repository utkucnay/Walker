#pragma once

#include <Platforms/DirectX12/DX12.h>
#include <Render/Fence.h>
#include <Render/Device.h>

namespace wkr::render
{
  class DX12Fence : public Fence
  {
  public:
    DX12Fence(Ref<Device> device, FenceFlag fenceFlag);
    ~DX12Fence();

  public:
    void* GetNativeHandle() override { return fence; }

  private:
    ID3D12Fence* fence;
  };
}
