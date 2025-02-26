#pragma once

#include "Core/PlatformDetection.h"

#if DEBUG
#define WKR_CORE_LOG(...) spdlog::info(__VA_ARGS__);
#define WKR_CORE_LOG_COND(cond, ...) if (cond) WKR_CORE_LOG(__VA_ARGS__);

#define WKR_CORE_WARNING(...) spdlog::warn(__VA_ARGS__);
#define WKR_CORE_WARNING_COND(cond, ...) if (cond) WKR_CORE_WARNING(__VA_ARGS__)

#define WKR_CORE_ERROR(...) {   \
  spdlog::error(__VA_ARGS__);   \
  assert(0); }

#define WKR_CORE_ERROR_COND(cond, ...) if (cond) WKR_CORE_ERROR(__VA_ARGS__)

#define WKR_CORE_ERROR_WINDOWS_COND(cond, ...) if (cond) WKR_CORE_ERROR(__VA_ARGS__)
#define WKR_CORE_ERROR_CHECK_DX12(hr)   \
  if (FAILED(hr)) {               \
    \
}

#else
#define WKR_CORE_LOG(cond, ...)
#define WKR_CORE_LOG_COND(cond, ...)

#define WKR_CORE_WARNING(...)
#define WKR_CORE_WARNING_COND(cond, ...)

#define WKR_CORE_ERROR(...)
#define WKR_CORE_ERROR_COND(cond, ...)
#endif

#define SAFE_GET_NATIVE_OBJECT(obj, ...) \
  nullptr == obj ? nullptr : obj->GetNativeObject(__VA_ARGS__)

#define HAS_FLAG(flag1, flag2) \
  (static_cast<u64>(flag1) & static_cast<u64>(flag2)) != 0

#define WALKER_ENUM_CLASS_BITWISE_DECLARATION(E)  \
  E operator|(E a, E b);                          \
  E operator&(E a, E b);                          \
  E operator|=(E a, E b);                         \
  E operator&=(E a, E b);

#define WALKER_ENUM_CLASS_BITWISE_DEFINATION(E)      \
  E operator|(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) | \
                          static_cast<unsigned>(b)); \
  }                                                  \
                                                     \
  E operator&(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) & \
                          static_cast<unsigned>(b)); \
  }                                                  \
  E operator|=(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) | \
                          static_cast<unsigned>(b)); \
  }                                                  \
                                                     \
  E operator&=(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) & \
                          static_cast<unsigned>(b)); \
  }

#ifdef WKR_PLATFORM_WINDOWS
#define WKR_BUILD_DLL
#ifdef WKR_BUILD_DLL // TODO: Will Add CMAKE
#define WALKER_API /*__declspec(dllexport)*/
#else
#define WALKER_API /*__declspec(dllimport)*/
#endif

#define WALKER_DEBUG_BREAK() __debugbreak()  // MSVC
#else
#define WALKER_API __attribute__((visibility("default")))
#define WALKER_DEBUG_BREAK() raise(SIGTRAP);
#endif

#define WKR_KB(x) x * 1024
#define WKR_MB(x) x * 1024 * 1024
#define WKR_GB(x) x * 1024 * 1024 * 1024

#define WKR_OFFSET(Type, Member) offsetof(Type, Member)
