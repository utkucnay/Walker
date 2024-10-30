#pragma once

#include "Graphics/Core/GraphicsType.h"
#include "Graphics/RHI/Command/ICommandQueue.h"
#include "Graphics/RHI/Core/IFence.h"
#include "Graphics/RHI/Descriptor/ADescriptorHeap.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics::rhi {

struct WALKER_API FSwapChainDesc {
  u32 m_bufferCount = 0;
  FSample m_sampleDesc = {0, 0};
  ESwapChainF m_flag = ESwapChainF::kNone;
  ESwapChainEffect m_swapEffect = ESwapChainEffect::kDiscard;
  AWindowHandle m_window = {};
  FModeDesc m_bufferDesc = {};
  EResourceUsageF m_bufferUsage = EResourceUsageF::kCPU_ACCESS_NONE;
  ICommandQueueHandle m_commandQueue = nullptr;
};

class WALKER_API ASwapChain {
 public:
  virtual ~ASwapChain() = default;

 public:
  virtual void WindowSizeEvent(u32 width, u32 height) = 0;
  virtual void FullscreenEvent(b64 isTrue) = 0;
  virtual void SwapBuffers() = 0;

  virtual NativeObject GetNativeObject() = 0;
  virtual FSwapChainDesc GetDesc() const = 0;

  [[nodiscard]] virtual IFence& GetCurrentFence() { return m_fence.Get(); }

  virtual void Present(u8 syncInterval, u8 flags) = 0;

 public:
  virtual u32 GetFrameIndex() { return m_frameIndex; }

  [[nodiscard]] ARenderTargetViewHandle GetCurrentRenderTarget() {
    return m_descripHeap->Get<ARenderTargetView>(GetFrameIndex());
  }

 protected:
  u32 m_frameIndex;
  wkr::mem::TScope<IFence> m_Fence;
  IDescriptorHeapHandle m_DescripHeap;

 private:
  WindowResizeEvent::FEvent m_ResizeEvent;
  WindowSetFullscreenEvent::FEvent m_FullscreenEvent;
};

using ASwapChainHandle = wkr::mem::TRef<ASwapChain>;

}  // namespace wkr::graphics::rhi
