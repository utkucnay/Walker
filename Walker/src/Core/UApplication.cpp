#include "Core/UApplication.h"

#include "OS/UOSFactory.h"

namespace wkr {

UApplication::UApplication(const FApplicationSpecs& applicationSpecs) {
  WKR_CORE_LOG("Application Starting");
  appSpecs = applicationSpecs;

  os::UOSFactory::Init();

  FWindowDesc windowDesc = {};
  windowDesc.m_name = "Walker Engine";
  windowDesc.m_width = 1280;
  windowDesc.m_height = 720;
  m_mainWindow = os::UOSFactory::Get().GetAWindow()->Create(windowDesc);

  render::FGraphicsDesc rendererDesc;
  rendererDesc.window = m_mainWindow;
  m_renderer = new render::UGraphics(rendererDesc);

  m_renderer->CreateResource();
  m_renderer->LoadResources();
}

UApplication::~UApplication() {
  m_renderer.Release();
  m_mainWindow.Reset();
}

void UApplication::Run() {
  while (m_mainWindow->IsShouldClose()) {
    m_mainWindow->PoolEvents();

    m_renderer->Render();
    m_mainWindow->SwapBuffers();
  }
}

}  // namespace wkr
