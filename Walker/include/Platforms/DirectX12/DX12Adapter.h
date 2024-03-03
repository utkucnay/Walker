#pragma once

#include <Render/Core/Adapter.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12Adapter : public Adapter
  {
  public:
    DX12Adapter(IDXGIAdapter1* adapter) : m_adapter(adapter) {}
    ~DX12Adapter() override;

  public:
    void* GetNativeHandle() override { return m_adapter; }

    mem::Scope<char> GetName() override final;

    uint32_t GetVendorID() override final;
    uint32_t GetDeviceID() override final;
    uint32_t GetSubSysID() override final;
    uint32_t GetRevision() override final;

    uint64_t GetDedicatedVideoMemory()  override final;
    uint64_t GetDedicatedSystemMemory() override final;
    uint64_t GetSharedSystemMemory()    override final;

    Luid GetAdapterLuid() override final;

  private:
    IDXGIAdapter1* m_adapter;

  public:
    static std::vector<mem::Ref<Adapter>> GetAllAdapters();
  };
}
