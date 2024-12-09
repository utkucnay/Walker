#pragma once

#include "Graphics/RHI/Core/IDevice.h"

namespace wkr::graphics::rhi::dx12 {

class UDevice : public IDevice {
 public:
  UDevice(FDeviceDesc& db);
  ~UDevice() override;

 public:
  FDeviceDesc GetDesc() override;
  NativeObject GetNativeObject() override { return m_Device; }

 private:
  ID3D12Device* m_Device;
  IAdapter* m_Adapter;
};

}  // namespace wkr::graphics::rhi
