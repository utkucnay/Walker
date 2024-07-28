#pragma once

namespace wkr::mem
{
  template<typename T>
  class TRef;

  template<typename T>
  class TWeakRef
  {
  public:
    TWeakRef() {}
    TWeakRef(const TRef<T>& ref) { m_ptr(ref.ptr()); }

    b32 Expired() const
    {
      return m_ptr.expired();
    }

    TRef<T> Lock() const
    {
      TRef<T> ret;
      ret.ptr = m_ptr.lock();
      return ret;
    }

  public:
    template<typename TConv>
    explicit operator TWeakRef<TConv>()
    {
      TWeakRef<TConv> ret;
      ret.m_ptr = std::static_pointer_cast<TConv>(this->m_ptr.lock());
      return ret;
    }

    template<typename TO>
    TWeakRef<T>& operator=(Ref<TO> other)
    {
      m_ptr = other.ptr;
      return *this;
    };

  public:
    std::weak_ptr<T> m_ptr;
  };
}
