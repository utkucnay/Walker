#pragma once

#include <Core/PlatformDetection.h>

#if defined (WKR_PLATFORM_WINDOWS)

  #include <Platforms/DirectX12/Core/DX12Factory.h>
  #include <Platforms/DirectX12/Core/DX12Device.h>
  #include <Platforms/DirectX12/Core/DX12Adapter.h>
  #include <Platforms/DirectX12/Core/DX12SwapChain.h>
  #include <Platforms/DirectX12/Core/DX12Fence.h>
  #include <Platforms/DirectX12/Core/DX12RootSignature.h>

  #include <Platforms/DirectX12/Command/DX12CommandList.h>
  #include <Platforms/DirectX12/Command/DX12CommandAllocator.h>
  #include <Platforms/DirectX12/Command/DX12CommandQueue.h>

  #include <Platforms/DirectX12/Resource/DX12Resource.h>
  #include <Platforms/DirectX12/Resource/DX12Heap.h>

  #include <Platforms/DirectX12/ResourceView/DX12RenderTargetView.h>

  #include <Platforms/DirectX12/Descriptor/DX12DescriptorHeap.h>

  #include <Platforms/DirectX12/ResourceBarrier/DX12TransitionBarrier.h>
#endif

