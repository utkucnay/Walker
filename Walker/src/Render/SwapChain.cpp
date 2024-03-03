#include <Render/Core/SwapChain.h>
#include <Render/Core/RendererMakro.h>

namespace wkr::render
{
  //Builder
  SwapChainBuilder::SwapChainBuilder()
  {
    m_bufferDesc.format = Format::R8G8B8A8_UNORM;
    m_bufferUsage       = Usage::RENDER_TARGET_OUTPUT;
    m_swapEffect        = SwapChain::Effect::FlipDiscard;
  }

  SwapChainBuilder& SwapChainBuilder::SetCommandQueue(
      CommandQueue* commandQueue)
  {
    m_commandQueue = commandQueue;
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetVsync(SwapChain::VsyncDesc desc)
  {
    switch (desc)
    {
      case SwapChain::VsyncDesc::None:
        m_bufferCount = 2;
        m_bufferDesc.refreshRate.Numerator = 0;
        m_bufferDesc.refreshRate.Denominator = 1;
        break;
      case SwapChain::VsyncDesc::DoubleBuffering:
        m_bufferCount = 2;
        WKR_CORE_WARNING("Didn't Support Double Buffering");
        m_bufferDesc.refreshRate.Numerator = 144;
        m_bufferDesc.refreshRate.Denominator = 1;
        break;
      case SwapChain::VsyncDesc::TripleBuffering:
        m_bufferCount = 3;
        WKR_CORE_WARNING("Didn't Support Triple Buffering");
        m_bufferDesc.refreshRate.Numerator = 144;
        m_bufferDesc.refreshRate.Denominator = 1;
        break;
    }
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetMSAA(uint32_t count, uint32_t quality)
  {
    m_sampleDesc.count = count;
    m_sampleDesc.quality = quality;
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetDevice(Device* device)
  {
    m_device = device;
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetWindow(Window* window)
  {
    m_bufferDesc.width  = window->GetWidth();
    m_bufferDesc.height = window->GetHeight();
    m_window = window;
    return *this;
  }

  SwapChain* SwapChainBuilder::BuildRaw()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryRaw(
          m_commandQueue,
          this
          );
  }

  mem::Ref<SwapChain> SwapChainBuilder::BuildRef()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryRef(
          m_commandQueue,
          this
          );
  }

  mem::Scope<SwapChain> SwapChainBuilder::BuildScope()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryScope(
          m_commandQueue,
          this
          );
  }

  //Factory
  SwapChain* SwapChainFactory::CreateFactoryRaw(
      mem::Visitor<CommandQueue> commandQueue,
      mem::Visitor<SwapChainBuilder> scb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12SwapChain(
          commandQueue,
          scb
        ))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<SwapChain> SwapChainFactory::CreateFactoryRef(
      mem::Visitor<CommandQueue> commandQueue,
      mem::Visitor<SwapChainBuilder> scb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12SwapChain>::Create(
          commandQueue,
          scb
        ))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<SwapChain> SwapChainFactory::CreateFactoryScope(
      mem::Visitor<CommandQueue> commandQueue,
      mem::Visitor<SwapChainBuilder> scb)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12SwapChain>::Create(
          commandQueue,
          scb
        ))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
