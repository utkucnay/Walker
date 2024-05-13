#include <Platforms/DirectX12/Core/DX12SwapChain.h>

namespace wkr::render
{
  UDX12SwapChain::UDX12SwapChain(SwapChainBuilder& scb)
  {
    IDXGISwapChain* swapChain;
    mem::Scope<DXGI_SWAP_CHAIN_DESC> translatedDesc = TranslateDesc(scb);

    HRESULT hr = UDX12Factory::GetFactory()->CreateSwapChain(
        static_cast<ID3D12CommandQueue*>(scb.m_commandQueue.Lock()->GetNativeHandle()),
        translatedDesc.GetPtr(),
        &swapChain);

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 SwapChain")
    WKR_CORE_LOG("Created DX12 SwapChain")

    m_swapChain = static_cast<IDXGISwapChain3*>(swapChain);

    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    for(uint32_t i = 0; i < GetBufferCount(); i++)
    {
      ID3D12Resource* res;
      m_swapChain->GetBuffer(i, IID_PPV_ARGS(&res));
      m_textures.push_back(mem::Ref<rsc::UDX12Texture2D>::Create(res));
      WKR_CORE_LOG("Binding Each Resource in Swap Chain");
    }

    DescriptorHeapBuilder dhBuilder;
    dhBuilder
      .SetCount(GetBufferCount())
      .SetType(IDescriptorHeap::Type::RTV)
      .SetFlags(IDescriptorHeap::Flags::None);

    m_descripHeap = dhBuilder.BuildRef();

    std::vector<mem::WeakRef<rsc::IResource>> m_weakTextures;
    std::transform(m_textures.begin(), m_textures.end(),
        std::back_inserter(m_weakTextures), [](mem::Ref<rsc::ITexture2D> res)
        {
          return res;
        });

    m_descripHeap->Bind(m_weakTextures);

    FenceBuilder fBuilder;
    fBuilder
      .SetFenceFlag(IFence::Flag::None)
      .SetFrameCount(GetBufferCount());

    m_fence = fBuilder.BuildScope();

    m_resizeEvent     = BIND_EVENT_2(UDX12SwapChain::WindowSizeEvent);
    m_fullscreenEvent = BIND_EVENT_1(UDX12SwapChain::FullscreenEvent);

    scb.m_window.Lock()->m_resizeEvent        += m_resizeEvent;
    scb.m_window.Lock()->m_setFullscreenEvent += m_fullscreenEvent;

    SetupEvents();
  }

  UDX12SwapChain::~UDX12SwapChain()
  {
    m_swapChain->Release();
    DestroyEvents();
  }

  void UDX12SwapChain::WindowSizeEvent(u32 width, u32 height)
  {
    m_swapChain->SetSourceSize(width, height);
  }

  void UDX12SwapChain::FullscreenEvent(b64 isTrue)
  {
    m_swapChain->SetFullscreenState(isTrue, NULL);
  }

  void UDX12SwapChain::SwapBuffers()
  {
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    m_fence->FenceEvent(m_frameIndex);
  }

  void UDX12SwapChain::SetupEvents()
  {

  }

  void UDX12SwapChain::DestroyEvents()
  {

  }

  UDisplay::FModeDesc UDX12SwapChain::GetBufferDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    UDisplay::FModeDesc retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.m_height = desc.BufferDesc.Height;
    retDesc.m_width = desc.BufferDesc.Width;
    retDesc.m_format = static_cast<rsc::IResource::Format>(desc.BufferDesc.Format);
    retDesc.m_scaling =
      static_cast<UDisplay::Scaling>(desc.BufferDesc.Scaling);
    retDesc.m_refreshRate.m_numerator = desc.BufferDesc.RefreshRate.Numerator;
    retDesc.m_refreshRate.m_denominator = desc.BufferDesc.RefreshRate.Denominator;
    retDesc.m_scanlineOrdering =static_cast<UDisplay::ScanlineOrder>(
        desc.BufferDesc.ScanlineOrdering);
    return retDesc;
  }

  FSample UDX12SwapChain::GetSampleDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    FSample retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.count = desc.SampleDesc.Count;
    retDesc.quality = desc.SampleDesc.Quality;
    return retDesc;
  }

  rsc::IResource::Usage UDX12SwapChain::GetBufferUsage()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<rsc::IResource::Usage>(desc.BufferUsage);
  }

  u32 UDX12SwapChain::GetBufferCount()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return desc.BufferCount;
  }

  USwapChain::Effect UDX12SwapChain::GetSwapEffect()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<USwapChain::Effect>(desc.SwapEffect);
  }

  USwapChain::Flag UDX12SwapChain::GetFlag()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<USwapChain::Flag>(desc.Flags);
  }

  void UDX12SwapChain::Present(u8 syncInterval, u8 flags)
  {
    m_swapChain->Present(syncInterval, flags);
  }

  mem::Scope<DXGI_SWAP_CHAIN_DESC> UDX12SwapChain::TranslateDesc(SwapChainBuilder& scb)
  {
    auto retDesc = mem::Scope<DXGI_SWAP_CHAIN_DESC>::Create();
    auto lWindow = scb.m_window.Lock();

    retDesc->BufferDesc.Width   = scb.m_bufferDesc.m_width;
    retDesc->BufferDesc.Height  = scb.m_bufferDesc.m_height;

    retDesc->BufferDesc.RefreshRate.Numerator =
      scb.m_bufferDesc.m_refreshRate.m_numerator;
    retDesc->BufferDesc.RefreshRate.Denominator =
      scb.m_bufferDesc.m_refreshRate.m_denominator;

    retDesc->BufferDesc.Format = static_cast<DXGI_FORMAT>(scb.m_bufferDesc.m_format);

    retDesc->BufferDesc.ScanlineOrdering =
      static_cast<DXGI_MODE_SCANLINE_ORDER>(scb.m_bufferDesc.m_scanlineOrdering);
    retDesc->BufferDesc.Scaling =
      static_cast<DXGI_MODE_SCALING>(scb.m_bufferDesc.m_scaling);

    retDesc->SampleDesc.Count   = scb.m_sampleDesc.count;
    retDesc->SampleDesc.Quality = scb.m_sampleDesc.quality;

    retDesc->BufferUsage = static_cast<DXGI_USAGE>(scb.m_bufferUsage);
    retDesc->BufferCount = scb.m_bufferCount;
    retDesc->OutputWindow = *(static_cast<HWND*>(lWindow->GetNativeHandle()));
    retDesc->Windowed = lWindow->GetWindowed();
    retDesc->SwapEffect = static_cast<DXGI_SWAP_EFFECT>(scb.m_swapEffect);
    retDesc->Flags = static_cast<uint32_t>(scb.m_flag);

    return retDesc;
  }
}
