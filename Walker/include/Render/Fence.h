#pragma once

#include <Render/Device.h>

namespace wkr::render
{
  class Device;

  enum class FenceFlag
  {
    None = 0,
    Shared = 0x1,
    SharedCrossAdapter = 0x2,
    NonMonitored = 0x4
  };

  class Fence
  {
  public:
    virtual void* GetNativeHandle();

  public:
    static Ref<Fence> Create(Ref<Device> device);
  };
}
