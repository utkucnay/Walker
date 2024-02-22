#include <Platforms/DirectX12/DX12Adapter.h>
#include <Platforms/DirectX12/DX12Factory.h>

namespace wkr::render
{
  DX12Adapter::~DX12Adapter()
  {
    adapter->Release();
  }

  std::vector<Ref<Adapter>> DX12Adapter::GetAllAdapters()
  {
    std::vector<Ref<Adapter>> ret;

    IDXGIAdapter1* adapter;
    int adapterIndex = 0;
    while(DX12Factory::GetFactory()->EnumAdapters1(
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
      //Note(utku): check buffer count
      wcstombs_s(NULL, desc.description, 128, tmpDesc.Description, 128);

      Ref<DX12Adapter> dadapter = Ref<DX12Adapter>::Create(adapter);
      dadapter->desc = desc;

      ret.push_back(dadapter);

      adapterIndex++;
    }

    adapter = nullptr;
    return ret;
  }
}
