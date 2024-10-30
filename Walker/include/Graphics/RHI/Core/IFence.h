#pragma once

#include "Graphics/Core/GraphicsType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FFenceDesc {
  u8 m_frameCount = 0;
  EFenceF m_flag = EFenceF::kNone;
};

class WALKER_API IFence {
 public:
  virtual ~IFence() = default;

 public:
  virtual void FenceEvent(int frameIndex) = 0;
  virtual NativeObject GetNativeObject(int frameIndex) = 0;
};

using IFenceHandle = mem::TRef<IFence>;

}  // namespace wkr::graphics::rhi
