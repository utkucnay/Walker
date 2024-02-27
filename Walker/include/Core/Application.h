#pragma once

#include <Core/Window.h>
#include <Render/Renderer.h>

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
    ApplicationCommandLineArgs ApplicationCommandLineArgs;
  };

  class Application
  {
  public:
    Application(const ApplicationSpecs& applicationSpecs);

  private:
    void Run();

  private:
    ApplicationSpecs              appSpecs; //?
    mem::Scope<Window>            m_window;
    mem::Scope<render::Renderer>  m_renderer;

    friend int ::main(int argc, char** argv);
  };

  //defined in client
  Application* CreateApplication(const ApplicationCommandLineArgs& args);
}
