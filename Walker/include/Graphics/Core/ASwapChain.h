#pragma once

#include "Core/AWindow.h"
#include "Graphics/Command/ICommandQueue.h"
#include "Graphics/Core/GraphicsType.h"
#include "Graphics/Core/IFence.h"
#include "Graphics/Descriptor/ADescriptorHeap.h"
#include "Graphics/Resource/ResourceType.h"

namespace wkr {

class AWindow;
using AWindowHandle = mem::TRef<AWindow>;

}  // namespace wkr

namespace wkr::render {

struct FSwapChainDesc {
  u32 m_bufferCount;
  FSample m_sampleDesc;
  ESwapChainFlag m_flag;
  ESwapChainEffect m_swapEffect;
  AWindowHandle m_window;
  FModeDesc m_bufferDesc;
  EResourceUsageF m_bufferUsage;
  ICommandQueueHandle m_commandQueue;
};

class ASwapChain {
 public:
  virtual ~ASwapChain() = default;

 public:
  virtual void WindowSizeEvent(u32 width, u32 height) = 0;
  virtual void FullscreenEvent(b64 isTrue) = 0;

  virtual void SwapBuffers() = 0;

  virtual NativeObject GetNativeObject() = 0;

  virtual u32 GetBufferCount() = 0;
  virtual FSample GetSampleDesc() = 0;
  virtual FModeDesc GetBufferDesc() = 0;
  virtual ESwapChainFlag GetFlag() = 0;
  virtual ESwapChainEffect GetSwapEffect() = 0;
  virtual EResourceUsageF GetBufferUsage() = 0;

  [[nodiscard]] virtual IFence& GetCurrentFence() { return m_fence.Get(); }

  virtual void Present(u8 syncInterval, u8 flags) = 0;

 public:
  virtual u32 GetFrameIndex() { return m_frameIndex; }

  [[nodiscard]] ARenderTargetViewHandle GetCurrentRenderTarget() {
    return m_descripHeap->Get<ARenderTargetView>(GetFrameIndex());
  }

 protected:
  WindowResizeEvent::FEvent m_resizeEvent;
  WindowSetFullscreenEvent::FEvent m_fullscreenEvent;

  u32 m_frameIndex;

  mem::TScope<IFence> m_fence;
  IDescriptorHeapHandle m_descripHeap;
};

using ASwapChainHandle = mem::TRef<ASwapChain>;

}  // namespace wkr::render
