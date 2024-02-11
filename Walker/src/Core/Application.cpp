#include <Core/Application.h>

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <Platforms/Windows/WindowsWindow.h>
  #include <Platforms/DirectX12/DX12Renderer.h>
#endif

namespace wkr
{
  Application::Application(
      const ApplicationSpecs& applicationSpecs)
  {
    WKR_CORE_LOG("Application Starting");
    appSpecs = applicationSpecs;

    ShowWindow(GetConsoleWindow(), applicationSpecs.showCLI);

    WindowProps wnProps;
    wnProps.name = "Walker Engine";
    wnProps.width = 1280;
    wnProps.height = 720;

    #if defined(WKR_PLATFORM_WINDOWS)
      window = CreateScope<WindowsWindow>(wnProps);
      graphics = CreateScope<render::DX12Renderer>(window.get());
    #endif
  }

  void Application::Run()
  {
    while (window->IsShouldClose())
    {

      window->PoolEvents();

      graphics->Render();
      graphics->SwapChain();
    }
  }
}
