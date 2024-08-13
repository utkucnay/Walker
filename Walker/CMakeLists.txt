add_subdirectory(vendor)

set(header_files
  ./include/Walker.h

  ./include/Core/EntryPoint.h
  ./include/Core/Application.h
  )

set(source_files
  ./src/Core/Application.cpp
  ./src/Core/Window.cpp
  ./src/Core/RendererAPI.cpp

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

  ./src/Render/Renderer.cpp
  ./src/Render/Types.cpp
  ./src/Render/Resource/Buffer.cpp
  ./src/Render/Resource/Texture2D.cpp

  ./src/OS/OSFactory.cpp
  )

set(all_files
  ${header_files}
  ${source_files})

add_library(Walker ${all_files})
target_precompile_headers(Walker PUBLIC ./include/pch.h)
target_include_directories(Walker PUBLIC ./include/)
target_link_libraries(Walker PUBLIC D3D12.lib DXGI.lib d3dcompiler.lib)

target_link_libraries(Walker PUBLIC DirectStorage WinPixEventRuntime DirectX12)

target_compile_definitions(Walker PUBLIC "DEBUG=$<CONFIG:Debug>")
