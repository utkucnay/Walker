#pragma once

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
    ApplicationSpecs appSpecs;
    Scope<Window> window;
    Scope<Graphics> graphics;

    friend int ::main(int argc, char** argv);
  };

  //defined in client
  Application* CreateApplication(const ApplicationCommandLineArgs& args);
}
