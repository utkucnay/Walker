#pragma once

#include <Render/Device.h>
#include <Render/Adapter.h>
#include <d3d12.h>


namespace wkr::render
{
  class DX12Device : public Device
  {
  public:
    DX12Device();
    DX12Device(Ref<Adapter> adapter);
    ~DX12Device();

  public:
    Ref<CommandQueue> CreateCommandQueue();
    Ref<CommandAllocator> CreateCommandAllocator();
    Ref<CommandList> CreateCommandList();

    Ref<DescriptorHeap> CreateDescriptorHeap();
    Ref<RenderTargetView> CreateRenderTargetView();
    Ref<RootSignature> CreateRootSignature();

    Ref<Fence> CreateFence();

  private:
    bool CreateDevice(Ref<Adapter> adapter);

  private:
    ID3D12Device* device;
  };
}
