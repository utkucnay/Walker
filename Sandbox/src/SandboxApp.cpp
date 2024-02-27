#include <Core/EntryPoint.h>

namespace wkr
{
  class SandboxApp : public Application
  {
  public:
    SandboxApp(const ApplicationSpecs& specs) : Application(specs) {}
    ~SandboxApp() {}
  };

  Application* CreateApplication(const ApplicationCommandLineArgs& args)
  {
    ApplicationSpecs specs;
    specs.name = "Sandbox";
    specs.showCLI = true;
    specs.ApplicationCommandLineArgs = args;

    return new SandboxApp(specs);
  }
}
