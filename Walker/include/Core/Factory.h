#pragma once

#define REGISTER_FACTORY(Type, SubType, ...)                          \
  template<typename... Args>                                          \
  class SubType##FactoryTemp : public IFactory<Type, Args...>         \
  {                                                                   \
  public:                                                             \
    Type*              CreateRaw  (Args... args)                      \
    {                                                                 \
      return new SubType(args...);                                    \
    }                                                                 \
    mem::Ref<Type>     CreateRef  (Args... args)                      \
    {                                                                 \
      return mem::Ref<SubType>::Create(args...);                      \
    }                                                                 \
    mem::Scope<Type>   CreateScope(Args... args)                      \
    {                                                                 \
      return mem::Scope<SubType>::Create(args...);                    \
    }                                                                 \
  };                                                                  \
  class SubType##Factory : public SubType##FactoryTemp<__VA_ARGS__> {};


namespace wkr
{
  template <typename T,typename... Args>
  class IFactory
  {
  public:
    virtual T*              CreateRaw  (Args... args) = 0;
    virtual mem::Ref<T>     CreateRef  (Args... args) = 0;
    virtual mem::Scope<T>   CreateScope(Args... args) = 0;
  };
}
