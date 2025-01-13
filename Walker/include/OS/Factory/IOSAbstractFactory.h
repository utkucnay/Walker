#pragma once

#include "OS/Memory/IPageAllocator.h"
#include "OS/Window/AWindow.h"

namespace wkr::os {

class IOSAbstractFactory {
 public:
  virtual ~IOSAbstractFactory() = default;

 public:
  virtual AWindow* GetWindow(const FWindowDesc& desc) = 0;
  virtual IPageAllocator* GetPageAllocator(const FPageAllocatorDesc& desc) = 0;
};

}  // namespace wkr::os
