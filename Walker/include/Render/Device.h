#pragma once

#include "Render/Adapter.h"
#include <Render/CommandList.h>
#include <Render/CommandQueue.h>
#include <Render/CommandAllocator.h>

#include <Render/RenderTargetView.h>
#include <Render/DescriptorHeap.h>
#include <Render/RootSignature.h>

#include <Render/Fence.h>

namespace wkr::render
{
  class Device
  {
  public:
    Device(const AdapterDesc& desc);
    ~Device();

  public:
    virtual Ref<Device> GetDefaultDevice() = 0;

  public:
    virtual Ref<CommandQueue> CreateCommandQueue() = 0;
    virtual Ref<CommandAllocator> CreateCommandAllocator() = 0;
    virtual Ref<CommandList> CreateCommandList() = 0;

    virtual Ref<DescriptorHeap> CreateDescriptorHeap() = 0;
    virtual Ref<RenderTargetView> CreateRenderTargetView() = 0;
    virtual Ref<RootSignature> CreateRootSignature() = 0;

    virtual Ref<Fence> CreateFence() = 0;
  };
}
