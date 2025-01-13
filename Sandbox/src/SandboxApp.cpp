#include "Core/UApplication.h"
#include "Walker.h"

// clang-format off
#include "Core/EntryPoint.h"
// clang-format on

namespace sandbox {

class USandboxApp : public wkr::UApplication {
 public:
  USandboxApp(const wkr::FApplicationSpecs& specs) : UApplication(specs) {}

  ~USandboxApp() override { wkr::UApplication::~UApplication(); }
};

}  // namespace sandbox

wkr::mem::TScope<wkr::UApplication> CreateApplication(
    const wkr::FApplicationCommandLineArgs& args) {
  wkr::FApplicationSpecs specs = {
      .name = "Sandbox", .showCLI = false, .ApplicationCommandLineArgs = args};

  return wkr::mem::TScope<sandbox::USandboxApp>::Create(specs);
}
