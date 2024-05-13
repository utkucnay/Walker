#pragma once

#include <Core/Window.h>

#include <Render/Core/Fence.h>
#include <Render/Core/Display.h>
#include <Render/Core/RendererStructs.h>

#include <Render/Command/Command.h>

#include <Render/Resource/Resource.h>
#include <Render/Resource/Texture2D.h>

#include <Render/Descriptor/DescriptorHeap.h>

#include <Render/ResourceView/RenderTargetView.h>

namespace wkr
{
  class UWindow;
}

namespace wkr::render
{
  class SwapChainBuilder;

  namespace view
  {
    class URenderTargetView;
  }

  class USwapChain
  {
  public:
    enum class Effect
    {
      Discard         = 0,
      Sequential      = 1,
      FlipSequential  = 3,
      FlipDiscard     = 4,
    };

    enum class Flag : u32
    {
      Nonprerotated                         = 1,
      AllowModeSwitch                       = 2,
      GDICompatible                         = 4,
      RestrictedContent                     = 8,
      RestrictSharedResourceDriver          = 16,
      DisplayOnly                           = 32,
      FrameLatencyWaitableObject            = 64,
      ForegroundLayer                       = 128,
      FullscreenVideo                       = 256,
      YuvVideo                              = 512,
      HWProtected                           = 1024,
      AllowTearing                          = 2048,
      RestrictedToAllHolographicDisplays    = 4096,
    };

    enum class VsyncDesc : u8
    {
      None            = 0,
      DoubleBuffering = 1,
      TripleBuffering = 2,
    };

  public:
    virtual ~USwapChain() {}

  public:
    virtual void WindowSizeEvent(u32 width, u32 height) = 0;
    virtual void FullscreenEvent(b64 isTrue) = 0;

    virtual void SwapBuffers() = 0;

    virtual void* GetNativeHandle() = 0;

    virtual u32                   GetBufferCount()  = 0;
    virtual FSample            GetSampleDesc()   = 0;
    virtual USwapChain::Flag      GetFlag()         = 0;
    virtual USwapChain::Effect    GetSwapEffect()   = 0;
    virtual UDisplay::FModeDesc   GetBufferDesc()   = 0;
    virtual rsc::IResource::Usage GetBufferUsage()  = 0;

    [[nodiscard]] virtual IFence& GetCurrentFence() { return m_fence.Get(); }

    virtual void Present(u8 syncInterval, u8 flags) = 0;

  public:
    virtual u32 GetFrameIndex() { return m_frameIndex; }
    [[nodiscard]] mem::Ref<view::URenderTargetView> GetCurrentRenderTarget()
    {
      return m_descripHeap->Get<view::URenderTargetView>(GetFrameIndex());
    }

  protected:
    WindowResizeEvent::Event        m_resizeEvent;
    WindowSetFullscreenEvent::Event m_fullscreenEvent;

    u32 m_frameIndex;

    mem::Scope<IFence> m_fence;
    mem::Ref<IDescriptorHeap> m_descripHeap;
  };

  class SwapChainBuilder : IBuilder<USwapChain>
  {
  public:
    SwapChainBuilder(
        mem::WeakRef<UWindow> window,
        mem::WeakRef<ICommandQueue> commandQueue);

  public:
    SwapChainBuilder& SetVsync(USwapChain::VsyncDesc desc);
    SwapChainBuilder& SetMSAA(u32 count, u32 quality);

  public:
    [[nodiscard]] USwapChain*            BuildRaw() override;
    [[nodiscard]] mem::Ref<USwapChain>   BuildRef() override;
    [[nodiscard]] mem::Scope<USwapChain> BuildScope() override;

  public:
    u32                         m_bufferCount{};
    FSample                  m_sampleDesc{};
    USwapChain::Flag            m_flag{};
    USwapChain::Effect          m_swapEffect{};
    mem::WeakRef<UWindow>       m_window{};
    UDisplay::FModeDesc         m_bufferDesc{};
    rsc::IResource::Usage       m_bufferUsage{};
    mem::WeakRef<ICommandQueue> m_commandQueue{};
  };
}
