#pragma once

#include "Core/AWindow.h"
#include "Memory/Allocator/PageAllocator.h"

namespace wkr::os {

CREATE_FACTORY(OS)
SUBS_FACTORY(AWindow, FWindowDesc&)
SUBS_FACTORY_NAMESPACE(mem, IPageAllocator, mem::FPageAllocatorDesc&)
END_FACTORY()

}  // namespace wkr::os
