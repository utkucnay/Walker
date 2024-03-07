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
    virtual void FenceEvent() = 0;
    virtual void* GetNativeHandle() = 0;
  };

  class FenceBuilder : Builder<Fence>
  {
  public:
    FenceBuilder* SetFenceFlag(Fence::Flag fenceFlag);

    Fence*            BuildRaw  () override final;
    mem::Ref<Fence>   BuildRef  () override final;
    mem::Scope<Fence> BuildScope() override final;

  public:
    Device*     m_device;
    Fence::Flag m_fenceFlag{};

    friend class Fence;
  };
}
