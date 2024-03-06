#pragma once

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #define WKR_PLATFORM_DIRECTX12

  #include <d3d12.h>
  #include <d3dx12/d3dx12.h>
  #include <dxgi.h>
  #include <dxgi1_4.h>
  #include <d3dcompiler.h>

  #include <Platforms/DirectX12/Core/DX12Factory.h>
  #include <Platforms/DirectX12/Core/DX12Device.h>
  #include <Platforms/DirectX12/Core/DX12Adapter.h>
  #include <Platforms/DirectX12/Core/DX12SwapChain.h>
  #include <Platforms/DirectX12/Core/DX12Fence.h>

  #include <Platforms/DirectX12/Command/DX12CommandList.h>
  #include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
  #include <Platforms/DirectX12/Command/DX12CommandQueue.h>

  #include <Platforms/DirectX12/Resource/DX12Texture2D.h>

  #include <Platforms/DirectX12/ResourceView/DX12RenderTargetView.h>

  #include <Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h>
#endif
