#pragma once

#include "Graphics/RHI/Core/IDevice.h"

namespace wkr::graphics::rhi::dx12 {

class UDevice : public IDevice {
 public:
  explicit UDevice(const FDeviceDesc& db);
  ~UDevice() override;

 public:
  FDeviceDesc GetDesc() override;
  NativeObject GetNativeObject() override { return m_Device; }
  void CheckDevice() override final
  {
    HRESULT hr = m_Device->GetDeviceRemovedReason();

    if (FAILED(hr))
    {
        WKR_CORE_WARNING( << std::to_string((u32)hr));
    }
  }

 private:
  ID3D12Device* m_Device;
  IAdapter* m_Adapter;
};

}  // namespace wkr::graphics::rhi
