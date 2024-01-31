#pragma once

#include <Render/Adapter.h>
#include <Render/Device.h>

namespace wkr::render
{
  class DX12Device : public Device
  {
  public:
    DX12Device(const AdapterDesc& desc);
    ~DX12Device();

  public:
    Ref<CommandQueue> CreateCommandQueue();
    Ref<CommandAllocator> CreateCommandAllocator();
    Ref<CommandList> CreateCommandList();

    Ref<DescriptorHeap> CreateDescriptorHeap();
    Ref<RenderTargetView> CreateRenderTargetView();
    Ref<RootSignature> CreateRootSignature();

    Ref<Fence> CreateFence();
  };
}
