#include <Platforms/DirectX12/DX12Adapter.h>
#include <Platforms/DirectX12/DX12Factory.h>

namespace wkr::render
{
  DX12Adapter::~DX12Adapter()
  {
    adapter->Release();
  }

  std::vector<Ref<Adapter>> Adapter::GetAllAdapters()
  {
    std::vector<Ref<Adapter>> ret;

    IDXGIAdapter1* adapter;
    int adapterIndex = 0;
    while(g_dxgiFactory->EnumAdapters1(
          adapterIndex,
          &adapter) != DXGI_ERROR_NOT_FOUND)
    {
      DXGI_ADAPTER_DESC1 tmpDesc;
      adapter->GetDesc1(&tmpDesc);

      AdapterDesc desc;
      desc.flags = tmpDesc.Flags;
      desc.deviceID = tmpDesc.DeviceId;
      desc.revision = tmpDesc.Revision;
      desc.subSysID = tmpDesc.SubSysId;
      desc.vendorId = tmpDesc.VendorId;
      desc.sharedSystemMemory = tmpDesc.SharedSystemMemory;
      desc.dedicatedVideoMemory = tmpDesc.DedicatedVideoMemory;
      desc.dedicatedSystemMemory = tmpDesc.DedicatedSystemMemory;
      wcstombs_s(NULL, desc.description, 128, tmpDesc.Description, 127);

      Ref<DX12Adapter> dadapter = CreateRef<DX12Adapter>(adapter);
      dadapter->desc = desc;

      ret.push_back(dadapter);

      adapterIndex++;
    }

    adapter = nullptr;
    return ret;
  }
}