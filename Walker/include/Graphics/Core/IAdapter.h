#pragma once

#include "Graphics/Core/GraphicsType.h"

namespace wkr::render {

class IAdapter {
 public:
  virtual ~IAdapter() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;

  virtual std::string GetName() = 0;

  virtual u32 GetVendorID() = 0;
  virtual u32 GetDeviceID() = 0;
  virtual u32 GetSubSysID() = 0;
  virtual u32 GetRevision() = 0;

  virtual FLuid GetAdapterLuid() = 0;

  virtual u64 GetDedicatedVideoMemory() = 0;
  virtual u64 GetDedicatedSystemMemory() = 0;
  virtual u64 GetSharedSystemMemory() = 0;
};

using IAdapterHandle = mem::TRef<IAdapter>;

}  // namespace wkr::render
