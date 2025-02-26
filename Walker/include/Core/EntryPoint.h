#pragma once

extern wkr::mem::TScope<wkr::UApplication> CreateApplication(
    const wkr::FApplicationCommandLineArgs& args);

int main(int argc, char** argv) {
  wkr::mem::TScope<wkr::UApplication> app = CreateApplication({argv, argc});

  app->Run();
  return 0;
};
