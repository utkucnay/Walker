#pragma once

#include "OS/Factory/IOSAbstractFactory.h"
#include "Platforms/Windows/Windows.h"

namespace wkr::os::windows {

REGISTER_FACTORY(AWindow, UWindow, FWindowDesc&)
REGISTER_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)

BEGIN_ABSTRACT_FACTORY(OS)
SUBS_ABSTRACT_FACTORY(AWindow, UWindow, FWindowDesc&)
SUBS_ABSTRACT_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)
END_FACTORY()

}  // namespace wkr::os::windows
