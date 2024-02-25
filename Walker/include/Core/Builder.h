#pragma once

namespace wkr
{
  template<typename T, typename... Args>
  class Builder
  {
    virtual T*              BuildRaw  (Args... args);
    virtual mem::Ref<T>     BuildRef  (Args... args);
    virtual mem::Scope<T>   BuildScope(Args... args);
  };
}
