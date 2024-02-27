#pragma once

#include <Core/Window.h>

#include <Render/Command.h>
#include <Render/RendererStructs.h>

namespace wkr
{
  class Window;
}

namespace wkr::render
{
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
    virtual ~SwapChain() = 0;

  public:
    virtual void ChangeWindowSize(int width, int height) = 0;
    virtual void SetFullscreen(mem::Visitor<Window> window) = 0;
    virtual void SwapBuffers() = 0;
    virtual void* GetNativeHandle() = 0;

  protected:
    std::vector<mem::Scope<Fence>> m_fence;
  };

  struct SwapChainDesc
  {
    ModeDesc          bufferDesc;
    SampleDesc        sampleDesc;
    Usage             bufferUsage;
    uint32_t          bufferCount;
    Window*           window;
    SwapChain::Effect swapEffect;
    SwapChain::Flag   flag;
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

  private:
    Device*       m_device;
    CommandQueue* m_commandQueue;
    SwapChainDesc m_swapChainDesc;
  };

  class SwapChainFactory : Factory<
                           SwapChain,
                           mem::Visitor<CommandQueue>,
                           const SwapChainDesc&>
  {
  public:
    SwapChain*              CreateFactoryRaw  (
        mem::Visitor<CommandQueue>  commandQueue,
        const SwapChainDesc&        desc) override;
    mem::Ref<SwapChain>     CreateFactoryRef  (
        mem::Visitor<CommandQueue>  commandQueue,
        const SwapChainDesc&        desc) override;
    mem::Scope<SwapChain>   CreateFactoryScope(
        mem::Visitor<CommandQueue>  commandQueue,
        const SwapChainDesc&        desc) override;
  };
}
