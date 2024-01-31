#include <Core/Application.h>

#include <Core/PlatformDetection.h>
#include <memory>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <Platforms/Windows/WindowsWindow.h>
  #include <Platforms/DirectX12/DX12Graphics.h>
#endif

namespace wkr
{
  Application::Application(
      const ApplicationSpecs& applicationSpecs)
  {
    appSpecs = applicationSpecs;

    ShowWindow(GetConsoleWindow(), applicationSpecs.showCLI);

    WindowProps wnProps;
    wnProps.name = "Walker Engine";
    wnProps.width = 1280;
    wnProps.height = 720;

    #if defined(WKR_PLATFORM_WINDOWS)
      window = CreateScope<WindowsWindow>(wnProps);
      graphics = CreateScope<DX12Graphics>(window.get());
    #endif
  }

  void Application::Run()
  {
    while (window->IsShouldClose())
    {

      graphics->Render();
      graphics->SwapChain();
      window->PoolEvents();
    }
  }
}
