#include "Platforms/DirectX12/Core/DX12SwapChain.h"
#include "Core/Base.h"
#include "Graphics/Core/GraphicsType.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Core/ASwapChain.h"
#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "OS/Window/AWindow.h"
#include "Platforms/DirectX12/Core/DX12Factory.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"
#include "Platforms/DirectX12/Resource/DX12Resource.h"

namespace wkr::graphics::rhi::dx12 {

USwapChain::USwapChain(FSwapChainDesc& desc) {
  m_Window = desc.Window;
  IDXGISwapChain* swapChain;
  os::FWindowDesc windowDesc = m_Window->GetDesc();

  m_BufferCount = desc.BufferCount;

  DXGI_SWAP_CHAIN_DESC swapChainDesc = {
      .BufferDesc =
          {
              .Width = desc.BufferDesc.Width,
              .Height = desc.BufferDesc.Height,
              .RefreshRate =
                  {
                      .Numerator = desc.BufferDesc.RefreshRate.Numerator,
                      .Denominator = desc.BufferDesc.RefreshRate.Denominator,
                  },
              .Format =
                  wkrtodx12::ConvertEResourceFormat(desc.BufferDesc.Format),
              .ScanlineOrdering = wkrtodx12::ConvertEScanlineOrder(
                  desc.BufferDesc.ScanlineOrdering),
              .Scaling = wkrtodx12::ConvertEScaling(desc.BufferDesc.Scaling),
          },
      .SampleDesc = {.Count = desc.SampleDesc.Count,
                     .Quality = desc.SampleDesc.Quality},
      .BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
      .BufferCount = desc.BufferCount,
      .OutputWindow = *(static_cast<HWND*>(desc.Window->GetNativeObject())),
      .Windowed = (int)windowDesc.Windowed,
      .SwapEffect = wkrtodx12::ConvertESwapChainEffect(desc.SwapEffect),
      .Flags = wkrtodx12::ConvertESwapChainF(desc.Flag),
  };

  HRESULT hr = UDX12Factory::GetFactory()->CreateSwapChain(
      desc.m_commandQueue->GetNativeObject(), &swapChainDesc, &swapChain);

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 SwapChain")
  WKR_CORE_LOG("Created DX12 SwapChain")

  m_SwapChain = static_cast<IDXGISwapChain3*>(swapChain);
  m_FrameIndex = m_SwapChain->GetCurrentBackBufferIndex();

  std::vector<IResourceHandle> resources;

  for (u32 i = 0; i < GetBufferCount(); i++) {
    ID3D12Resource* res;
    m_SwapChain->GetBuffer(i, IID_PPV_ARGS(&res));
    resources.push_back(new UResource(res));
    WKR_CORE_LOG("Binding Each Resource in Swap Chain");
  }

  auto& factory = UGraphicsAPI::GetAbstractFactory();

  FDescriptorHeapDesc descriptorHeapDesc = {
    .Count = GetBufferCount(),
    .Type = EDescriptorHeapType::kRTV,
    .Flag = EDescriptorHeapF::kNone,
  };

  m_DescripHeap = factory.GetADescriptorHeap()->Create(descriptorHeapDesc);

  m_DescripHeap->Bind(resources);

  m_ResizeEvent = BIND_EVENT_2(USwapChain::WindowSizeEvent);
  m_FullscreenEvent = BIND_EVENT_1(USwapChain::FullscreenEvent);

  m_Window->ResizeEvent += m_ResizeEvent;
  m_Window->SetFullscreenEvent += m_FullscreenEvent;
}

USwapChain::~USwapChain() {
  m_SwapChain->Release();

  //m_Window->ResizeEvent -= m_ResizeEvent;
  //m_Window->SetFullscreenEvent -= m_FullscreenEvent;
}

void USwapChain::WindowSizeEvent(u32 width, u32 height) {
  m_SwapChain->SetSourceSize(width, height);
}

void USwapChain::FullscreenEvent(b64 isTrue) {
  m_SwapChain->SetFullscreenState(isTrue, nullptr);
}

void USwapChain::SwapBuffers() {
  m_FrameIndex = m_SwapChain->GetCurrentBackBufferIndex();
}

FSwapChainDesc USwapChain::GetDesc() {
  DXGI_SWAP_CHAIN_DESC nDesc;
  m_SwapChain->GetDesc(&nDesc);

  FSwapChainDesc desc = {
      .BufferCount = nDesc.BufferCount,
      .SampleDesc =
          {
              .Count = nDesc.SampleDesc.Count,
              .Quality = nDesc.SampleDesc.Quality,
          },
      .Flag = ESwapChainF::kNone, //dx12towkr::ConvertESwapChainF(nDesc.Flags),
      .SwapEffect = dx12towkr::ConvertESwapChainEffect(nDesc.SwapEffect),
      .Window = m_Window,
      .BufferDesc =
          {
              .Width = nDesc.BufferDesc.Width,
              .Height = nDesc.BufferDesc.Height,
              .RefreshRate = {.Numerator =
                                  nDesc.BufferDesc.RefreshRate.Numerator,
                              .Denominator =
                                  nDesc.BufferDesc.RefreshRate.Denominator},
              .ScanlineOrdering = dx12towkr::ConvertEScanlineOrder(
                  nDesc.BufferDesc.ScanlineOrdering),
              .Scaling = dx12towkr::ConvertEScaling(nDesc.BufferDesc.Scaling),
              .Format =
                  dx12towkr::ConvertEResourceFormat(nDesc.BufferDesc.Format),
          },
      .m_bufferUsage = dx12towkr::ConvertEResourceUsage(nDesc.BufferUsage),
  };

  return desc;
}

void USwapChain::Present(u8 syncInterval, u8 flags) {
  HRESULT hr = m_SwapChain->Present(syncInterval, flags);

  WKR_CORE_ERROR_COND(FAILED(hr), "Swapchain Present Not Work")
}

}  // namespace wkr::graphics::rhi::dx12
