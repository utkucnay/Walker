#pragma once

#include <Render/Core/Device.h>
#include <Render/Core/Adapter.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12Device : public Device
  {
  public:
    DX12Device();
    DX12Device(mem::Visitor<Adapter> adapter);
    ~DX12Device() override;

  public:
    void* GetNativeHandle() override { return device; }

  private:
    ID3D12Device* device;
  };
}
