#pragma once

#include <type_traits>

namespace wkr::mem {

template <typename T>
class TWeakRef;

template <typename T>
class TRef {
 public:
  TRef<T>() {}

  explicit TRef<T>(T* obj) { ptr = std::shared_ptr<T>(obj); }

  TRef<T>(std::nullptr_t) { ptr = nullptr; }

 public:
  [[nodiscard]] T& Get() const { return *ptr.get(); }

  [[nodiscard]] T* GetPtr() const { return ptr.get(); }

  void Reset() { ptr.reset(); }

 public:
  template <typename TConv>
  operator TRef<TConv>() {
    TRef<TConv> ret;
    ret.ptr = std::static_pointer_cast<TConv>(this->ptr);
    return ret;
  }

  template <typename TConv>
  operator TWeakRef<TConv>() {
    TWeakRef<TConv> ret;
    ret.m_ptr = std::static_pointer_cast<TConv>(this->ptr);
    return ret;
  }

  T* operator->() const { return ptr.get(); };

  TRef<T>& operator=(std::nullptr_t) {
    ptr = nullptr;
    return *this;
  };

  b32 operator==(void* comp) const { return ptr.get() == comp; };

 public:
  template <typename... Args>
  static TRef<T> Create(Args&&... args) {
    static_assert(std::is_constructible<T, Args...>::value,
                  "Constructor Not Match...");
    TRef<T> ret;
    ret.ptr = std::make_shared<T>(std::forward<Args>(args)...);
    return ret;
  }

 public:
  std::shared_ptr<T> ptr;
};

}  // namespace wkr::mem
