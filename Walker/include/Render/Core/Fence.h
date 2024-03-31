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
    virtual void FenceEvent(int frameIndex) = 0;
    virtual void* GetNativeHandle(int frameIndex) = 0;
  };

  class FenceBuilder : Builder<Fence>
  {
  public:
    FenceBuilder& SetFenceFlag(Fence::Flag fenceFlag);
    FenceBuilder& SetFrameCount(uint8_t frameCount);

    Fence*            BuildRaw  () override final;
    mem::Ref<Fence>   BuildRef  () override final;
    mem::Scope<Fence> BuildScope() override final;

  public:
    Device*     m_device;
    Fence::Flag m_fenceFlag{};
    uint8_t m_frameCount;
  };
}
