#pragma once

#include <Core/EntryPoint.h>
#include <Core/Application.h>


extern wkr::Application* wkr::CreateApplication(const ApplicationCommandLineArgs& args);

int main(int argc, char** argv)
{
  auto app = wkr::CreateApplication({argc, argv});

  app->Run();

  delete app;

  return 0;
};
