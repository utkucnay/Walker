add_subdirectory(vendor)

set(header_files
  ./include/Walker.h

  ./include/Core/EntryPoint.h
  ./include/Core/Application.h
  )

set(source_files
  ./src/Core/Application.cpp
  ./src/Core/Window.cpp

  ./src/Platform/Windows/WindowsWindow.cpp

  ./src/Platform/DirectX12/DX12Renderer.cpp
  ./src/Platform/DirectX12/DX12Adapter.cpp
  ./src/Platform/DirectX12/DX12Device.cpp
  ./src/Platform/DirectX12/DX12CommandList.cpp
  ./src/Platform/DirectX12/DX12CommandQueue.cpp
  ./src/Platform/DirectX12/DX12CommandAllocator.cpp
  ./src/Platform/DirectX12/DX12Fence.cpp

  ./src/Renderer/Renderer.cpp
  ./src/Renderer/CommandQueue.cpp
  ./src/Renderer/CommandList.cpp
  ./src/Renderer/CommandAllocator.cpp
  ./src/Renderer/Adapter.cpp
  ./src/Renderer/Device.cpp
  )

set(all_files
  ${header_files}
  ${source_files})

add_library(Walker ${all_files})
target_precompile_headers(Walker PUBLIC ./include/pch.h)
target_include_directories(Walker PUBLIC ./include/)
target_link_libraries(Walker PUBLIC D3D12.lib DXGI.lib)

target_link_libraries(Walker PUBLIC DirectStorage WinPixEventRuntime DirectX12)

target_compile_definitions(Walker PUBLIC "DEBUG=$<CONFIG:Debug>")
