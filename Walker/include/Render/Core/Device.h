#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
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
    Device*             CreateFactoryRaw(
        Adapter* adapter) override final;
    mem::Ref<Device>    CreateFactoryRef(
        Adapter* adapter) override final;
    mem::Scope<Device>  CreateFactoryScope(
        Adapter* adapter) override final;
  };
}
