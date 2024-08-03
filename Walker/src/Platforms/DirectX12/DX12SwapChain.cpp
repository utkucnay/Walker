#include <Platforms/DirectX12/Core/DX12SwapChain.h>

namespace wkr::render::dx12
{
  USwapChain::USwapChain(FSwapChainDesc& desc)
  {
    SetupEvents();
  }

  USwapChain::~USwapChain()
  {
    m_swapChain->Release();
    DestroyEvents();
  }

  void USwapChain::WindowSizeEvent(u32 width, u32 height)
  {
    m_swapChain->SetSourceSize(width, height);
  }

  void USwapChain::FullscreenEvent(b64 isTrue)
  {
    m_swapChain->SetFullscreenState(isTrue, nullptr);
  }

  void USwapChain::SwapBuffers()
  {
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    m_fence->FenceEvent(m_frameIndex);
  }

  void USwapChain::SetupEvents()
  {

  }

  void USwapChain::DestroyEvents()
  {

  }

  FModeDesc USwapChain::GetBufferDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    FModeDesc retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.m_height = desc.BufferDesc.Height;
    retDesc.m_width = desc.BufferDesc.Width;
    retDesc.m_format = static_cast<EResourceFormat>(desc.BufferDesc.Format);
    retDesc.m_scaling =
      static_cast<EScaling>(desc.BufferDesc.Scaling);
    retDesc.m_refreshRate.m_numerator = desc.BufferDesc.RefreshRate.Numerator;
    retDesc.m_refreshRate.m_denominator = desc.BufferDesc.RefreshRate.Denominator;
    retDesc.m_scanlineOrdering =static_cast<EScanlineOrder>(
        desc.BufferDesc.ScanlineOrdering);
    return retDesc;
  }

  FSample USwapChain::GetSampleDesc()
  {
    DXGI_SWAP_CHAIN_DESC desc;
    FSample retDesc;

    m_swapChain->GetDesc(&desc);
    retDesc.count = desc.SampleDesc.Count;
    retDesc.quality = desc.SampleDesc.Quality;
    return retDesc;
  }

  EResourceUsage USwapChain::GetBufferUsage()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<EResourceUsage>(desc.BufferUsage);
  }

  u32 USwapChain::GetBufferCount()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return desc.BufferCount;
  }

  ESwapChainEffect USwapChain::GetSwapEffect()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<ESwapChainEffect>(desc.SwapEffect);
  }

  ESwapChainFlag USwapChain::GetFlag()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<ESwapChainFlag>(desc.Flags);
  }

  void USwapChain::Present(u8 syncInterval, u8 flags)
  {
    m_swapChain->Present(syncInterval, flags);
  }
}
