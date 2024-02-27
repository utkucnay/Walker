#include <Core/Window.h>
#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
#include <Platforms/Windows/WindowsWindow.h>
#endif

namespace wkr
{
  Window::~Window()
  {

  }

  mem::Ref<render::SwapChain> Window::SetSwapChain(
      mem::Visitor<render::SwapChainBuilder> builder)
  {
    builder->SetWindow(this);
    auto swapChain = builder->BuildRef();
    m_swapChain = swapChain;
    return swapChain;
  }

  void Window::SwapBuffers()
  {
    if(m_swapChain.Expired())
    {
      WKR_CORE_LOG("Swap Chain Expired");
      return;
    }
    m_swapChain.Lock()->SwapBuffers();
  }

  //Builder
  WindowBuilder& WindowBuilder::SetName(const std::string& name)
  {
    m_windowDesc.name = name;
    return *this;
  }

  WindowBuilder& WindowBuilder::SetSize(uint32_t width, uint32_t height)
  {
    m_windowDesc.width = width;
    m_windowDesc.height = height;
    return *this;
  }

  Window* WindowBuilder::BuildRaw()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return new WindowsWindow(m_windowDesc);
  #endif
    return NULL;
  }

  mem::Ref<Window> WindowBuilder::BuildRef()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return mem::Ref<WindowsWindow>::Create(m_windowDesc);
  #endif
    return NULL;
  }

  mem::Scope<Window> WindowBuilder::BuildScope()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return mem::Scope<WindowsWindow>::Create(m_windowDesc);
  #endif
    return NULL;
  }
}
