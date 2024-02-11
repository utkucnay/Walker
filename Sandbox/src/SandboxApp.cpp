#include <Core/EntryPoint.h>
#include <Core/Application.h>
#include <Render/RendererAPI.h>

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
    specs.apiType = render::RendererAPI::APIType::DirectX12;
    specs.ApplicationCommandLineArgs = args;

    return new SandboxApp(specs);
  }
}
