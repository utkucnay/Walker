#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
  struct FDeviceDesc
  {
    mem::WeakRef<IAdapter> adapter;
  };

  class IDevice
  {
  public:
    virtual ~IDevice() {}

  public:
    virtual NativeObject GetNativeObject() = 0;
  };

  using DeviceHandle = mem::Ref<IDevice>;
}
