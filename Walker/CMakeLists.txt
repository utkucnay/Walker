add_subdirectory(vendor)

set(header_files
  ./include/Walker.h

  ./include/Core/EntryPoint.h
  ./include/Core/Application.h
  )

set(source_files
  ./src/Core/Application.cpp

  ./src/Platform/Windows/WindowsWindow.cpp

  ./src/Platform/DirectX12/DX12Renderer.cpp
  ./src/Platform/DirectX12/DX12Adapter.cpp
  ./src/Platform/DirectX12/DX12Device.cpp
  ./src/Platform/DirectX12/DX12Command.cpp
  ./src/Platform/DirectX12/DX12Fence.cpp

  ./src/Renderer/Renderer.cpp
  ./src/Renderer/Command.cpp
  ./src/Renderer/Adapter.cpp
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
