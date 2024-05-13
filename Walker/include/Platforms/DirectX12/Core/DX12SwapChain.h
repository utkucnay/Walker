#pragma once

#include <Render/Core/SwapChain.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class UDX12SwapChain : public USwapChain
  {
  public:
    UDX12SwapChain(SwapChainBuilder& scb);
    ~UDX12SwapChain() override;

  public:
    void WindowSizeEvent(u32 width, u32 height) override final;
    void FullscreenEvent(b64 isTrue) override final;

    void SwapBuffers() override final;

    NativeHandle GetNativeHandle() override final { return m_swapChain; }

    u32                   GetBufferCount()  override final;
    FSample            GetSampleDesc()   override final;
    USwapChain::Flag      GetFlag()         override final;
    USwapChain::Effect    GetSwapEffect()   override final;
    UDisplay::FModeDesc   GetBufferDesc()   override final;
    rsc::IResource::Usage GetBufferUsage()  override final;

    void Present(u8 syncInterval, u8 flags) override final;

  private:
    mem::Scope<DXGI_SWAP_CHAIN_DESC> TranslateDesc(SwapChainBuilder& scb);
    void SetupEvents();
    void DestroyEvents();

  private:
    IDXGISwapChain3*  m_swapChain;

    std::vector<mem::Ref<rsc::ITexture2D>> m_textures;
  };
}
