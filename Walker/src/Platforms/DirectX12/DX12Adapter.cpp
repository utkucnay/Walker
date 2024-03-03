#include <Platforms/DirectX12/DX12Adapter.h>
#include <Platforms/DirectX12/DX12Factory.h>
#include <cstdint>
#include <wchar.h>

namespace wkr::render
{
  DX12Adapter::~DX12Adapter()
  {
    m_adapter->Release();
  }

  std::vector<mem::Ref<Adapter>> DX12Adapter::GetAllAdapters()
  {
    std::vector<mem::Ref<Adapter>> ret;
    IDXGIAdapter1* nAdapter;
    int adapterIndex = 0;

    while(DX12Factory::GetFactory()->EnumAdapters1(
          adapterIndex,
          &nAdapter) != DXGI_ERROR_NOT_FOUND)
    {
      mem::Ref<DX12Adapter> adapter = mem::Ref<DX12Adapter>::Create(nAdapter);
      ret.push_back(adapter);
      adapterIndex++;
    }
    return ret;
  }

  mem::Scope<char> DX12Adapter::GetName()
  {
    auto ret = mem::Scope<char>::Create(128);
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    wcstombs_s(NULL, ret.Get(), 128, desc.Description, 128);
    return ret;
  }

  uint32_t DX12Adapter::GetVendorID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.VendorId;
  }

  uint32_t DX12Adapter::GetDeviceID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DeviceId;
  }

  uint32_t DX12Adapter::GetSubSysID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SubSysId;
  }

  uint32_t DX12Adapter::GetRevision()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.Revision;
  }

  uint64_t DX12Adapter::GetDedicatedVideoMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedVideoMemory;
  }

  uint64_t DX12Adapter::GetDedicatedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedSystemMemory;
  }

  uint64_t DX12Adapter::GetSharedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SharedSystemMemory;
  }

  Luid DX12Adapter::GetAdapterLuid()
  {
    DXGI_ADAPTER_DESC desc;
    Luid ret;

    m_adapter->GetDesc(&desc);
    ret.lowPart = desc.AdapterLuid.LowPart;
    ret.highPart = desc.AdapterLuid.HighPart;
    return ret;
  }
}
