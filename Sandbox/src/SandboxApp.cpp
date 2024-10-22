#include "Walker.inc"
#include "Core/EntryPoint.h"

namespace wkr
{
  class USandboxApp : public UApplication
  {
  public:
    USandboxApp(const FApplicationSpecs& specs) : UApplication(specs) {}
    ~USandboxApp() override { }
  };

  mem::TScope<UApplication> CreateApplication(const FApplicationCommandLineArgs& args)
  {
    FApplicationSpecs specs;
    specs.name = "Sandbox";
    specs.showCLI = true;
    specs.ApplicationCommandLineArgs = args;

    return mem::TScope<USandboxApp>::Create(specs);
  }
}
