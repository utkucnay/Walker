#pragma once

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)
  #define WKR_PLATFORM_DIRECTX12

  #include <d3d12.h>
  #include <dxgi.h>
  #include <dxgi1_4.h>
  #include <d3dcompiler.h>

  #include <Platforms/DirectX12/DX12Factory.h>
  #include <Platforms/DirectX12/DX12Device.h>
  #include <Platforms/DirectX12/DX12Adapter.h>
  #include <Platforms/DirectX12/DX12CommandList.h>
  #include <Platforms/DirectX12/DX12CommandAllocator.h>
  #include <Platforms/DirectX12/DX12CommandQueue.h>
  #include <Platforms/DirectX12/DX12Renderer.h>
#endif
