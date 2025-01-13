#include "Core/UApplication.h"
#include "Analytics/Memory/MemoryAnalytics.h"
#include "OS/Core/UOSFactory.h"

namespace wkr {

UApplication::UApplication(const FApplicationSpecs& applicationSpecs) {
  WKR_CORE_LOG("Application Starting");
  m_AppSpecs = applicationSpecs;

  os::UOSFactory::Init();

  auto& memoryAnalytics = analytics::MemoryAnalytics::GetInstance();
  memoryAnalytics.StartTracking();

  os::FWindowDesc windowDesc = {
      .Width = 1280,
      .Height = 720,
      .Name = "Walker Engine",
  };
  m_MainWindow = os::AWindowHandle(os::UOSFactory::Get().GetWindow(windowDesc));

  graphics::FGraphicsDesc graphicsDesc = {.Window = m_MainWindow};
  m_Graphics = new graphics::UGraphics(graphicsDesc);

  m_Graphics->CreateResource();
  m_Graphics->LoadResources();

  std::string memoryAnalyticsLog = memoryAnalytics.StopTracking();
  WKR_CORE_LOG(memoryAnalyticsLog);
}

UApplication::~UApplication() {
  m_Graphics.Release();
  m_MainWindow.Reset();

  os::UOSFactory::Destroy();
}

void UApplication::Run() {
  while (m_MainWindow->IsShouldClose()) {
    auto& memoryAnalytics = analytics::MemoryAnalytics::GetInstance();
    memoryAnalytics.StartTracking();

    m_MainWindow->PoolEvents();

    //TODO(utku): Game Logic

    m_Graphics->SwapBuffers();
    m_Graphics->Fence();
    m_Graphics->Render();

    std::string memoryAnalyticsLog = memoryAnalytics.StopTracking();
    //WKR_CORE_LOG(memoryAnalyticsLog);
  }
}

}  // namespace wkr
