#pragma once

#include <Render/Core/SwapChain.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class DX12SwapChain : public SwapChain
  {
  public:
    DX12SwapChain(
        SwapChainBuilder* scb);
    ~DX12SwapChain() override;

  public:
    void WindowSizeEvent(int width, int height) override final;
    void FullscreenEvent(bool isTrue) override final;

    void SwapBuffers() override final;

    void* GetNativeHandle() override final { return m_swapChain; }

    ModeDesc          GetBufferDesc()   override final;
    SampleDesc        GetSampleDesc()   override final;
    Usage             GetBufferUsage()  override final;
    uint32_t          GetBufferCount()  override final;
    SwapChain::Effect GetSwapEffect()   override final;
    SwapChain::Flag   GetFlag()         override final;

    void Present(uint8_t syncInterval, uint8_t flags) override final;

  private:
    mem::Scope<DXGI_SWAP_CHAIN_DESC> TranslateDesc(
        SwapChainBuilder* scb);
    void SetupEvents();
    void DestroyEvents();

  private:
    IDXGISwapChain3*  m_swapChain;
    std::vector<mem::Ref<rsc::Texture2D>> m_textures;
  };
}
