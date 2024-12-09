#include "Platforms/DirectX12/Core/DX12Adapter.h"

namespace wkr::graphics::rhi::dx12 {

UAdapter::~UAdapter() {
  m_adapter->Release();
}

FAdapterDesc UAdapter::GetDesc() {
  DXGI_ADAPTER_DESC nAdapterDesc;
  m_adapter->GetDesc(&nAdapterDesc);

  char* name = new char[128];
  wcstombs_s(NULL, name, 128, nAdapterDesc.Description, 128);

  FAdapterDesc adapterDesc = {
      .Name = name,
      .VendorID = nAdapterDesc.VendorId,
      .DeviveID = nAdapterDesc.DeviceId,
      .SubSysID = nAdapterDesc.SubSysId,
      .Revision = nAdapterDesc.Revision,
      .AdapterLuid = {.LowPart = nAdapterDesc.AdapterLuid.LowPart,
                      .HighPart = nAdapterDesc.AdapterLuid.HighPart},
      .DedicatedVideoMemory = nAdapterDesc.DedicatedVideoMemory,
      .DedicatedSystemMemory = nAdapterDesc.DedicatedSystemMemory,
      .SharedSystemMemory = nAdapterDesc.SharedSystemMemory,
  };

  return adapterDesc;
}

}  // namespace wkr::graphics::rhi::dx12
