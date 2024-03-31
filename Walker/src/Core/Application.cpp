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
    windowBuilder
      .SetName("Walker Engine")
      .SetSize(1280, 720);

    m_mainWindow = windowBuilder.BuildScope();
    m_renderer = mem::Scope<render::Renderer>::Create(m_mainWindow.Get());
  }

  Application::~Application()
  {
    m_renderer.Release();
    m_mainWindow.Release();
  }

  void Application::Run()
  {
    while (m_mainWindow->IsShouldClose())
    {
      m_mainWindow->PoolEvents();

      m_renderer->Render();
      m_mainWindow->SwapBuffers();
    }
  }
}
