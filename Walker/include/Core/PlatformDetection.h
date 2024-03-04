#pragma once

#if defined(_WIN32)
  #if defined(_WIN64)
    #define WKR_PLATFORM_WINDOWS
  #else
    #error "Win32 builds are not supported"
  #endif
#elif defined(__APPLE__) || defined(__MACH__)
  #error "Apple builds are not supported"
#elif defined(__ANDROID__)
  #error "Andoid builds are not supported"
#elif defined(__Linux__)
  #error "Linux is not suported"
#endif
