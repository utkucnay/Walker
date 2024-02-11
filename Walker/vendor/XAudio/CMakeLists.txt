add_library(XAudio INTERFACE)
target_include_directories(XAudio INTERFACE ./include/)
target_link_libraries(XAudio INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/xapobaseredist.lib
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/xaudio2_9redist.lib
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/xapobaseredist_md.lib
  )
