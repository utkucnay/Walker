#include <Platforms/DirectX12/Core/DX12Device.h>

namespace wkr::render
{
  DX12Device::DX12Device()
  {
    HRESULT hr = D3D12CreateDevice(
        NULL,
        D3D_FEATURE_LEVEL_12_1,
        IID_PPV_ARGS(&device));
    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Device");
  }

  DX12Device::DX12Device(mem::Visitor<Adapter> adapter)
  {
    HRESULT hr = D3D12CreateDevice(
        (IDXGIAdapter1*)adapter->GetNativeHandle(),
        D3D_FEATURE_LEVEL_12_2,
        IID_PPV_ARGS(&device));
    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Device");
  }

  DX12Device::~DX12Device()
  {
    device->Release();
  }
}
