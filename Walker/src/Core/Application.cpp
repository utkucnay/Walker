#include <Core/Application.h>

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <Platforms/Windows/WindowsWindow.h>
#endif

namespace wkr
{
  Application::Application(
      const ApplicationSpecs& applicationSpecs)
  {
    WKR_CORE_LOG("Application Starting");
    appSpecs = applicationSpecs;

    ShowWindow(GetConsoleWindow(), applicationSpecs.showCLI);

    WindowBuilder windowBuilder;
    windowBuilder.SetName("Walker Engine");
    windowBuilder.SetSize(1280, 720);

    m_window = windowBuilder.BuildScope();
    m_renderer = mem::Scope<render::Renderer>::Create(m_window.Get());
  }

  void Application::Run()
  {
    while (m_window->IsShouldClose())
    {
      m_window->PoolEvents();

      m_renderer->RenderScene();
      m_window->SwapBuffers();
    }
  }
}
