#pragma once

#include "Graphics/Core/GraphicsType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FFenceDesc {
  u8 FrameCount = 0;
  EFenceF Flag = EFenceF::kNone;
};

class WALKER_API AFence {
 public:
  virtual ~AFence() = default;

 public:
  virtual void FenceEvent(int frameIndex) = 0;
  virtual NativeObject GetNativeObject(int frameIndex) = 0;

  void IncreaseFenceValue(int frameIndex) { m_FenceValue[frameIndex]++; }

  u64 GetFenceValue(int frameIndex) { return m_FenceValue[frameIndex]; }

 protected:
  std::vector<u64> m_FenceValue;
};

using AFenceHandle = mem::TRef<AFence>;

}  // namespace wkr::graphics::rhi
