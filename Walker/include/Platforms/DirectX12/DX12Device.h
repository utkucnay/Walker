#pragma once

#include <Render/Device.h>
#include <Render/Adapter.h>

namespace wkr::render
{
  class DX12Device : public Device
  {
  public:
    DX12Device();
    DX12Device(mem::Ref<Adapter> adapter);
    ~DX12Device() override;

  public:
    mem::Ref<CommandQueue> CreateCommandQueue(CommandQueueDesc& desc) override;
    mem::Ref<CommandAllocator> CreateCommandAllocator() override;
    mem::Ref<CommandList> CreateCommandList() override;

    mem::Ref<DescriptorHeap> CreateDescriptorHeap() override;
    mem::Ref<RenderTargetView> CreateRenderTargetView() override;
    mem::Ref<RootSignature> CreateRootSignature() override;

    mem::Ref<Fence> CreateFence() override;

    void* GetNativeHandle() override { return device; }

  private:
    void CreateDevice(mem::Ref<Adapter> adapter);

  private:
    ID3D12Device* device;
  };
}
