#include "Platforms/DirectX12/Core/DX12Device.h"

namespace wkr::graphics::rhi::dx12 {

UDevice::UDevice(const FDeviceDesc& desc) {
  HRESULT hr =
      D3D12CreateDevice(SAFE_GET_NATIVE_OBJECT(desc.Adapter),
                        D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_Device));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Device");
  m_Adapter = desc.Adapter;
}

FDeviceDesc UDevice::GetDesc() {
  FDeviceDesc desc = {.Adapter = m_Adapter};
  return desc;
}

UDevice::~UDevice() {
  m_Device->Release();
}

}  // namespace wkr::graphics::rhi::dx12
