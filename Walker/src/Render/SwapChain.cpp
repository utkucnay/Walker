#include <Render/SwapChain.h>
#include <Render/RendererMakro.h>

namespace wkr::render
{
  SwapChain::~SwapChain()
  {

  }

  //Builder
  SwapChainBuilder::SwapChainBuilder()
  {
    m_swapChainDesc = {};
    m_swapChainDesc.bufferDesc.format = Format::R8G8B8A8_UNORM;
    m_swapChainDesc.bufferUsage = Usage::RENDER_TARGET_OUTPUT;
    m_swapChainDesc.swapEffect = SwapChain::Effect::FlipDiscard;
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
        m_swapChainDesc.bufferCount = 2;
        m_swapChainDesc.bufferDesc.refreshRate.Numerator = 0;
        m_swapChainDesc.bufferDesc.refreshRate.Denominator = 1;
        break;
      case SwapChain::VsyncDesc::DoubleBuffering:
        m_swapChainDesc.bufferCount = 2;
        WKR_CORE_LOG("Didn't Support Double Buffering");
        m_swapChainDesc.bufferDesc.refreshRate.Numerator = 144;
        m_swapChainDesc.bufferDesc.refreshRate.Denominator = 1;
        break;
      case SwapChain::VsyncDesc::TripleBuffering:
        m_swapChainDesc.bufferCount = 3;
        WKR_CORE_LOG("Didn't Support Triple Buffering");
        m_swapChainDesc.bufferDesc.refreshRate.Numerator = 144;
        m_swapChainDesc.bufferDesc.refreshRate.Denominator = 1;
        break;
    }
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetMSAA(uint32_t count, uint32_t quality)
  {
    m_swapChainDesc.sampleDesc.count = count;
    m_swapChainDesc.sampleDesc.quality = quality;
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetDevice(Device* device)
  {
    m_device = device;
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetWindow(Window* window)
  {
    m_swapChainDesc.bufferDesc.width = window->GetWidth();
    m_swapChainDesc.bufferDesc.height = window->GetHeight();
    m_swapChainDesc.window = window;
    return *this;
  }

  SwapChain* SwapChainBuilder::BuildRaw()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryRaw(m_commandQueue, m_swapChainDesc);
  }

  mem::Ref<SwapChain> SwapChainBuilder::BuildRef()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryRef(m_commandQueue, m_swapChainDesc);
  }

  mem::Scope<SwapChain> SwapChainBuilder::BuildScope()
  {
    return mem::Scope<SwapChainFactory>::Create()
      ->CreateFactoryScope(m_commandQueue, m_swapChainDesc);
  }

  //Factory
  SwapChain* SwapChainFactory::CreateFactoryRaw(
      CommandQueue* commandQueue,
      const SwapChainDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12SwapChain(commandQueue, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<SwapChain> SwapChainFactory::CreateFactoryRef(
      CommandQueue* commandQueue,
      const SwapChainDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12SwapChain>::Create(commandQueue, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<SwapChain> SwapChainFactory::CreateFactoryScope(
      CommandQueue* commandQueue,
      const SwapChainDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12SwapChain>::Create(commandQueue, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
