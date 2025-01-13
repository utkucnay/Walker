#pragma once

#include "OS/Factory/IOSAbstractFactory.h"
#include "Platforms/Windows/Windows.h"

namespace wkr::os::windows {

class UOSAbstractFactory : public IOSAbstractFactory {
 public:
  ~UOSAbstractFactory() override = default;

 public:
  AWindow* GetWindow(const FWindowDesc& desc) override final {
    return new UWindow(desc);
  }

  IPageAllocator* GetPageAllocator(
      const FPageAllocatorDesc& desc) override final {
    return new UPageAllocator(desc);
  }
};

}  // namespace wkr::os::windows
