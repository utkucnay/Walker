#pragma once

#include <Platforms/DirectX12/DX12Fence.h>

namespace wkr::render
{
  DX12Fence::DX12Fence(
      mem::Ref<Device> device,
      Fence::Flag fenceFlag)
  {
    ID3D12Device* nDevice = (ID3D12Device*)device->GetNativeHandle();

    HRESULT hr = nDevice->CreateFence(
        0,
        static_cast<D3D12_FENCE_FLAGS>(fenceFlag),
        IID_PPV_ARGS(&fence));

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create Fence");
  }

  DX12Fence::~DX12Fence()
  {
    fence->Release();
  }
}
