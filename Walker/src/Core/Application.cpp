#include <Core/Application.h>

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <Platforms/Windows/WindowsWindow.h>
#endif

namespace wkr
{
  UApplication::UApplication(
      const FApplicationSpecs& applicationSpecs)
  {
    WKR_CORE_LOG("Application Starting");
    appSpecs = applicationSpecs;

    ShowWindow(GetConsoleWindow(), applicationSpecs.showCLI);

    m_mainWindow = mem::Scope<WindowBuilder>::Create().Get()
      .SetName("Walker Engine")
      .SetSize(1280, 720)
      .BuildRef();

    m_renderer = mem::Ref<render::URenderer>::Create(m_mainWindow);

    m_renderer->CreateResource();
    m_renderer->LoadResources();
  }

  UApplication::~UApplication()
  {
    m_renderer.Reset();
    m_mainWindow.Reset();
  }

  void UApplication::Run()
  {
    while (m_mainWindow->IsShouldClose())
    {
      m_mainWindow->PoolEvents();

      m_renderer->Render();
      m_mainWindow->SwapBuffers();
    }
  }
}
