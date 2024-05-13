#include <Render/Core/SwapChain.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  //Builder
  SwapChainBuilder::SwapChainBuilder(
      mem::WeakRef<UWindow> window,
      mem::WeakRef<ICommandQueue> commandQueue)
  {
    auto rWindow = window.Lock();

    m_window = window;
    m_bufferDesc.m_width = rWindow->GetWidth();
    m_bufferDesc.m_height = rWindow->GetHeight();

    m_commandQueue = commandQueue;

    m_bufferDesc.m_format = rsc::IResource::Format::R8G8B8A8_UNORM;
    m_bufferUsage         = rsc::IResource::Usage::RENDER_TARGET_OUTPUT;
    m_swapEffect          = USwapChain::Effect::FlipDiscard;
  }

  SwapChainBuilder& SwapChainBuilder::SetVsync(USwapChain::VsyncDesc desc)
  {
    switch (desc)
    {
      case USwapChain::VsyncDesc::None:
        m_bufferCount = 2;
        m_bufferDesc.m_refreshRate.m_numerator = 0;
        m_bufferDesc.m_refreshRate.m_denominator = 1;
        break;
      case USwapChain::VsyncDesc::DoubleBuffering:
        m_bufferCount = 2;
        WKR_CORE_WARNING("Didn't Support Double Buffering");
        m_bufferDesc.m_refreshRate.m_numerator = 144;
        m_bufferDesc.m_refreshRate.m_denominator = 1;
        break;
      case USwapChain::VsyncDesc::TripleBuffering:
        m_bufferCount = 3;
        WKR_CORE_WARNING("Didn't Support Triple Buffering");
        m_bufferDesc.m_refreshRate.m_numerator = 144;
        m_bufferDesc.m_refreshRate.m_denominator = 1;
        break;
    }
    return *this;
  }

  SwapChainBuilder& SwapChainBuilder::SetMSAA(u32 count, u32 quality)
  {
    m_sampleDesc.count = count;
    m_sampleDesc.quality = quality;
    return *this;
  }

  USwapChain* SwapChainBuilder::BuildRaw()
  {
    return RendererAPI::GetAbstractFactory().GetSwapChainFactory()
      ->CreateRaw(*this);
  }

  mem::Ref<USwapChain> SwapChainBuilder::BuildRef()
  {
    return RendererAPI::GetAbstractFactory().GetSwapChainFactory()
      ->CreateRef(*this);
  }

  mem::Scope<USwapChain> SwapChainBuilder::BuildScope()
  {
    return RendererAPI::GetAbstractFactory().GetSwapChainFactory()
      ->CreateScope(*this);
  }
}
