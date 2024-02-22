#pragma once

#if DEBUG
  #define WKR_CORE_LOG(...) std::cout << __VA_ARGS__ << std::endl
  #define WKR_CORE_LOG_COND(cond, ...) if(cond) std::cout << __VA_ARGS__ << std::endl
#else
  #define WKR_CORE_LOG(cond, ...)
  #define WKR_CORE_LOG_COND(cond, ...)
#endif

namespace wkr
{
  template<typename T>
  class Ref
  {
  public:
    Ref<T>() { }

    Ref<T>(std::nullptr_t) { }

  public:
    T* Get()
    {
      return ptr.get();
    }

  public:
    template<typename TConv>
    operator Ref<TConv>()
    {
      Ref<TConv> ret;
      ret.ptr = std::static_pointer_cast<TConv>(this->ptr);
      return ret;
    }

    T* operator->()
    {
      return ptr.get();
    };

    Ref<T>& operator=(std::nullptr_t)
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
    static Ref<T> Create(Args&&... args)
    {
      Ref<T> ret;
      ret.ptr = std::make_shared<T>(std::forward<Args>(args)...);
      return ret;
    }

  public:
    std::shared_ptr<T> ptr;
  };

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
    static Scope<T> Create(Args&&... args)
    {
      Scope<T> ret;
      ret.ptr = std::make_unique<T>(std::forward<Args>(args)...);
      return ret;
    }

  public:
    std::unique_ptr<T> ptr;
  };
}
