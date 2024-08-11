#include "Platforms/DirectX12/Resource/DX12Resource.h"
#include <Platforms/DirectX12/Core/DX12TypeMap.h>
#include <Render/Core/RendererAPI.h>
#include <Render/Descriptor/DescriptorHeap.h>
#include <Platforms/DirectX12/Core/DX12SwapChain.h>

namespace wkr::render::dx12
{
  USwapChain::USwapChain(FSwapChainDesc& desc)
  {
    IDXGISwapChain* swapChain;
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.BufferCount = desc.m_bufferCount;
    swapChainDesc.BufferDesc.Width = desc.m_bufferDesc.m_width;
    swapChainDesc.BufferDesc.Height = desc.m_bufferDesc.m_height;
    swapChainDesc.BufferDesc.Format = ConvertEResourceFormat(desc.m_bufferDesc.m_format);
    swapChainDesc.BufferDesc.Scaling = ConvertEScaling(desc.m_bufferDesc.m_scaling);
    swapChainDesc.BufferDesc.ScanlineOrdering = ConvertEScanlineOrder(desc.m_bufferDesc.m_scanlineOrdering);

    swapChainDesc.BufferDesc.RefreshRate.Numerator = desc.m_bufferDesc.m_refreshRate.m_numerator;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = desc.m_bufferDesc.m_refreshRate.m_denominator;

    swapChainDesc.SampleDesc.Count = desc.m_sampleDesc.count;
    swapChainDesc.SampleDesc.Quality = desc.m_sampleDesc.quality;

    swapChainDesc.SwapEffect = ConvertESwapChainEffect(desc.m_swapEffect);
    swapChainDesc.Flags = (UINT)desc.m_flag;

    swapChainDesc.OutputWindow = *(static_cast<HWND*>(desc.m_window->GetNativeObject()));
    swapChainDesc.Windowed = desc.m_window->GetWindowed();

    HRESULT hr = UDX12Factory::GetFactory()->CreateSwapChain(
        desc.m_commandQueue->GetNativeObject(),
        &swapChainDesc,
        &swapChain);

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 SwapChain")
    WKR_CORE_LOG("Created DX12 SwapChain")

    m_swapChain = static_cast<IDXGISwapChain3*>(swapChain);
    m_frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    for(u32 i = 0; i < GetBufferCount(); i++)
    {
      ID3D12Resource* res;
      m_swapChain->GetBuffer(i, IID_PPV_ARGS(&res));
      m_textures.push_back(mem::TRef<UTexture2D>::Create(new UResource(res)));
      WKR_CORE_LOG("Binding Each Resource in Swap Chain");
    }

    auto& factory = URendererAPI::GetAbstractFactory();

    FDescriptorHeapDesc descriptorHeapDesc;
    descriptorHeapDesc.m_count = GetBufferCount();
    descriptorHeapDesc.m_type = EDescriptorHeapType::RTV;
    descriptorHeapDesc.m_flags = EDescriptorHeapFlags::None;

    m_descripHeap = factory.GetIDescriptorHeap()->Create(descriptorHeapDesc);

    std::vector<IResourceHandle> m_resources;
    std::transform(m_textures.begin(), m_textures.end(),
        std::back_inserter(m_resources), [](mem::TRef<UTexture2D> texture)
        {
          return texture->GetResource();
        });

    m_descripHeap->Bind(m_resources);

    FFenceDesc fenceDesc;
    fenceDesc.m_frameCount = GetBufferCount();
    fenceDesc.m_flag = EFenceFlag::None;

    m_fence = factory.GetIFence()->Create(fenceDesc);

    SetupEvents(desc.m_window);
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

  void USwapChain::SetupEvents(AWindowHandle window)
  {
    m_resizeEvent     = BIND_EVENT_2(USwapChain::WindowSizeEvent);
    m_fullscreenEvent = BIND_EVENT_1(USwapChain::FullscreenEvent);

    window->m_resizeEvent        += m_resizeEvent;
    window->m_setFullscreenEvent += m_fullscreenEvent;
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

  EResourceUsageF USwapChain::GetBufferUsage()
  {
    DXGI_SWAP_CHAIN_DESC desc;

    m_swapChain->GetDesc(&desc);
    return static_cast<EResourceUsageF>(desc.BufferUsage);
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
