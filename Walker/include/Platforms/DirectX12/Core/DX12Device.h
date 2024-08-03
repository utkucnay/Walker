#pragma once

#include <Render/Core/Device.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UDevice : public IDevice
  {
  public:
    UDevice(FDeviceDesc& db);
    ~UDevice() override;

  public:
    NativeObject GetNativeObject() override { return m_device; }

  private:
    ID3D12Device* m_device;
  };
}
