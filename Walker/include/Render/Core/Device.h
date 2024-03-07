#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
  class Device
  {
  public:
    virtual ~Device() {}

  public:
    virtual void* GetNativeHandle() = 0;
  };

  class DeviceBuilder : Builder<Device>
  {
  public:
    DeviceBuilder& SetAdapter(Adapter* adapter);

  public:
    Device*             BuildRaw()    override final;
    mem::Ref<Device>    BuildRef()    override final;
    mem::Scope<Device>  BuildScope()  override final;

  public:
    Adapter* m_adapter{};
  };
}
