add_subdirectory(vendor)

set(header_files
  )

set(source_files
  ./src/Core/UApplication.cc

  ./src/Core/UGraphicsAPI.cc

  ./src/Platforms/Windows/WindowsWindow.cc
  ./src/Platforms/Windows/WindowsPageAllocator.cc

  ./src/Platforms/DirectX12/DX12Adapter.cc
  ./src/Platforms/DirectX12/DX12Device.cc
  ./src/Platforms/DirectX12/DX12CommandList.cc
  ./src/Platforms/DirectX12/DX12CommandQueue.cc
  ./src/Platforms/DirectX12/DX12CommandAllocator.cc
  ./src/Platforms/DirectX12/DX12Fence.cc
  ./src/Platforms/DirectX12/DX12SwapChain.cc
  ./src/Platforms/DirectX12/DX12DescriptorHeap.cc
  ./src/Platforms/DirectX12/DX12Heap.cc
  ./src/Platforms/DirectX12/DX12RootSignature.cc
  ./src/Platforms/DirectX12/DX12Resource.cc
  ./src/Platforms/DirectX12/DX12Shader.cc
  ./src/Platforms/DirectX12/DX12ResourceView.cc
  ./src/Platforms/DirectX12/DX12ResourceBarrier.cc
  ./src/Platforms/DirectX12/DX12DebugLayer.cc

  ./src/Graphics/UGraphics.cc
  ./src/Graphics/GraphicsType.cc
  ./src/Graphics/Resource/UBuffer.cc
  ./src/Graphics/Resource/UTexture1D.cc
  ./src/Graphics/Resource/UTexture2D.cc
  ./src/Graphics/Resource/UTexture3D.cc
  ./src/Graphics/Resource/Barrier/UTransitionBarrier.cc
  ./src/Graphics/GraphicsType.cc

  ./src/OS/UOSFactory.cc
  )

set(all_files
  ${header_files}
  ${source_files})

add_library(Walker ${all_files})
target_precompile_headers(Walker PUBLIC ./include/Walker_pch.h)
target_include_directories(Walker PUBLIC ./include/)

target_link_libraries(Walker PUBLIC D3D12.lib DXGI.lib d3dcompiler.lib dxguid.lib)

target_link_libraries(Walker PUBLIC DirectStorage WinPixEventRuntime DirectX12 spdlog)

target_compile_definitions(Walker PUBLIC "DEBUG=$<CONFIG:Debug>")
