#include "Platforms/DirectX12/Core/DX12Device.h"
#include "Core/Base.h"

namespace wkr::graphics::rhi::dx12 {

UDevice::UDevice(const FDeviceDesc& desc) {
  HRESULT hr =
      D3D12CreateDevice(SAFE_GET_NATIVE_OBJECT(desc.Adapter),
                        D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_Device));

  if (FAILED(hr)) {
    WKR_CORE_WARNING("Didn't Create DX12 Device");
    WKR_DX12_ERROR(hr);
  }

  m_Adapter = desc.Adapter;

  WKR_DX12_DEBUG_SET_DEVICE(m_Device);
  WKR_CORE_LOG("DX12 Device Created");
}

FDeviceDesc UDevice::GetDesc() {
  FDeviceDesc desc = {.Adapter = m_Adapter};
  return desc;
}

UDevice::~UDevice() {
  m_Device->Release();
}

}  // namespace wkr::graphics::rhi::dx12
