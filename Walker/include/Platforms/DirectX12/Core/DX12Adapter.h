#pragma once

#include <Render/Core/Adapter.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12Adapter : public IAdapter
  {
  public:
    UDX12Adapter(IDXGIAdapter1* adapter) : m_adapter(adapter) {}
    ~UDX12Adapter() override;

  private:
    UDX12Adapter() {}

  public:
    NativeHandle GetNativeHandle() override { return m_adapter; }

    mem::Scope<char> GetName() override final;

    u32 GetVendorID() override final;
    u32 GetDeviceID() override final;
    u32 GetSubSysID() override final;
    u32 GetRevision() override final;

    u64 GetDedicatedVideoMemory()  override final;
    u64 GetDedicatedSystemMemory() override final;
    u64 GetSharedSystemMemory()    override final;

    Luid GetAdapterLuid() override final;

    void Clone(IAdapter& adapter) override final;

  private:
    IDXGIAdapter1* m_adapter;

  public:
    static std::vector<mem::Ref<IAdapter>> GetAllAdapters();
  };
}
