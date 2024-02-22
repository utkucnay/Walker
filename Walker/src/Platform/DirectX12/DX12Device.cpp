#include <Platforms/DirectX12/DX12Device.h>

namespace wkr::render
{
  DX12Device::DX12Device(DX12DeviceSpec spec)
  {
  }

  DX12Device::DX12Device(Ref<Adapter> adapter, DX12DeviceSpec spec)
  {
    CreateDevice(adapter, spec);
  }

  DX12Device::~DX12Device()
  {
    device->Release();
  }

  Ref<CommandQueue> DX12Device::CreateCommandQueue(CommandQueueDesc& desc)
  {
    return NULL;
  }

  Ref<CommandAllocator> DX12Device::CreateCommandAllocator()
  {
    return NULL;
  }

  Ref<CommandList> DX12Device::CreateCommandList()
  {
    return NULL;
  }

  Ref<DescriptorHeap> DX12Device::CreateDescriptorHeap()
  {
    return NULL;
  }

  Ref<RenderTargetView> DX12Device::CreateRenderTargetView()
  {
    return NULL;
  }

  Ref<RootSignature> DX12Device::CreateRootSignature()
  {
    return NULL;
  }

  Ref<Fence> DX12Device::CreateFence()
  {
    return NULL;
  }

  void DX12Device::CreateDevice(Ref<Adapter> adapter, DX12DeviceSpec spec)
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
