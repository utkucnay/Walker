#pragma once

namespace wkr
{
  template<typename T, typename... Args>
  class IBuilder
  {
  public:
    virtual T*              BuildRaw  (Args... args) = 0;
    virtual mem::Ref<T>     BuildRef  (Args... args) = 0;
    virtual mem::Scope<T>   BuildScope(Args... args) = 0;
  };
}
