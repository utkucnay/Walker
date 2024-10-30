#pragma once

#include "Graphics/RHI/Command/CommandType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FCommandAllocatorDesc {
  ECommandType CommandType = ECommandType::kNone;
};

class WALKER_API ICommandAllocator {
 public:
  virtual ~ICommandAllocator() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
  virtual FCommandAllocatorDesc GetDesc() const = 0;
  virtual void Reset() = 0;
};

using ICommandAllocatorHandle = mem::TRef<ICommandAllocator>;

}  // namespace wkr::graphics::rhi
