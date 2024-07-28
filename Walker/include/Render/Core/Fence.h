#pragma once

#include <Render/Core/Device.h>

namespace wkr::render
{
  enum class EFenceFlag
  {
    None                = 0,
    Shared              = 0x1,
    SharedCrossAdapter  = 0x2,
    NonMonitored        = 0x4
  };

  struct FFenceDesc
  {
    u8      m_frameCount;
    EFenceFlag   m_flag;
  };

  class IFence
  {
  public:
    virtual ~IFence() {}

  public:
    virtual void FenceEvent(int frameIndex) = 0;
    virtual NativeObject GetNativeObject(int frameIndex) = 0;
  };

  using FenceHandle = mem::TRef<IFence>;
}
