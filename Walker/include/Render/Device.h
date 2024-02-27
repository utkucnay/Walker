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
  };

  class DeviceFactory : Factory<Device, Adapter*>
  {
  public:
    Device*             CreateFactoryRaw(Adapter* adapter)    override;
    mem::Ref<Device>    CreateFactoryRef(Adapter* adapter)    override;
    mem::Scope<Device>  CreateFactoryScope(Adapter* adapter)  override;
  };
}
