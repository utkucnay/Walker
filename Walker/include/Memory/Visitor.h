#pragma once

namespace wkr::mem
{
  template<typename T>
  class Visitor
  {
    Visitor() = delete;
    Visitor(T& other) = delete;
    Visitor(T&& other) = delete;

    T& operator=(T& other) = delete;
    T& operator=(T&& other) = delete;

  public:
    template<typename TO>
    Visitor(TO* visitor) :
      m_visitorAdr(*(static_cast<T*>(visitor)))
    {
    }

    T* operator->() const
    {
      return &m_visitorAdr;
    }

  private:
    T& m_visitorAdr;
  };
}
