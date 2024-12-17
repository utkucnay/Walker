#pragma once

#include "Graphics/RHI/Command/CommandType.h"
#include "Graphics/RHI/Command/ICommandList.h"
#include "Graphics/RHI/Core/IFence.h"

namespace wkr::graphics::rhi {

struct WALKER_API FCommandQueueDesc {
  ECommandType CommandType = ECommandType::kNone;
  ECommandQueuePriority CommandQueuePriority = ECommandQueuePriority::kNormal;
  ECommandQueueF CommandQueueFlag = ECommandQueueF::kNone;
};

class WALKER_API ICommandQueue {
 public:
  virtual ~ICommandQueue() = default;

 public:
  virtual void ExecuteCommandList(
      const std::vector<ICommandList*>& commandLists) = 0;
  virtual void Signal(AFence& fence, i32 frameIndex) = 0;
  virtual FCommandQueueDesc GetDesc() = 0;
  virtual NativeObject GetNativeObject() = 0;
};

using ICommandQueueHandle = wkr::mem::TRef<ICommandQueue>;

}  // namespace wkr::graphics::rhi
