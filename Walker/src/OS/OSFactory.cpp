#include <OS/OSFactory.h>
#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #include <Platforms/Windows/OSWindowsAbstractFactory.h>
#endif

namespace wkr::os
{
  void OSFactory::Init()
  {
    s_instance = nullptr;

#if defined (WKR_PLATFORM_WINDOWS)
    s_instance = new windows::UAbstractFactory();
#endif
  }
}
