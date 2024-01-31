set(header_files
  )

set(source_files
  ./src/SandboxApp.cpp
  )

set(all_files
  ${header_files}
  ${source_files})

add_executable(Sandbox ${all_files})
target_include_directories(Sandbox PRIVATE ./include/)
target_link_libraries(Sandbox PUBLIC Walker)
