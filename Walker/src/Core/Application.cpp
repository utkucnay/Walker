#include <Core/Application.h>

#include <Platforms/Windows/WindowsWindow.h>

namespace wkr
{
  UApplication::UApplication(
      const FApplicationSpecs& applicationSpecs)
  {
    WKR_CORE_LOG("Application Starting");
    appSpecs = applicationSpecs;


    FWindowDesc windowDesc = {};
    windowDesc.m_name = "Walker Engine";
    windowDesc.m_width = 1280;
    windowDesc.m_height = 720;
    m_mainWindow = static_cast<wkr::UWindowHandle>(
      wkr::windows::UWindowHandle::Create(windowDesc));

    m_renderer = render::URendererHandle::Create(m_mainWindow);

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
