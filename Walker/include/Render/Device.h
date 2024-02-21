#pragma once

#include <Render/Command.h>

#include <Render/RenderTargetView.h>
#include <Render/DescriptorHeap.h>
#include <Render/RootSignature.h>

#include <Render/Fence.h>

namespace wkr::render
{
  class CommandQueue;
  class CommandAllocator;
  class CommandList;
  struct CommandQueueDesc;

  class Fence;

  class Device
  {
  public:
    virtual void* GetNativeHandle() = 0;

    virtual Ref<CommandQueue> CreateCommandQueue(CommandQueueDesc& desc) = 0;
    virtual Ref<CommandAllocator> CreateCommandAllocator() = 0;
    virtual Ref<CommandList> CreateCommandList() = 0;

    virtual Ref<DescriptorHeap> CreateDescriptorHeap() = 0;
    virtual Ref<RenderTargetView> CreateRenderTargetView() = 0;

    virtual Ref<RootSignature> CreateRootSignature() = 0;

    virtual Ref<Fence> CreateFence() = 0;

  public:
    Ref<Device> GetDefault();
  };
}
