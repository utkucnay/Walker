#pragma once

#include <Core/Factory.h>

#include <Render/Device.h>

namespace wkr::render
{
  class Device;

  enum class FenceFlag
  {
    None                = 0,
    Shared              = 0x1,
    SharedCrossAdapter  = 0x2,
    NonMonitored        = 0x4
  };

  class Fence
  {
  public:
    virtual void* GetNativeHandle();
  };

  class FenceFactory : Factory<Fence, Ref<Device>, FenceFlag>
  {
  public:
    Fence*        CreateFactoryRaw(
        Ref<Device> device,
        FenceFlag fenceFlag) override;

    Ref<Fence>    CreateFactoryRef  (
        Ref<Device> device,
        FenceFlag fenceFlag) override;

    Scope<Fence>  CreateFactoryScope(
        Ref<Device> device,
        FenceFlag fenceFlag) override;
  };
}
