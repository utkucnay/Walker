#pragma once

#include <Platforms/DirectX12/DX12.h>

#include <Render/Device.h>
#include <Render/Command.h>
#include <Render/Adapter.h>

namespace wkr::render
{
  struct DX12DeviceSpec
  {
    int t;
  };

  class DX12Device : public Device
  {
  public:
    DX12Device(DX12DeviceSpec spec);
    DX12Device(Ref<Adapter> adapter, DX12DeviceSpec spec);
    ~DX12Device();

  public:
    Ref<CommandQueue> CreateCommandQueue(CommandQueueDesc& desc) override;
    Ref<CommandAllocator> CreateCommandAllocator() override;
    Ref<CommandList> CreateCommandList() override;

    Ref<DescriptorHeap> CreateDescriptorHeap() override;
    Ref<RenderTargetView> CreateRenderTargetView() override;
    Ref<RootSignature> CreateRootSignature() override;

    Ref<Fence> CreateFence() override;

    void* GetNativeHandle() override { return device; }

  private:
    void CreateDevice(Ref<Adapter> adapter, DX12DeviceSpec spec);

  private:
    ID3D12Device* device;
  };
}
