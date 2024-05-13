#pragma once

#include <Core/Window.h>
#include <Render/Core/Renderer.h>

int main(int argc, char** argv);

namespace wkr
{
  struct FApplicationCommandLineArgs
  {
    char** argv;
    i32 argc;
  };

  struct FApplicationSpecs
  {
    std::string name;
    FApplicationCommandLineArgs ApplicationCommandLineArgs;
    b32 showCLI;
  };

  class UApplication
  {
  public:
    UApplication(const FApplicationSpecs& applicationSpecs);
    virtual ~UApplication();

  private:
    void Run();

  private:
    FApplicationSpecs             appSpecs;
    mem::Ref<UWindow>             m_mainWindow;
    mem::Ref<render::URenderer>   m_renderer;

    friend int ::main(int argc, char** argv);
  };

  //defined in client
  mem::Scope<UApplication> CreateApplication(const FApplicationCommandLineArgs& args);
}
