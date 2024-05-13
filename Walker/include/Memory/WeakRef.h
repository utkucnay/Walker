#pragma once

namespace wkr::mem
{
  template<typename T>
  class Ref;

  template<typename T>
  class WeakRef
  {
  public:
    WeakRef()
    {

    }

    WeakRef(const Ref<T>& ref)
    {
      m_ptr(ref.ptr());
    }

    b32 Expired() const
    {
      return m_ptr.expired();
    }

    Ref<T> Lock() const
    {
      Ref<T> ret;
      ret.ptr = m_ptr.lock();
      return ret;
    }

  public:
    template<typename TConv>
    explicit operator WeakRef<TConv>()
    {
      WeakRef<TConv> ret;
      ret.m_ptr = std::static_pointer_cast<TConv>(this->m_ptr.lock());
      return ret;
    }

    template<typename TO>
    WeakRef<T>& operator=(Ref<TO> other)
    {
      m_ptr = other.ptr;
      return *this;
    };

  public:
    std::weak_ptr<T> m_ptr;
  };
}
