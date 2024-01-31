#include <Platforms/DirectX12/DX12Graphics.h>

namespace wkr
{
  DX12Graphics::DX12Graphics(Window* window)
  {
    HRESULT hr;

    HWND* hwnd = (HWND*)window->GetNativeHandle();

    IDXGIFactory4* dxgiFactory;
    hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));

    if(SUCCEEDED(hr))
    {
      //TODO(utku): log
    }

    IDXGIAdapter1* adapter;

    int adapterIndex = 0;
    bool bAdapterFound = false;

    while(dxgiFactory->EnumAdapters1(
          adapterIndex,
          &adapter) != DXGI_ERROR_NOT_FOUND)
    {
      DXGI_ADAPTER_DESC1 desc;
      adapter->GetDesc1(&desc);

      char des[128];
      wcstombs(des, desc.Description, 128);
      std::cout << des << std::endl;

      if(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
      {
        adapterIndex++;
        break;
      }

      hr = D3D12CreateDevice(
          adapter,
          D3D_FEATURE_LEVEL_12_2,
          IID_PPV_ARGS(&m_device));

      if(SUCCEEDED(hr))
      {
        bAdapterFound = true;
        break;
      }
      else
      {

      }

      adapterIndex++;
    }

    if(!bAdapterFound)
    {
      //TODO(utku): log
    }

    D3D12_COMMAND_QUEUE_DESC cqDesc = {};

    hr = m_device->CreateCommandQueue(
        &cqDesc,
        IID_PPV_ARGS(&m_commandQueue));

    if(FAILED(hr))
    {
      //TODO(utku): log
    }

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

    dxgiFactory->CreateSwapChain(
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
      hr = m_device->CreateCommandAllocator(
          D3D12_COMMAND_LIST_TYPE_DIRECT,
          IID_PPV_ARGS(&m_commandAllocator[i]));

      if(FAILED(hr))
      {
        //TODO(utku): log
      }
    }

    hr = m_device->CreateCommandList(
        NULL,
        D3D12_COMMAND_LIST_TYPE_DIRECT,
        m_commandAllocator[0],
        NULL,
        IID_PPV_ARGS(&m_commandList));

    if(FAILED(hr))
    {
      //TODO(utku): log
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

  DX12Graphics::~DX12Graphics()
  {

  }

  void DX12Graphics::Render()
  {

  }

  void DX12Graphics::SwapChain()
  {

  }
}
