#pragma once

#include <Render/SwapChain.h>
#include <Render/RenderTargetView.h>
#include <Render/Command.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12SwapChain : public SwapChain
  {
  public:
    DX12SwapChain(
        mem::Visitor<CommandQueue>  commandQueue,
        const SwapChainDesc&        desc);
    ~DX12SwapChain() override;

  public:
    void ChangeWindowSize(int width, int height) override;
    void SetFullscreen(mem::Visitor<Window> window) override;
    void SwapBuffers() override;
    void* GetNativeHandle() override { return m_swapChain; }

  private:
    mem::Scope<DXGI_SWAP_CHAIN_DESC> TranslateDesc(const SwapChainDesc& desc);

  private:
    IDXGISwapChain3*  m_swapChain;
    uint32_t          m_frameIndex;
  };
}
