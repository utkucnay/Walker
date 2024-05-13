#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
  class IDevice
  {
  public:
    virtual ~IDevice() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
  };

  class DeviceBuilder : IBuilder<IDevice>
  {
  public:
    DeviceBuilder& SetAdapter(mem::WeakRef<IAdapter> adapter);

  public:
    IDevice*             BuildRaw()    override final;
    mem::Ref<IDevice>    BuildRef()    override final;
    mem::Scope<IDevice>  BuildScope()  override final;

  public:
    mem::WeakRef<IAdapter> m_adapter;
  };
}
