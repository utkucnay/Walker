#pragma once

namespace wkr::mem
{
  template<typename T>
  class Scope
  {
  public:
    Scope<T>() {}

    Scope<T>(std::nullptr_t) {}

  public:
    T* Get()
    {
      return ptr.get();
    }

  public:
    template<typename TConv>
    operator Scope<TConv>()
    {
      Scope<TConv> ret;
      ret.ptr = std::move(this->ptr);
      return ret;
    }

    T* operator->()
    {
      return ptr.get();
    };

    Scope<T>& operator=(std::nullptr_t)
    {
      ptr = NULL;
      return *this;
    };

    bool operator==(void* comp) const
    {
      return ptr.get() == comp;
    };

  public:
    template<typename... Args>
    static Scope<T> Create(Args&&... args) noexcept
    {
      Scope<T> ret;
      ret.ptr = std::make_unique<T>(std::forward<Args>(args)...);
      return ret;
    }

  public:
    std::unique_ptr<T> ptr;
  };
}
