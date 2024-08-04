#include <Platforms/DirectX12/Core/DX12Device.h>

namespace wkr::render::dx12
{
  UDevice::UDevice(FDeviceDesc& desc)
  {
    HRESULT hr = D3D12CreateDevice(
        SAFE_GET_NATIVE_OBJECT(desc.adapter),
        D3D_FEATURE_LEVEL_12_0,
        IID_PPV_ARGS(&m_device));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Device");
  }

  UDevice::~UDevice()
  {
    m_device->Release();
  }
}
