#pragma once

#include "Graphics/Core/IDevice.h"

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
