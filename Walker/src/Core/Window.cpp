#include <Core/Window.h>
#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
#include <Platforms/Windows/WindowsWindow.h>
#endif

namespace wkr
{
  UWindow::~UWindow()
  {

  }

  void UWindow::SetSwapChain(
      mem::WeakRef<render::USwapChain> swapChain)
  {
    m_swapChain = swapChain;
  }

  void UWindow::SwapBuffers()
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
    m_name = name;
    return *this;
  }

  WindowBuilder& WindowBuilder::SetSize(uint32_t width, uint32_t height)
  {
    m_width = width;
    m_height = height;
    return *this;
  }

  UWindow* WindowBuilder::BuildRaw()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return new UWindowsWindow(*this);
  #endif
    return NULL;
  }

  mem::Ref<UWindow> WindowBuilder::BuildRef()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return mem::Ref<UWindowsWindow>::Create(*this);
  #endif
    return NULL;
  }

  mem::Scope<UWindow> WindowBuilder::BuildScope()
  {
  #if defined (WKR_PLATFORM_WINDOWS)
    return mem::Scope<UWindowsWindow>::Create(*this);
  #endif
    return NULL;
  }
}
