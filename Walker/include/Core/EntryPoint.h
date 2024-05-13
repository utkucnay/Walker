#pragma once

#include <Core/Application.h>

extern wkr::mem::Scope<wkr::UApplication> wkr::CreateApplication(
    const FApplicationCommandLineArgs& args);

int main(int argc, char** argv)
{
  auto app = wkr::CreateApplication({argv, argc});

  app->Run();

  return 0;
};
