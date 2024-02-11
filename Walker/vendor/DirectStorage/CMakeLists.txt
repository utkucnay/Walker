add_library(DirectStorage INTERFACE)
target_include_directories(DirectStorage INTERFACE ./include/)
target_link_libraries(DirectStorage INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/dstorage.lib)
