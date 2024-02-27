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

    bool Expired()
    {
      return m_ptr.expired();
    }

    Ref<T> Lock()
    {
      Ref<T> ret;
      ret.ptr = m_ptr.lock();
      return ret;
    }

  public:
    template<typename TO>
    WeakRef<T>& operator=(Ref<TO> other)
    {
      m_ptr = other.ptr;
      return *this;
    };

    bool operator==(void* comp) const
    {
      return m_ptr.get() == comp;
    };

  public:
    std::weak_ptr<T> m_ptr;
  };
}
