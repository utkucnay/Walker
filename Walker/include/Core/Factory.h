#pragma once

#define REGISTER_FACTORY(Type, SubType, ...)                          \
  template<typename... Args>                                          \
  class SubType##FactoryTemp : public IFactory<Type, Args...>         \
  {                                                                   \
  public:                                                             \
    Type*               CreateRaw  (Args... args) override            \
    {                                                                 \
      return new SubType(args...);                                    \
    }                                                                 \
    mem::TRef<Type>     CreateRef  (Args... args) override            \
    {                                                                 \
      return mem::TRef<SubType>::Create(args...);                     \
    }                                                                 \
    mem::TScope<Type>   CreateScope(Args... args) override            \
    {                                                                 \
      return mem::TScope<SubType>::Create(args...);                   \
    }                                                                 \
  };                                                                  \
  class SubType##Factory : public SubType##FactoryTemp<__VA_ARGS__> {};

#define BEGIN_FACTORY() \
  class UAbstractFactory : public IAbstractFactory {

#define END_FACTORY() };

#define CTOR_FACTORY(action) public: UAbstractFactory() { action }

#define SUBS_FACTORY(Type, SubType, ...) \
  mem::TScope<IFactory<Type, __VA_ARGS__>> Get##Type##Factory() { \
    return mem::TScope<SubType##Factory>::Create(); }

namespace wkr
{
  template <typename T,typename... Args>
  class IFactory
  {
  public:
    [[nodiscard]] virtual T*  CreateRaw  (Args... args) = 0;
    virtual mem::TRef<T>      CreateRef  (Args... args) = 0;
    virtual mem::TScope<T>    CreateScope(Args... args) = 0;
  };
}
