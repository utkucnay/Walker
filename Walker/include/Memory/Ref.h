#pragma once

namespace wkr::mem
{
  template<typename T>
  class WeakRef;

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

    void Reset()
    {
      ptr.reset();
    }

  public:
    template<typename TConv>
    operator Ref<TConv>()
    {
      Ref<TConv> ret;
      ret.ptr = std::static_pointer_cast<TConv>(this->ptr);
      return ret;
    }

    template<typename TConv>
    operator WeakRef<TConv>()
    {
      WeakRef<TConv> ret;
      ret.m_ptr = std::static_pointer_cast<TConv>(this->ptr);
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
}
