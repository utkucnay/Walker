#pragma once

namespace wkr
{
  template<typename... Args>
  class Event
  {
  public:
    void Invoke(Args... args)
    {
      for(auto eventListener : m_eventListeners)
      {
        eventListener(args...);
      }
    }

    void AddListener(std::function<void(Args...)> func)
    {
      m_eventListeners.push_back(func);
    }

    void RemoveListener(std::function<void(Args...)> func)
    {
      m_eventListeners.remove(func);
    }

  private:
    std::list<std::function<void(Args...)>> m_eventListeners;
  };
}
