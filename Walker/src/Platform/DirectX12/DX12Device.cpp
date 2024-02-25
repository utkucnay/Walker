#include <Platforms/DirectX12/DX12Device.h>

namespace wkr::render
{
  DX12Device::DX12Device()
  {
  }

  DX12Device::DX12Device(mem::Ref<Adapter> adapter)
  {
    CreateDevice(adapter);
  }

  DX12Device::~DX12Device()
  {
    device->Release();
  }

  mem::Ref<CommandQueue> DX12Device::CreateCommandQueue(CommandQueueDesc& desc)
  {
    return NULL;
  }

  mem::Ref<CommandAllocator> DX12Device::CreateCommandAllocator()
  {
    return NULL;
  }

  mem::Ref<CommandList> DX12Device::CreateCommandList()
  {
    return NULL;
  }

  mem::Ref<DescriptorHeap> DX12Device::CreateDescriptorHeap()
  {
    return NULL;
  }

  mem::Ref<RenderTargetView> DX12Device::CreateRenderTargetView()
  {
    return NULL;
  }

  mem::Ref<RootSignature> DX12Device::CreateRootSignature()
  {
    return NULL;
  }

  mem::Ref<Fence> DX12Device::CreateFence()
  {
    return NULL;
  }

  void DX12Device::CreateDevice(mem::Ref<Adapter> adapter)
  {
    HRESULT hr;

    if (adapter == NULL)
    {
      hr = D3D12CreateDevice(
        NULL,
        D3D_FEATURE_LEVEL_12_2,
        IID_PPV_ARGS(&device));
    }
    else
    {
      hr = D3D12CreateDevice(
        (IDXGIAdapter1*)adapter->GetNativeHandle(),
        D3D_FEATURE_LEVEL_12_2,
        IID_PPV_ARGS(&device));
    }

    WKR_CORE_LOG_COND(FAILED(hr), "Didn't Create DX12Device");
  }
}
