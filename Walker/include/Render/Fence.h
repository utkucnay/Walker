#pragma once

#include <Render/Device.h>

namespace wkr::render
{
  class Device;

  class Fence
  {
  public:
    enum class Flag
    {
      None                = 0,
      Shared              = 0x1,
      SharedCrossAdapter  = 0x2,
      NonMonitored        = 0x4
    };

  public:
    virtual ~Fence() = 0;

  public:
    virtual void FenceEvent() = 0;
    virtual void* GetNativeHandle();
  };

  class FenceBuilder : Builder<Fence, mem::Ref<Device>>
  {
  public:
    FenceBuilder* SetFenceFlag(Fence::Flag fenceFlag);

    Fence*            BuildRaw  (mem::Ref<Device> device) override;
    mem::Ref<Fence>   BuildRef  (mem::Ref<Device> device) override;
    mem::Scope<Fence> BuildScope(mem::Ref<Device> device) override;

  private:
    Fence::Flag m_fenceFlag;
  };

  class FenceFactory : Factory<Fence, mem::Ref<Device>, Fence::Flag>
  {
  public:
    Fence*            CreateFactoryRaw(
        mem::Ref<Device> device,
        Fence::Flag fenceFlag) override;

    mem::Ref<Fence>   CreateFactoryRef  (
        mem::Ref<Device> device,
        Fence::Flag fenceFlag) override;

    mem::Scope<Fence> CreateFactoryScope(
        mem::Ref<Device> device,
        Fence::Flag fenceFlag) override;
  };
}
