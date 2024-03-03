#include <Platforms/DirectX12/DX12SwapChain.h>

namespace wkr::render
{
  DX12SwapChain::DX12SwapChain(
        mem::Visitor<CommandQueue>  commandQueue,
        mem::Visitor<SwapChainBuilder> scb)
  {
    IDXGISwapChain* swapChain;
    mem::Scope<DXGI_SWAP_CHAIN_DESC> translatedDesc = TranslateDesc(scb);

    HRESULT hr = DX12Factory::GetFactory()->CreateSwapChain(
        static_cast<ID3D12CommandQueue*>(commandQueue->GetNativeHandle()),
        translatedDesc.Get(),
        &swapChain);

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 SwapChain")
    WKR_CORE_LOG("Created DX12 SwapChain")

    m_swapChain = static_cast<IDXGISwapChain3*>(swapChain);

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    DescriptorHeapBuilder dhBuilder;
    dhBuilder
      .SetCount(GetBufferCount())
      .SetType(DescriptorHeap::Type::RTV)
      .SetFlags(DescriptorHeap::Flags::None);

    m_descripHeap = dhBuilder.BuildScope(scb->m_device);
    m_descripHeap->Bind(scb->m_device, GetBufferCount(), GetAllTexture2D());

    m_resizeEvent     = BIND_EVENT_2(DX12SwapChain::WindowSizeEvent);
    m_fullscreenEvent = BIND_EVENT_1(DX12SwapChain::FullscreenEvent);

    SetupEvents();
  }

  DX12SwapChain::~DX12SwapChain()
  {
    m_swapChain->Release();
    DestroyEvents();
  }

  void DX12SwapChain::WindowSizeEvent(int width, int height)
  {
    m_swapChain->SetSourceSize(width, height);
  }

  void DX12SwapChain::FullscreenEvent(bool isTrue)
  {
    m_swapChain->SetFullscreenState(isTrue, NULL);
  }

  void DX12SwapChain::SwapBuffers()
  {
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    //m_fence[m_frameIndex]->FenceEvent();
  }

  void DX12SwapChain::SetupEvents()
  {

  }

  void DX12SwapChain::DestroyEvents()
  {

  }

  ModeDesc DX12SwapChain::GetBufferDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    ModeDesc retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.height = desc.BufferDesc.Height;
    retDesc.width = desc.BufferDesc.Width;
    retDesc.format = static_cast<Format>(desc.BufferDesc.Format);
    retDesc.scaling =
      static_cast<Scaling>(desc.BufferDesc.Scaling);
    retDesc.refreshRate.Numerator = desc.BufferDesc.RefreshRate.Numerator;
    retDesc.refreshRate.Denominator = desc.BufferDesc.RefreshRate.Denominator;
    retDesc.scanlineOrdering =static_cast<ScanlineOrder>(
        desc.BufferDesc.ScanlineOrdering);
    return retDesc;
  }

  SampleDesc DX12SwapChain::GetSampleDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    SampleDesc retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.count = desc.SampleDesc.Count;
    retDesc.quality = desc.SampleDesc.Quality;
    return retDesc;
  }

  Usage DX12SwapChain::GetBufferUsage()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<Usage>(desc.BufferUsage);
  }

  uint32_t DX12SwapChain::GetBufferCount()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return desc.BufferCount;
  }

  SwapChain::Effect DX12SwapChain::GetSwapEffect()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<SwapChain::Effect>(desc.SwapEffect);
  }

  SwapChain::Flag DX12SwapChain::GetFlag()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<SwapChain::Flag>(desc.Flags);
  }

  std::vector<mem::Visitor<rsc::Texture2D>>
    DX12SwapChain::GetAllTexture2D()
  {
    std::vector<mem::Visitor<rsc::Texture2D>> ret;
    ID3D12Resource* res;

    for(uint32_t i = 0; i < GetBufferCount(); i++)
    {
      m_swapChain->GetBuffer(i, IID_PPV_ARGS(&res));
      ret.push_back(new rsc::DX12Texture2D(res));
    }
    return ret;
  }

  mem::Visitor<rsc::Texture2D> DX12SwapChain::GetTexture2D(uint32_t index)
  {
    ID3D12Resource* res;

    m_swapChain->GetBuffer(index, IID_PPV_ARGS(&res));
    auto ret = new rsc::DX12Texture2D(res);
    return ret;
  }

  mem::Scope<DXGI_SWAP_CHAIN_DESC> DX12SwapChain::TranslateDesc(
      mem::Visitor<SwapChainBuilder> scb)
  {
    auto retDesc = mem::Scope<DXGI_SWAP_CHAIN_DESC>::Create();

    retDesc->BufferDesc.Width   = scb->m_bufferDesc.width;
    retDesc->BufferDesc.Height  = scb->m_bufferDesc.height;

    retDesc->BufferDesc.RefreshRate.Numerator =
      scb->m_bufferDesc.refreshRate.Numerator;
    retDesc->BufferDesc.RefreshRate.Denominator =
      scb->m_bufferDesc.refreshRate.Denominator;

    retDesc->BufferDesc.Format = static_cast<DXGI_FORMAT>(scb->m_bufferDesc.format);

    retDesc->BufferDesc.ScanlineOrdering =
      static_cast<DXGI_MODE_SCANLINE_ORDER>(scb->m_bufferDesc.scanlineOrdering);
    retDesc->BufferDesc.Scaling =
      static_cast<DXGI_MODE_SCALING>(scb->m_bufferDesc.scaling);

    retDesc->SampleDesc.Count   = scb->m_sampleDesc.count;
    retDesc->SampleDesc.Quality = scb->m_sampleDesc.quality;

    retDesc->BufferUsage = static_cast<DXGI_USAGE>(scb->m_bufferUsage);
    retDesc->BufferCount = scb->m_bufferCount;
    retDesc->OutputWindow = *(static_cast<HWND*>(scb->m_window->GetNativeHandle()));
    retDesc->Windowed = scb->m_window->GetWindowed();
    retDesc->SwapEffect = static_cast<DXGI_SWAP_EFFECT>(scb->m_swapEffect);
    retDesc->Flags = static_cast<uint32_t>(scb->m_flag);

    return retDesc;
  }
}
