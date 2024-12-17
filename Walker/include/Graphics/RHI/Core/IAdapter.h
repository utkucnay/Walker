#pragma once

#include "Graphics/Core/GraphicsType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FAdapterDesc {
  std::string Name;
  u32 VendorID;
  u32 DeviveID;
  u32 SubSysID;
  u32 Revision;
  FLuid AdapterLuid;
  u64 DedicatedVideoMemory;
  u64 DedicatedSystemMemory;
  u64 SharedSystemMemory;
};

class WALKER_API IAdapter {
 public:
  virtual ~IAdapter() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;

  virtual FAdapterDesc GetDesc() = 0;
};

using IAdapterHandle = mem::TRef<IAdapter>;

}  // namespace wkr::graphics::rhi
