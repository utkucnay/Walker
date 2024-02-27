#pragma once

#if DEBUG
  #define WKR_CORE_LOG(...) std::cout << __VA_ARGS__ << std::endl
  #define WKR_CORE_LOG_COND(cond, ...) if(cond) std::cout << __VA_ARGS__ << std::endl
#else
  #define WKR_CORE_LOG(cond, ...)
  #define WKR_CORE_LOG_COND(cond, ...)
#endif

#define KB * 1024
#define MB * 1024 * KB
