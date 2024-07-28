#pragma once

#include <Render/Core/SwapChain.h>

namespace wkr::render
{
  class USwapChain;
}

namespace wkr
{
  struct FWindowDesc
  {
    u32         m_width;
    u32         m_height;
    std::string m_name;
  };

  class UWindow
  {
  public:
    UWindow(FWindowDesc& windowDesc);
    virtual ~UWindow() = 0;

  public:
    void SetSwapChain(render::USwapChainHandle swapChain);

    b32 GetFullscreen() { return !GetWindowed(); }
    void SwapBuffers();

  public:
    virtual void OnUpdate()       = 0;
    virtual b32 IsShouldClose()   = 0;
    virtual void PoolEvents()     = 0;

    virtual u32 GetWidth()      = 0;
    virtual u32 GetHeight()     = 0;
    virtual b32 GetWindowed()   = 0;

    [[nodiscard]] mem::TWeakRef<render::USwapChain> GetSwapChain()
    {
        return m_swapChain;
    }

    virtual NativeObject GetNativeObject() = 0;

  public:
    WindowResizeEvent         m_resizeEvent;
    WindowSetFullscreenEvent  m_setFullscreenEvent;

  protected:
    mem::TWeakRef<render::USwapChain> m_swapChain;
  };

  using UWindowHandle = mem::TRef<UWindow>;
}
