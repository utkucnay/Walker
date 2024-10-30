#pragma once

#include "Core/UApplication.h"

extern wkr::mem::TScope<wkr::UApplication> wkr::CreateApplication(
    const FApplicationCommandLineArgs& args);

int main(int argc, char** argv) {
  wkr::mem::TScope<wkr::UApplication> app = wkr::CreateApplication({argv, argc});

  app->Run();

  return 0;
};
