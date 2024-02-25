#pragma once

namespace wkr
{
  template <typename T,typename... Args>
  class Factory
  {
  public:
    virtual T*              CreateFactoryRaw  (Args... args) = 0;
    virtual mem::Ref<T>     CreateFactoryRef  (Args... args) = 0;
    virtual mem::Scope<T>   CreateFactoryScope(Args... args) = 0;
  };
}
