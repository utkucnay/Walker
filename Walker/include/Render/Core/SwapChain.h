#pragma once

#include <Render/Command/CommandQueue.h>
#include <Core/Window.h>

#include <Render/Core/Fence.h>
#include <Render/Core/Display.h>
#include <Render/Core/RendererStructs.h>

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
  namespace view
  {
    class URenderTargetView;
  }

  enum class ESwapChainEffect
  {
    Discard         = 0,
    Sequential      = 1,
    FlipSequential  = 3,
    FlipDiscard     = 4,
  };

  enum class ESwapChainFlag : u32
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

  enum class EVsyncDesc : u8
  {
    None            = 0,
    DoubleBuffering = 1,
    TripleBuffering = 2,
  };


  struct FSwapChainDesc
  {
    u32                           m_bufferCount{};
    FSample                       m_sampleDesc{};
    ESwapChainFlag                m_flag{};
    ESwapChainEffect              m_swapEffect{};
    mem::TWeakRef<UWindow>        m_window{};
    FModeDesc                     m_bufferDesc{};
    rsc::EResourceUsage           m_bufferUsage{};
    mem::TWeakRef<ICommandQueue>  m_commandQueue{};
  };

  class USwapChain
  {
  public:
    virtual ~USwapChain() {}

  public:
    virtual void WindowSizeEvent(u32 width, u32 height) = 0;
    virtual void FullscreenEvent(b64 isTrue) = 0;

    virtual void SwapBuffers() = 0;

    virtual void* GetNativeHandle() = 0;

    virtual u32                   GetBufferCount()  = 0;
    virtual FSample            GetSampleDesc()   = 0;
    virtual ESwapChainFlag      GetFlag()         = 0;
    virtual ESwapChainEffect    GetSwapEffect()   = 0;
    virtual FModeDesc   GetBufferDesc()   = 0;
    virtual rsc::EResourceUsage GetBufferUsage()  = 0;

    [[nodiscard]] virtual IFence& GetCurrentFence() { return m_fence.Get(); }

    virtual void Present(u8 syncInterval, u8 flags) = 0;

  public:
    virtual u32 GetFrameIndex() { return m_frameIndex; }
    [[nodiscard]] view::URenderTargetViewHandle GetCurrentRenderTarget()
    {
      return m_descripHeap->Get<view::URenderTargetView>(GetFrameIndex());
    }

  protected:
    WindowResizeEvent::FEvent        m_resizeEvent;
    WindowSetFullscreenEvent::FEvent m_fullscreenEvent;

    u32 m_frameIndex;

    mem::TScope<IFence> m_fence;
    mem::TRef<IDescriptorHeap> m_descripHeap;
  };

  using USwapChainHandle = mem::TRef<USwapChain>;
}
