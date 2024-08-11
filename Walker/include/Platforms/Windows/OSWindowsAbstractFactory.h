#pragma once

#include <Platforms/Windows/WindowsWindow.h>
#include <Platforms/Windows/WindowsPageAllocator.h>
#include <OS/OSAbstractFactory.h>

namespace wkr::os::windows
{
  REGISTER_FACTORY(AWindow, UWindow, FWindowDesc&)
  REGISTER_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)

  BEGIN_ABSTRACT_FACTORY()
    SUBS_ABSTRACT_FACTORY(AWindow, UWindow, FWindowDesc&)
    SUBS_ABSTRACT_FACTORY(IPageAllocator, UPageAllocator, FPageAllocatorDesc&)
  END_FACTORY()
}

