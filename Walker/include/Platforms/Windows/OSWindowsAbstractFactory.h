#pragma once

#include "OS/IOSAbstractFactory.h"
#include "Platforms/Windows/WindowsPageAllocator.h"
#include "Platforms/Windows/WindowsWindow.h"

namespace wkr::os::windows {

REGISTER_FACTORY(AWindow, UWindow, FWindowDesc&)
REGISTER_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)

BEGIN_ABSTRACT_FACTORY(OS)
SUBS_ABSTRACT_FACTORY(AWindow, UWindow, FWindowDesc&)
SUBS_ABSTRACT_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)
END_FACTORY()

}  // namespace wkr::os::windows
