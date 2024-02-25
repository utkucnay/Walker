#pragma once

#include <Render/Command.h>

#include <Render/RenderTargetView.h>
#include <Render/DescriptorHeap.h>
#include <Render/RootSignature.h>
#include <Render/Adapter.h>
#include <Render/Fence.h>

namespace wkr::render
{
  class CommandAllocator;
  class CommandQueue;
  class CommandList;
  struct CommandQueueDesc;

  class Fence;

  class Device
  {
  public:
    virtual ~Device() = 0;

  public:
    virtual void* GetNativeHandle() = 0;

    virtual mem::Ref<CommandQueue> CreateCommandQueue(CommandQueueDesc& desc) = 0;
    virtual mem::Ref<CommandAllocator> CreateCommandAllocator() = 0;
    virtual mem::Ref<CommandList> CreateCommandList() = 0;

    virtual mem::Ref<DescriptorHeap> CreateDescriptorHeap() = 0;
    virtual mem::Ref<RenderTargetView> CreateRenderTargetView() = 0;

    virtual mem::Ref<RootSignature> CreateRootSignature() = 0;

    virtual mem::Ref<Fence> CreateFence() = 0;
  };

  class DeviceFactory : Factory<Device, mem::Ref<Adapter>>
  {
  public:
    Device*             CreateFactoryRaw(mem::Ref<Adapter> adapter)    override;
    mem::Ref<Device>    CreateFactoryRef(mem::Ref<Adapter> adapter)    override;
    mem::Scope<Device>  CreateFactoryScope(mem::Ref<Adapter> adapter)  override;
  };
}
