add_subdirectory(vendor)

set(header_files
  )

set(source_files
  ./src/Core/UApplication.cpp
  ./src/Core/AWindow.cpp
  ./src/Core/UGraphicsAPI.cpp

  ./src/Platforms/Windows/WindowsWindow.cpp
  ./src/Platforms/Windows/WindowsPageAllocator.cpp

  ./src/Platforms/DirectX12/DX12Adapter.cpp
  ./src/Platforms/DirectX12/DX12Device.cpp
  ./src/Platforms/DirectX12/DX12CommandList.cpp
  ./src/Platforms/DirectX12/DX12CommandQueue.cpp
  ./src/Platforms/DirectX12/DX12CommandAllocator.cpp
  ./src/Platforms/DirectX12/DX12Fence.cpp
  ./src/Platforms/DirectX12/DX12SwapChain.cpp
  ./src/Platforms/DirectX12/DX12DescriptorHeap.cpp
  ./src/Platforms/DirectX12/DX12RenderTargetView.cpp
  ./src/Platforms/DirectX12/DX12TransitionBarrier.cpp
  ./src/Platforms/DirectX12/DX12Heap.cpp
  ./src/Platforms/DirectX12/DX12RootSignature.cpp
  ./src/Platforms/DirectX12/DX12Resource.cpp
  ./src/Platforms/DirectX12/DX12Shader.cpp

  ./src/Graphics/UGraphics.cpp
  ./src/Graphics/Resource/UBuffer.cpp
  ./src/Graphics/Resource/UTexture2D.cpp
  ./src/Graphics/GraphicsType.cc

  ./src/OS/UOSFactory.cpp
  )

set(all_files
  ${header_files}
  ${source_files})

add_library(Walker ${all_files})
target_precompile_headers(Walker PUBLIC ./include/Walker.pch.inc)
target_include_directories(Walker PUBLIC ./include/)
target_link_libraries(Walker PUBLIC D3D12.lib DXGI.lib d3dcompiler.lib)

target_link_libraries(Walker PUBLIC DirectStorage WinPixEventRuntime DirectX12)

target_compile_definitions(Walker PUBLIC "DEBUG=$<CONFIG:Debug>")
