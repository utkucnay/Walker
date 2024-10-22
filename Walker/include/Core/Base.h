#pragma once

#if DEBUG
#define WKR_CORE_LOG(...) std::cout << "L:" __VA_ARGS__ << std::endl;
#define WKR_CORE_LOG_COND(cond, ...) \
  if (cond)                          \
    std::cout << "L:" __VA_ARGS__ << std::endl;

#define WKR_CORE_WARNING(...) std::cout << "W:" __VA_ARGS__ << std::endl;
#define WKR_CORE_WARNING_COND(cond, ...) \
  if (cond)                              \
    std::cout << "W:" __VA_ARGS__ << std::endl;

#define WKR_CORE_ERROR(...)                   \
  std::cout << "E:" __VA_ARGS__ << std::endl; \
  assert(0);

#define WKR_CORE_ERROR_COND(cond, ...)          \
  if (cond) {                                   \
    std::cout << "E:" __VA_ARGS__ << std::endl; \
    assert(0);                                  \
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

#define WALKER_ENUM_CLASS_BITWISE_DECLARATION(E)    \
  E operator|(E a, E b);                            \
  E operator&(E a, E b);                            \

#define WALKER_ENUM_CLASS_BITWISE_DEFINATION(E)      \
  E operator|(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) | \
                          static_cast<unsigned>(b)); \
  }                                                  \
                                                     \
  E operator&(E a, E b) {                            \
    return static_cast<E>(static_cast<unsigned>(a) & \
                          static_cast<unsigned>(b)); \
  }

#define KB *1024
#define MB *1024 * 1024
