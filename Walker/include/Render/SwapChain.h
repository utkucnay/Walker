#pragma once

#include <Core/Window.h>
#include <Render/RendererStructs.h>

namespace wkr::render
{
  enum class SwapEffect
  {
    Discard         = 0,
    Sequential      = 1,
    FlipSequential  = 3,
    FlipDiscard     = 4
  };

  enum class SwapFlag
  {
    Nonprerotated                         = 1,
    AllowModeSwitch                       = 2,
    GDICompatible                         = 4,
    RestrictedContent                     = 8,
    RestrictSharedResourceDriver          = 16,
    DisplayOnly                           = 32,
    FrameLatencyWaitableObject            = 64,
    ForegroundLayer                       = 128,
    FullscreenVideo                       = 256,
    YuvVideo                              = 512,
    HWProtected                           = 1024,
    AllowTearing                          = 2048,
    RestrictedToAllHolographicDisplays    = 4096
  };

  struct SwapChainDesc
  {
    ModeDesc bufferDesc;
    SampleDesc sampleDesc;
    Usage bufferUsage;
    uint32_t bufferCount;
    Window* window;
    SwapEffect swapEffect;
    SwapFlag flag;
  };

  class SwapChain
  {
  public:
    virtual void* GetNativeHandle();
  };
}
