#pragma once

#include "OS/Window/AWindow.h"
#include "OS/Memory/IPageAllocator.h"

namespace wkr::os {

CREATE_FACTORY(OS)
SUBS_FACTORY(AWindow, FWindowDesc&)
SUBS_FACTORY(IPageAllocator, FPageAllocatorDesc&)
END_FACTORY()

}  // namespace wkr::os
