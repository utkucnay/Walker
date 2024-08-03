#pragma once

#include <Render/Core/CoreTypes.h>

namespace wkr::render
{
  struct FFenceDesc
  {
    u8          m_frameCount;
    EFenceFlag  m_flag;
  };

  class IFence
  {
  public:
    virtual ~IFence() = default;

  public:
    virtual void FenceEvent(int frameIndex) = 0;
    virtual NativeObject GetNativeObject(int frameIndex) = 0;
  };

  using IFenceHandle = mem::TRef<IFence>;
}
