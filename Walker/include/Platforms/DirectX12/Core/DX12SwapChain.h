#pragma once

#include "Graphics/RHI/Core/ASwapChain.h"

namespace wkr::graphics::rhi::dx12 {

class USwapChain : public ASwapChain {
 public:
  explicit USwapChain(const FSwapChainDesc& desc);
  ~USwapChain() override;

 public:
  void SwapBuffers() override final;
  NativeObject GetNativeObject() override final { return m_SwapChain; }
  FSwapChainDesc GetDesc() override final;
  void Present(u8 syncInterval, u8 flags) override final;

 private:
  IDXGISwapChain3* m_SwapChain;
  os::AWindowHandle m_Window;

 private:
  WindowResizeEvent::FEvent m_ResizeEvent;
  void WindowSizeEvent(u32 width, u32 height);

  WindowSetFullscreenEvent::FEvent m_FullscreenEvent;
  void FullscreenEvent(b64 isTrue);
};

}  // namespace wkr::graphics::rhi::dx12
