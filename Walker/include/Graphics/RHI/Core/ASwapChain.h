#pragma once

#include "Graphics/Core/GraphicsType.h"
#include "Graphics/RHI/Command/ICommandQueue.h"
#include "Graphics/RHI/Descriptor/ADescriptorHeap.h"
#include "Graphics/RHI/Resource/ResourceType.h"
#include "Graphics/Resource/View/URenderTargetView.h"
#include "OS/Window/AWindow.h"

namespace wkr::graphics::rhi {

struct WALKER_API FSwapChainDesc {
  u32 BufferCount = 0;
  FSample SampleDesc = {0, 0};
  ESwapChainF Flag = ESwapChainF::kNone;
  ESwapChainEffect SwapEffect = ESwapChainEffect::kDiscard;
  os::AWindowHandle Window = {};
  FModeDesc BufferDesc = {};
  EResourceUsageF m_bufferUsage = EResourceUsageF::kCPU_ACCESS_NONE;
  ICommandQueueHandle m_commandQueue = nullptr;
};

class WALKER_API ASwapChain {
 public:
  virtual ~ASwapChain() = default;

 public:
  virtual void SwapBuffers() = 0;

  virtual NativeObject GetNativeObject() = 0;
  virtual FSwapChainDesc GetDesc() = 0;

  virtual void Present(u8 syncInterval, u8 flags) = 0;

 public:
  u32 GetFrameIndex() { return m_FrameIndex; }
  u32 GetBufferCount() const { return m_BufferCount; }

  [[nodiscard]] URenderTargetView GetCurrentRenderTarget() {
    return URenderTargetView(m_DescripHeap->GetResourceView(m_FrameIndex));
  }

 protected:
  u32 m_FrameIndex;
  u32 m_BufferCount;
  ADescriptorHeapHandle m_DescripHeap;
};

using ASwapChainHandle = wkr::mem::TRef<ASwapChain>;

}  // namespace wkr::graphics::rhi
