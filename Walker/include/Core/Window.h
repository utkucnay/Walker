#pragma once

#include <Render/Core/SwapChain.h>

namespace wkr::render
{
  class USwapChain;
  class SwapChainBuilder;
}

namespace wkr
{
  class UWindow
  {
  public:
    virtual ~UWindow() = 0;

  public:
    void SetSwapChain(
          mem::WeakRef<render::USwapChain> swapChain);

    b32 GetFullscreen() { return !GetWindowed(); }
    void SwapBuffers();

  public:
    virtual void OnUpdate()       = 0;
    virtual b32 IsShouldClose()   = 0;
    virtual void PoolEvents()     = 0;

    virtual u32 GetWidth()      = 0;
    virtual u32 GetHeight()     = 0;
    virtual b32 GetWindowed()   = 0;

    [[nodiscard]] mem::WeakRef<render::USwapChain> GetSwapChain()
    {
        return m_swapChain;
    }

    virtual NativeHandle GetNativeHandle() = 0;

  public:
    WindowResizeEvent         m_resizeEvent;
    WindowSetFullscreenEvent  m_setFullscreenEvent;

  protected:
    mem::WeakRef<render::USwapChain> m_swapChain;
  };

  class WindowBuilder : IBuilder<UWindow>
  {
  public:
    WindowBuilder& SetName(const std::string& name);
    WindowBuilder& SetSize(u32 width, u32 height);

  public:
    [[nodiscard]] UWindow*             BuildRaw() override;
    [[nodiscard]] mem::Ref<UWindow>    BuildRef() override;
    [[nodiscard]] mem::Scope<UWindow>  BuildScope() override;

  public:
    u32         m_width;
    u32         m_height;
    std::string m_name;
  };
}
