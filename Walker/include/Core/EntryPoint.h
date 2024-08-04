#pragma once

#include <Core/Application.h>

extern wkr::mem::TScope<wkr::UApplication> wkr::CreateApplication(
    const FApplicationCommandLineArgs& args);

int main(int argc, char** argv)
{
  auto app = wkr::CreateApplication({argv, argc});

  app->Run();

  app.Release();

  return 0;
};
