#include <Platforms/DirectX12/DX12SwapChain.h>

namespace wkr::render
{
  DX12SwapChain::DX12SwapChain(
      mem::Visitor<CommandQueue>  commandQueue,
      const SwapChainDesc&        desc)
  {
    IDXGISwapChain* swapChain;
    mem::Scope<DXGI_SWAP_CHAIN_DESC> translatedDesc = TranslateDesc(desc);

    HRESULT hr = DX12Factory::GetFactory()->CreateSwapChain(
        static_cast<ID3D12CommandQueue*>(commandQueue->GetNativeHandle()),
        translatedDesc.Get(),
        &swapChain);

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create SwapChain");

    m_swapChain = static_cast<IDXGISwapChain3*>(swapChain);

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    desc.window->m_resizeEvent.AddListener(
        std::bind(
          &DX12SwapChain::ChangeWindowSize,
          this,
          std::placeholders::_1,
          std::placeholders::_2)
        );
  }

  DX12SwapChain::~DX12SwapChain()
  {
    m_swapChain->Release();
  }

  void DX12SwapChain::ChangeWindowSize(int width, int height)
  {
    m_swapChain->SetSourceSize(width, height);
  }

  void DX12SwapChain::SetFullscreen(mem::Visitor<Window> window)
  {
    m_swapChain->SetFullscreenState(window->GetFullscreen(), NULL);
  }

  void DX12SwapChain::SwapBuffers()
  {
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    //m_fence[m_frameIndex]->FenceEvent();
  }

  mem::Scope<DXGI_SWAP_CHAIN_DESC> DX12SwapChain::TranslateDesc(
      const SwapChainDesc& desc)
  {
    auto retDesc = mem::Scope<DXGI_SWAP_CHAIN_DESC>::Create();
    SwapChainDesc tDesc(desc);

    retDesc->BufferDesc.Width = tDesc.bufferDesc.width;
    retDesc->BufferDesc.Height = tDesc.bufferDesc.height;

    retDesc->BufferDesc.RefreshRate.Numerator =
      tDesc.bufferDesc.refreshRate.Numerator;
    retDesc->BufferDesc.RefreshRate.Denominator =
      tDesc.bufferDesc.refreshRate.Denominator;

    retDesc->BufferDesc.Format = static_cast<DXGI_FORMAT>(tDesc.bufferDesc.format);
    retDesc->BufferDesc.ScanlineOrdering =
      static_cast<DXGI_MODE_SCANLINE_ORDER>(tDesc.bufferDesc.scanlineOrdering);
    retDesc->BufferDesc.Scaling =
      static_cast<DXGI_MODE_SCALING>(tDesc.bufferDesc.scaling);

    retDesc->SampleDesc.Count = tDesc.sampleDesc.count;
    retDesc->SampleDesc.Quality = tDesc.sampleDesc.quality;

    retDesc->BufferUsage = static_cast<DXGI_USAGE>(tDesc.bufferUsage);
    retDesc->BufferCount = tDesc.bufferCount;
    retDesc->OutputWindow = *(static_cast<HWND*>(tDesc.window->GetNativeHandle()));
    retDesc->Windowed = tDesc.window->GetWindowed();
    retDesc->SwapEffect = static_cast<DXGI_SWAP_EFFECT>(tDesc.swapEffect);
    retDesc->Flags = static_cast<uint32_t>(tDesc.flag);

    return retDesc;
  }
}
