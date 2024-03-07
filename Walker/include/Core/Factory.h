#pragma once

#define REGISTER_FACTORY(Type, SubType, ...)                          \
  template<typename... Args>                                          \
  class SubType##FactoryTemp : public Factory<Type, Args...>          \
  {                                                                   \
  public:                                                             \
    Type*              CreateFactoryRaw  (Args... args)               \
    {                                                                 \
      return new SubType(args...);                                    \
    }                                                                 \
    mem::Ref<Type>     CreateFactoryRef  (Args... args)               \
    {                                                                 \
      return mem::Ref<SubType>::Create(args...);                      \
    }                                                                 \
    mem::Scope<Type>   CreateFactoryScope(Args... args)               \
    {                                                                 \
      return mem::Scope<SubType>::Create(args...);                    \
    }                                                                 \
  };                                                                  \
  class SubType##Factory : public SubType##FactoryTemp<__VA_ARGS__> {};


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
