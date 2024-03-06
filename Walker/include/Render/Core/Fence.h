#pragma once

#include <Render/Core/Device.h>

namespace wkr::render
{
  class Device;
  class FenceBuilder;

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
    virtual ~Fence() {}

  public:
    virtual Fence::Flag GetFlag() = 0;

  public:
    virtual void FenceEvent() = 0;
    virtual void* GetNativeHandle();
  };

  class FenceBuilder : Builder<Fence, Device*>
  {
  public:
    FenceBuilder* SetFenceFlag(Fence::Flag fenceFlag);

    Fence*            BuildRaw  (Device* device) override;
    mem::Ref<Fence>   BuildRef  (Device* device) override;
    mem::Scope<Fence> BuildScope(Device* device) override;

  public:
    Device*     m_device;
    Fence::Flag m_fenceFlag{};

    friend class Fence;
  };
}
