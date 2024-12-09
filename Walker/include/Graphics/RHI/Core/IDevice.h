#pragma once

#include "Graphics/RHI/Core/IAdapter.h"

namespace wkr::graphics::rhi {

struct WALKER_API FDeviceDesc {
  IAdapter* Adapter;
};

class WALKER_API IDevice {
 public:
  virtual ~IDevice() = default;

 public:
  virtual FDeviceDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;
};

using IDeviceHandle = mem::TRef<IDevice>;

}  // namespace wkr::graphics::rhi
