#pragma once

#include <Render/Core/Device.h>
#include <Render/Core/Adapter.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12Device : public IDevice
  {
  public:
    UDX12Device(DeviceBuilder& db);
    ~UDX12Device() override;

  public:
    NativeHandle GetNativeHandle() override { return m_device; }

  private:
    ID3D12Device* m_device;
  };
}
