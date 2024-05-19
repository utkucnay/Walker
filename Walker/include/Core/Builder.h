#pragma once

#define REGISTER_BUILDER(prefix, name) \
  prefix##name* name##Builder::BuildRaw() \
  { \
    return RendererAPI::GetAbstractFactory().Get##name##Factory() -> \
    CreateRaw(*this); \
  } \
  mem::Ref<prefix##name> name##Builder::BuildRef() \
  { \
    return RendererAPI::GetAbstractFactory().Get##name##Factory() -> \
    CreateRef(*this); \
  } \
  mem::Scope<prefix##name> name##Builder::BuildScope() \
  { \
    return RendererAPI::GetAbstractFactory().Get##name##Factory() -> \
    CreateScope(*this); \
  }

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
