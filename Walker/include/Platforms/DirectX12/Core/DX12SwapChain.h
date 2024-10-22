#pragma once

#include "Graphics/Core/ASwapChain.h"

namespace wkr::render::dx12
{
  class USwapChain : public ASwapChain
  {
  public:
    USwapChain(FSwapChainDesc& desc);
    ~USwapChain() override;

  public:
    void WindowSizeEvent(u32 width, u32 height) override final;
    void FullscreenEvent(b64 isTrue) override final;

    void SwapBuffers() override final;

    NativeObject GetNativeObject() override final { return m_swapChain; }

    u32                   GetBufferCount()  override final;
    FSample            GetSampleDesc()   override final;
    ESwapChainFlag      GetFlag()         override final;
    ESwapChainEffect    GetSwapEffect()   override final;
    FModeDesc   GetBufferDesc()   override final;
    EResourceUsageF GetBufferUsage()  override final;

    void Present(u8 syncInterval, u8 flags) override final;

    void SetupEvents(AWindowHandle window);
    void DestroyEvents();

  private:
    IDXGISwapChain3*  m_swapChain;

    std::vector<mem::TRef<UTexture2D>> m_textures;
  };
}
