#pragma once

#define REGISTER_FACTORY(Type, SubType, ...)                    \
  template <typename... Args>                                   \
  class SubType##FactoryTemp : public IFactory<Type, Args...> { \
   public:                                                      \
    Type* Create(Args... args) override {                       \
      return new SubType(args...);                              \
    }                                                           \
  };                                                            \
  class SubType##Factory : public SubType##FactoryTemp<__VA_ARGS__> {};

#define BEGIN_ABSTRACT_FACTORY(Prefix) \
  class U##Prefix##AbstractFactory : public I##Prefix##AbstractFactory {

#define END_FACTORY() \
  }                   \
  ;

#define CTOR_ABSTRACT_FACTORY(Prefix, action) \
 public:                              \
  U##Prefix##AbstractFactory() {                \
    action                            \
  }

#define SUBS_ABSTRACT_FACTORY(Type, SubType, ...)                 \
 public:                                                          \
  mem::TScope<IFactory<Type, __VA_ARGS__>> Get##Type() override { \
    return mem::TScope<SubType##Factory>::Create();               \
  }

#define CREATE_FACTORY(Prefix) class I##Prefix##AbstractFactory {

#define SUBS_FACTORY(Type, ...) \
 public:                        \
  virtual mem::TScope<IFactory<Type, __VA_ARGS__>> Get##Type() = 0;

#define SUBS_FACTORY_NAMESPACE(Namespace, Type, ...) \
 public:                                             \
  virtual mem::TScope<IFactory<Namespace::Type, __VA_ARGS__>> Get##Type() = 0;

namespace wkr {
template <typename T, typename... Args>
class IFactory {
 public:
  [[nodiscard]] virtual T* Create(Args... args) = 0;
};
}
