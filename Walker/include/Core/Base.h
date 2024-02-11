#pragma once

#if DEBUG
  #define WKR_CORE_LOG(...) std::cout << __VA_ARGS__ << std::endl
#else
  #define WKR_CORE_LOG(cond, ...)
#endif

namespace wkr
{
  template<typename T>
  using Ref = std::shared_ptr<T>;

  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T, typename... Args>
  Ref<T> CreateRef(Args... args)
  {
    return std::make_shared<T>(std::forward<Args>(args)...);
  }

  template<typename T, typename... Args>
  Scope<T> CreateScope(Args... args)
  {
    return std::make_unique<T>(std::forward<Args>(args)...);
  }
}
