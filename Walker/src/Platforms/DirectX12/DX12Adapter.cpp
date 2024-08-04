#include <Platforms/DirectX12/Core/DX12Adapter.h>

namespace wkr::render::dx12
{
  UAdapter::~UAdapter()
  {
    m_adapter->Release();
  }

  std::string UAdapter::GetName()
  {
    auto ret = mem::TScope<char>::Create(128);
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    wcstombs_s(NULL, ret.GetPtr(), 128, desc.Description, 128);
    return std::string(ret.GetPtr(), 128);
  }

  u32 UAdapter::GetVendorID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.VendorId;
  }

  u32 UAdapter::GetDeviceID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DeviceId;
  }

  u32 UAdapter::GetSubSysID()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SubSysId;
  }

  u32 UAdapter::GetRevision()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.Revision;
  }

  u64 UAdapter::GetDedicatedVideoMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedVideoMemory;
  }

  u64 UAdapter::GetDedicatedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.DedicatedSystemMemory;
  }

  u64 UAdapter::GetSharedSystemMemory()
  {
    DXGI_ADAPTER_DESC desc;

    m_adapter->GetDesc(&desc);
    return desc.SharedSystemMemory;
  }

  FLuid UAdapter::GetAdapterLuid()
  {
    DXGI_ADAPTER_DESC desc;
    FLuid ret;

    m_adapter->GetDesc(&desc);
    ret.lowPart = desc.AdapterLuid.LowPart;
    ret.highPart = desc.AdapterLuid.HighPart;
    return ret;
  }
}
