#pragma once

#include <Render/Core/Adapter.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render::dx12
{
  class UAdapter : public IAdapter
  {
  public:
    UAdapter(IDXGIAdapter1* adapter) : m_adapter(adapter) {}
    ~UAdapter() override;
    UAdapter() = delete;

  public:
    NativeObject GetNativeObject() override { return m_adapter; }

    std::string GetName() override final;

    u32 GetVendorID() override final;
    u32 GetDeviceID() override final;
    u32 GetSubSysID() override final;
    u32 GetRevision() override final;

    u64 GetDedicatedVideoMemory()  override final;
    u64 GetDedicatedSystemMemory() override final;
    u64 GetSharedSystemMemory()    override final;

    FLuid GetAdapterLuid() override final;

  private:
    IDXGIAdapter1* m_adapter;
  };
}
