#include "OS/Core/UOSFactory.h"
#include "Core/PlatformDetection.h"

#if defined(WKR_PLATFORM_WINDOWS)
#include "Platforms/Windows/Factory/WindowsAbstractFactory.h"
#endif

namespace wkr::os {

void UOSFactory::Init() {
  s_instance = nullptr;

#if defined(WKR_PLATFORM_WINDOWS)
  s_instance = new windows::UOSAbstractFactory();
#endif
}

}  // namespace wkr::os
