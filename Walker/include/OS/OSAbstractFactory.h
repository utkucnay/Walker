#pragma once

#include <Core/Window.h>
#include <Memory/Allocator/PageAllocator.h>

namespace wkr::os
{
  CREATE_FACTORY()
    SUBS_FACTORY(AWindow, FWindowDesc&)
    SUBS_FACTORY_NAMESPACE(mem, IPageAllocator, mem::FPageAllocatorDesc&)
  END_FACTORY()
}
