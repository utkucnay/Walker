#pragma once

#include <Core/Window.h>

#include <Render/Core/Fence.h>
#include <Render/Core/RendererStructs.h>

#include <Render/Command/Command.h>

#include <Render/Descriptor/DescriptorHeap.h>
#include <Render/Resource/Texture2D.h>

#include <Render/ResourceView/RenderTargetView.h>

namespace wkr
{
  class Window;
}

namespace wkr::render
{
  class SwapChainBuilder;

  namespace view
  {
    class RenderTargetView;
  }

  class SwapChain
  {
  public:
    enum class Effect
    {
      Discard         = 0,
      Sequential      = 1,
      FlipSequential  = 3,
      FlipDiscard     = 4,
    };

    enum class Flag : uint32_t
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

    enum class VsyncDesc : uint8_t
    {
      None            = 0,
      DoubleBuffering = 1,
      TripleBuffering = 2,
    };

  public:
    virtual ~SwapChain() {}

  public:
    virtual void WindowSizeEvent(int width, int height) = 0;
    virtual void FullscreenEvent(bool isTrue) = 0;

    virtual void SwapBuffers() = 0;

    virtual void* GetNativeHandle() = 0;

    virtual ModeDesc          GetBufferDesc() = 0;
    virtual SampleDesc        GetSampleDesc() = 0;
    virtual Usage             GetBufferUsage() = 0;
    virtual uint32_t          GetBufferCount() = 0;
    virtual SwapChain::Effect GetSwapEffect() = 0;
    virtual SwapChain::Flag   GetFlag() = 0;

  public:
    virtual uint32_t GetFrameIndex() { return m_frameIndex; }
    view::RenderTargetView* GetCurrentRenderTarget()
    {
      return m_descripHeap->Get<view::RenderTargetView>(GetFrameIndex());
    }

  protected:
    WindowResizeEvent::Event        m_resizeEvent;
    WindowSetFullscreenEvent::Event m_fullscreenEvent;

    uint32_t m_frameIndex;

    std::vector<mem::Scope<Fence>> m_fence;

    mem::Scope<DescriptorHeap> m_descripHeap;
  };

  class SwapChainBuilder : Builder<SwapChain>
  {
  public:
    SwapChainBuilder();

  public:
    SwapChainBuilder& SetCommandQueue(CommandQueue* commandQueue);
    SwapChainBuilder& SetVsync(SwapChain::VsyncDesc desc);
    SwapChainBuilder& SetMSAA(uint32_t count, uint32_t quality);
    SwapChainBuilder& SetDevice(Device* device);
    SwapChainBuilder& SetWindow(Window* window);

  public:
    SwapChain*            BuildRaw() override;
    mem::Ref<SwapChain>   BuildRef() override;
    mem::Scope<SwapChain> BuildScope() override;

  public:
    Device*           m_device{};
    CommandQueue*     m_commandQueue{};
    ModeDesc          m_bufferDesc{};
    SampleDesc        m_sampleDesc{};
    Usage             m_bufferUsage{};
    uint32_t          m_bufferCount{};
    Window*           m_window{};
    SwapChain::Effect m_swapEffect{};
    SwapChain::Flag   m_flag{};

    friend class SwapChain;
  };
}
