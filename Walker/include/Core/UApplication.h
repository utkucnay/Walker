#pragma once

#include "OS/Memory/IPageAllocator.h"
#include "OS/Window/AWindow.h"
#include "Graphics/Core/UGraphics.h"

int main(int argc, char** argv);

namespace wkr {

struct WALKER_API FApplicationCommandLineArgs {
  char** argv = nullptr;
  i32 argc = 0;
};

struct WALKER_API FApplicationSpecs {
  std::string name = {};
  b32 showCLI = false;
  FApplicationCommandLineArgs ApplicationCommandLineArgs = {};
};

class WALKER_API UApplication {
 public:
  explicit UApplication(const FApplicationSpecs& applicationSpecs);
  virtual ~UApplication();

 private:
  void Run();

 private:
  os::AWindowHandle m_MainWindow;
  FApplicationSpecs m_AppSpecs;
  mem::TScope<graphics::UGraphics> m_Graphics;
  mem::TScope<os::IPageAllocator> m_PageAllocator;

  friend int ::main(int argc, char** argv);
};

mem::TScope<UApplication> CreateApplication(
    const FApplicationCommandLineArgs& args);

}  // namespace wkr
