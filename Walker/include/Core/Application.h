#pragma once

#include <Core/Window.h>
#include <Render/Core/Renderer.h>

int main(int argc, char** argv);

namespace wkr
{
  struct FApplicationCommandLineArgs
  {
    char** argv;
    int argc;
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
    AWindowHandle             m_mainWindow;
    FApplicationSpecs         appSpecs;
    render::URendererHandle   m_renderer;

    friend int ::main(int argc, char** argv);
  };

  mem::TScope<UApplication> CreateApplication(const FApplicationCommandLineArgs& args);
}
