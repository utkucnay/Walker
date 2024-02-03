#pragma once

#include <Render/Adapter.h>
#include <dxgi.h>
#include <dxgi1_6.h>

namespace wkr::render
{
  class DX12Adapter : public Adapter
  {
  public:
    DX12Adapter(IDXGIAdapter1* adapter) : adapter(adapter) {}
    ~DX12Adapter();

  public:
    void* GetNativeHandle() override { return adapter; }

  private:
    IDXGIAdapter1* adapter;
  };
}
