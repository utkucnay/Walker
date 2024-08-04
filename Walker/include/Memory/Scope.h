#pragma once

namespace wkr::mem
{
  template<typename T>
  class TScope
  {
  public:
    TScope<T>() {}
    TScope<T>(T* obj) { ptr = std::unique_ptr<T>(obj); }
    TScope<T>(std::nullptr_t) { ptr = nullptr; }

  public:
    [[nodiscard]] T& Get()
    {
      return *ptr.get();
    }

    [[nodiscard]] T* GetPtr()
    {
      return ptr.get();
    }

    void Release()
    {
      ptr.release();
    }

  public:
    template<typename TConv>
    operator TScope<TConv>()
    {
      TScope<TConv> ret;
      ret.ptr = std::move(this->ptr);
      return ret;
    }

    T* operator->()
    {
      return ptr.get();
    };

    TScope<T>& operator=(std::nullptr_t)
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
    static TScope<T> Create(Args&&... args) noexcept
    {
      TScope<T> ret;
      ret.ptr = std::make_unique<T>(std::forward<Args>(args)...);
      return ret;
    }

  public:
    std::unique_ptr<T> ptr;
  };
}
