set(source_file
  ./src/d3dx12/d3dx12_property_format_table.cpp
  )

add_library(DirectX12 STATIC ${source_file})
target_include_directories(DirectX12 PUBLIC ./include/)
