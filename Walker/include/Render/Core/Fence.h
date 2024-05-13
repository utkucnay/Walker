#pragma once

#include <Render/Core/Device.h>

namespace wkr::render
{
  class IDevice;

  class IFence : public ICloneable<IFence>
  {
  protected:
    IFence() {}

  public:
    enum class Flag
    {
      None                = 0,
      Shared              = 0x1,
      SharedCrossAdapter  = 0x2,
      NonMonitored        = 0x4
    };

  public:
    virtual ~IFence() {}

  public:
    virtual void FenceEvent(int frameIndex) = 0;
    virtual NativeHandle GetNativeHandle(int frameIndex) = 0;
  };

  class FenceBuilder : IBuilder<IFence>
  {
  public:
    FenceBuilder& SetFenceFlag(IFence::Flag fenceFlag);
    FenceBuilder& SetFrameCount(u8 frameCount);

    IFence*            BuildRaw  () override final;
    mem::Ref<IFence>   BuildRef  () override final;
    mem::Scope<IFence> BuildScope() override final;

  public:
    u8            m_frameCount;
    IFence::Flag  m_fenceFlag{};
  };
}
