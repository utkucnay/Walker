#include "Core/UApplication.h"
#include "OS/Core/UOSFactory.h"

namespace wkr {

UApplication::UApplication(const FApplicationSpecs& applicationSpecs) {
  WKR_CORE_LOG("Application Starting");
  m_AppSpecs = applicationSpecs;

  os::UOSFactory::Init();

  os::FWindowDesc windowDesc = {
    .Width = 1280,
    .Height = 720,
    .Name = "Walker Engine",
  };
  m_MainWindow = os::UOSFactory::Get().GetAWindow()->Create(windowDesc);

  graphics::FGraphicsDesc graphicsDesc = {
    .Window = m_MainWindow
  };
  m_Graphics = new graphics::UGraphics(graphicsDesc);

  m_Graphics->CreateResource();
  m_Graphics->LoadResources();
}

UApplication::~UApplication() {
  m_Graphics.Release();
  m_MainWindow.Reset();
  os::UOSFactory::Destroy();
}

void UApplication::Run() {
  while (m_MainWindow->IsShouldClose()) {
    m_MainWindow->PoolEvents();

    m_Graphics->Render();
    //m_MainWindow->SwapBuffers();
  }
}

}  // namespace wkr
