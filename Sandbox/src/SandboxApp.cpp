#include "Walker.inc"

// clang-format off
#include "Core/EntryPoint.h"
// clang-format on

namespace sandbox {

class USandboxApp : public wkr::UApplication {
 public:
  USandboxApp(const wkr::FApplicationSpecs& specs) : UApplication(specs) {}

  ~USandboxApp() override {}
};

wkr::mem::TScope<wkr::UApplication> CreateApplication(
    const wkr::FApplicationCommandLineArgs& args) {
  wkr::FApplicationSpecs specs = {
      .name = "Sandbox", .showCLI = true, .ApplicationCommandLineArgs = args};

  return wkr::mem::TScope<USandboxApp>::Create(specs);
}

}  // namespace sandbox
