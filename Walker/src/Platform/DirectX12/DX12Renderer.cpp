#include "Platforms/DirectX12/DX12Adapter.h"
#include "Platforms/DirectX12/DX12Device.h"
#include "Platforms/DirectX12/DX12Factory.h"
#include <Platforms/DirectX12/DX12Renderer.h>

extern "C" { __declspec(dllexport) extern const UINT D3D12SDKVersion = 611;}

extern "C" { __declspec(dllexport) extern const char* D3D12SDKPath = u8".\\D3D12\\"; }

namespace wkr::render
{
  DX12Renderer::DX12Renderer(Window* window)
  {
    HWND* hwnd = (HWND*)window->GetNativeHandle();

    HRESULT hr;

    DX12Factory::Init();

    auto adapters = render::DX12Adapter::GetAllAdapters();

    Ref<render::Adapter> adapter;
    for(size_t i = 0; i < adapters.size(); i++)
    {
      //TODO(utku): find rtx 30 or later adapter
      if(adapters[i]->desc.dedicatedVideoMemory > 2048)
      {
        adapter = adapters[i];
      }
    }

    //DX12Device device;
    //DX12Device device2(adapter);

    DXGI_MODE_DESC backBufferDesc = {};
    backBufferDesc.Width = window->GetWidth();
    backBufferDesc.Height = window->GetHeight();
    backBufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    DXGI_SAMPLE_DESC sampleDesc = {};
    sampleDesc.Count = 1;

    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferCount = frameBufferCount;
    swapChainDesc.BufferDesc = backBufferDesc;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.OutputWindow = *hwnd;
    swapChainDesc.SampleDesc = sampleDesc;
    swapChainDesc.Windowed = true;

    IDXGISwapChain* tempSwapChain;

    g_dxgiFactory->CreateSwapChain(
        m_commandQueue,
        &swapChainDesc,
        &tempSwapChain);

    m_swapChain = static_cast<IDXGISwapChain3*>(tempSwapChain);

    frameIndex = m_swapChain->GetCurrentBackBufferIndex();

    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = frameBufferCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    hr = m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvDescriptorHeap));
    if(FAILED(hr))
    {
      //TODO(utku): log
    }

    rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle =
        m_rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart();

    for(int i = 0; i < frameBufferCount; i++)
    {
      hr = m_swapChain->GetBuffer(i, IID_PPV_ARGS(&m_renderTargets[i]));

      if(FAILED(hr))
      {
        //TODO(utku): log
      }

      m_device->CreateRenderTargetView(m_renderTargets[i], NULL, rtvHandle);

      rtvHandle.ptr += rtvDescriptorSize;
    }

    for(int i = 0; i < frameBufferCount; i++)
    {
      hr = m_device->CreateFence(
          0,
          D3D12_FENCE_FLAG_NONE,
          IID_PPV_ARGS(&m_fence));

      if(FAILED(hr))
      {
        //TODO(utku): log
      }
    }

    m_fenceEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

    if(m_fenceEvent == NULL)
    {
      //TODO(utku) : log
    }
  }

  DX12Renderer::~DX12Renderer()
  {

  }

  void DX12Renderer::Render()
  {

  }

  void DX12Renderer::SwapChain()
  {

  }
}
