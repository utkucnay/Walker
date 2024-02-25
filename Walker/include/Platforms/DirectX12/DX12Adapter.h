#pragma once

#include <Platforms/DirectX12/DX12.h>

#include <Render/Adapter.h>

namespace wkr::render
{
  class DX12Adapter : public Adapter
  {
  public:
    DX12Adapter(IDXGIAdapter1* adapter) : adapter(adapter) {}
    ~DX12Adapter() override;

  public:
    void* GetNativeHandle() override { return adapter; }

  private:
    IDXGIAdapter1* adapter;

  public:
    static std::vector<mem::Ref<Adapter>> GetAllAdapters();
  };
}
