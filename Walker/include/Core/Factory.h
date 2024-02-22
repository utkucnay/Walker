#pragma once

namespace wkr
{
  template <typename T,typename... Args>
  class Factory
  {
  public:
    virtual T*        CreateFactoryRaw  (Args... args) = 0;
    virtual Ref<T>    CreateFactoryRef  (Args... args) = 0;
    virtual Scope<T>  CreateFactoryScope(Args... args) = 0;
  };
}
