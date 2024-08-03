#include <Platforms/DirectX12/Core/DX12Device.h>

namespace wkr::render::dx12
{
  UDevice::UDevice(FDeviceDesc& desc)
  {
  }

  UDevice::~UDevice()
  {
    m_device->Release();
  }
}
