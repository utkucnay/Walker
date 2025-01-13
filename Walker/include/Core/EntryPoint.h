#pragma once

extern wkr::mem::TScope<wkr::UApplication> CreateApplication(
    const wkr::FApplicationCommandLineArgs& args);

int main(int argc, char** argv) {
  wkr::analytics::MemoryAnalytics::CreateInstance();
  auto& memoryAnalytics = wkr::analytics::MemoryAnalytics::GetInstance();

  {
    wkr::mem::TScope<wkr::UApplication> app = CreateApplication({argv, argc});

    app->Run();

    memoryAnalytics.StartTracking();
  }

  std::string memoryAnalyticsLog = memoryAnalytics.StopTracking();
  WKR_CORE_LOG(memoryAnalyticsLog);

  wkr::analytics::MemoryAnalytics::DestroyInstance();
  return 0;
};
