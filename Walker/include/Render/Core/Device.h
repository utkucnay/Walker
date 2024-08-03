#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
  struct FDeviceDesc
  {
    IAdapter* adapter;
  };

  class IDevice
  {
  public:
    virtual ~IDevice() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
  };

  using IDeviceHandle = mem::TRef<IDevice>;
}
