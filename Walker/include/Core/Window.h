#pragma once

#include <Render/Core/SwapChain.h>

namespace wkr::render
{
  class ASwapChain;
  using ASwapChainHandle = mem::TRef<ASwapChain>;
}

namespace wkr
{
  struct FWindowDesc
  {
    u32         m_width;
    u32         m_height;
    std::string m_name;
    b32         showCLI;
  };

  class AWindow
  {
  public:
    virtual ~AWindow() = default;

  public:
    void SetSwapChain(render::ASwapChainHandle swapChain)
    { m_swapChain = swapChain; }

    b32 GetFullscreen() { return !GetWindowed(); }
    void SwapBuffers();

  public:
    virtual void  OnUpdate()        = 0;
    virtual b32   IsShouldClose()   = 0;
    virtual void  PoolEvents()      = 0;

    virtual u32 GetWidth()      = 0;
    virtual u32 GetHeight()     = 0;
    virtual b32 GetWindowed()   = 0;

    mem::TWeakRef<render::ASwapChain> GetSwapChain()
    {
        return m_swapChain;
    }

    virtual NativeObject GetNativeObject() = 0;

  public:
    WindowResizeEvent         m_resizeEvent;
    WindowSetFullscreenEvent  m_setFullscreenEvent;

  protected:
    mem::TWeakRef<render::ASwapChain> m_swapChain;
  };

  using AWindowHandle = mem::TRef<AWindow>;
}
