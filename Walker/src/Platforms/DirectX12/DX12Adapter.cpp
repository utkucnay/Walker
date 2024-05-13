#include <Platforms/DirectX12/Core/DX12Adapter.h>

namespace wkr::render
{
  UDX12Adapter::~UDX12Adapter()
  {
  }

  std::vector<mem::Ref<IAdapter>> UDX12Adapter::GetAllAdapters()
  {
    std::vector<mem::Ref<IAdapter>> ret;
    IDXGIAdapter1* nAdapter;
    int adapterIndex = 0;

    while(UDX12Factory::GetFactory()->EnumAdapters1(
          adapterIndex,
          &nAdapter) != DXGI_ERROR_NOT_FOUND)
    {
      mem::Ref<UDX12Adapter> adapter = mem::Ref<UDX12Adapter>::Create(nAdapter);
      ret.push_back(adapter);
      adapterIndex++;
    }
    return ret;
  }

  mem::Scope<char> UDX12Adapter::GetName()
  {
    auto ret = mem::Scope<char>::Create(128);
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    wcstombs_s(NULL, ret.GetPtr(), 128, desc.Description, 128);
    return ret;
  }

  u32 UDX12Adapter::GetVendorID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.VendorId;
  }

  u32 UDX12Adapter::GetDeviceID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DeviceId;
  }

  u32 UDX12Adapter::GetSubSysID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SubSysId;
  }

  u32 UDX12Adapter::GetRevision()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.Revision;
  }

  u64 UDX12Adapter::GetDedicatedVideoMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedVideoMemory;
  }

  u64 UDX12Adapter::GetDedicatedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedSystemMemory;
  }

  u64 UDX12Adapter::GetSharedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SharedSystemMemory;
  }

  Luid UDX12Adapter::GetAdapterLuid()
  {
    DXGI_ADAPTER_DESC desc;
    Luid ret;

    m_adapter->GetDesc(&desc);
    ret.lowPart = desc.AdapterLuid.LowPart;
    ret.highPart = desc.AdapterLuid.HighPart;
    return ret;
  }

  void UDX12Adapter::Clone(IAdapter& adapter)
  {
    static_cast<UDX12Adapter&>(adapter).m_adapter = this->m_adapter;
  }
}
