#pragma once

#include <Render/Core/SwapChain.h>

namespace wkr::render
{
  class SwapChain;
  class SwapChainBuilder;
}

namespace wkr
{

  struct WindowDesc
  {
    std::string name;
    uint32_t width, height;
  };

  class Window
  {
  public:
    virtual ~Window() = 0;

  public:
    bool GetFullscreen() { return !GetWindowed(); }
    mem::Ref<render::SwapChain> SetSwapChain(
        mem::Visitor<render::SwapChainBuilder> builder);
    void SwapBuffers();

  public:
    virtual void OnUpdate() = 0;
    virtual bool IsShouldClose() = 0;
    virtual void PoolEvents() = 0;

    virtual int GetWidth() = 0;
    virtual int GetHeight() = 0;
    virtual bool GetWindowed() = 0;

    virtual void* GetNativeHandle() = 0;

  public:
    WindowResizeEvent         m_resizeEvent;
    WindowSetFullscreenEvent  m_setFullscreenEvent;

  protected:
    mem::WeakRef<render::SwapChain> m_swapChain;
  };

  class WindowBuilder : Builder<Window>
  {
  public:
    WindowBuilder& SetName(const std::string& name);
    WindowBuilder& SetSize(uint32_t width, uint32_t height);

  public:
    Window*             BuildRaw() override;
    mem::Ref<Window>    BuildRef() override;
    mem::Scope<Window>  BuildScope() override;

  private:
    WindowDesc m_windowDesc;
  };
}
