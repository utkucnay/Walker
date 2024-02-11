add_library(WinPixEventRuntime INTERFACE)
target_include_directories(WinPixEventRuntime INTERFACE ./Include/)
target_link_libraries(WinPixEventRuntime INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/WinPixEventRuntime.lib
  ${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/WinPixEventRuntime_UAP.lib)
