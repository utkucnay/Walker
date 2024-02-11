#pragma once

#include <Core/Window.h>
#include <Render/Renderer.h>
#include <Render/RendererAPI.h>

int main(int argc, char** argv);

namespace wkr
{
  struct ApplicationCommandLineArgs
  {
    int argc;
    char** argv;
  };

  struct ApplicationSpecs
  {
    std::string name;
    bool showCLI;
    render::RendererAPI::APIType apiType;
    ApplicationCommandLineArgs ApplicationCommandLineArgs;
  };

  class Application
  {
  public:
    Application(const ApplicationSpecs& applicationSpecs);

  private:
    void Run();

  private:
    ApplicationSpecs appSpecs;
    Scope<Window> window;
    Scope<render::Renderer> graphics;

    friend int ::main(int argc, char** argv);
  };

  //defined in client
  Application* CreateApplication(const ApplicationCommandLineArgs& args);
}
