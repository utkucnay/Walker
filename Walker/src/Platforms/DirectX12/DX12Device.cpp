#include <Platforms/DirectX12/Core/DX12Device.h>

namespace wkr::render
{
  UDX12Device::UDX12Device(DeviceBuilder& db)
  {
    auto lAdapter = db.m_adapter.Lock();

    HRESULT hr = D3D12CreateDevice(
        lAdapter == NULL ? NULL : (IDXGIAdapter1*)lAdapter->GetNativeHandle(),
        D3D_FEATURE_LEVEL_12_2,
        IID_PPV_ARGS(&m_device));
    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Device");

  }

  UDX12Device::~UDX12Device()
  {
    m_device->Release();
  }
}
