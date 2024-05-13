#include <Core/EntryPoint.h>

namespace wkr
{
  class USandboxApp : public UApplication
  {
  public:
    USandboxApp(const FApplicationSpecs& specs) : UApplication(specs) {}
    ~USandboxApp() {}
  };

  mem::Scope<UApplication> CreateApplication(const FApplicationCommandLineArgs& args)
  {
    FApplicationSpecs specs;
    specs.name = "Sandbox";
    specs.showCLI = true;
    specs.ApplicationCommandLineArgs = args;

    return mem::Scope<USandboxApp>::Create(specs);
  }
}
