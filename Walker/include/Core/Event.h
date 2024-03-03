#pragma once

#define BIND_EVENT_0(Func) std::bind(&Func, this);
#define BIND_EVENT_1(Func) std::bind(&Func, this, std::placeholders::_1);
#define BIND_EVENT_2(Func) std::bind(&Func, this, std::placeholders::_1, \
    std::placeholders::_2);
#define BIND_EVENT_3(Func) std::bind(&Func, this, std::placeholders::_1, \
    std::placeholders::_2, std::placeholders::_3);
#define BIND_EVENT_4(Func) std::bind(&Func, this, std::placeholders::_1, \
    std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);

namespace wkr
{
  template<typename... Args>
  class EventDispatcher
  {
  public:
    using Event = std::function<void(Args...)>;

  public:
    void operator()(Args... args)
    {
      for(auto eventListener : m_eventListeners)
      {
        eventListener(args...);
      }
    }

    void operator+=(Event func)
    {
      m_eventListeners.push_back(func);
    }

    void operator-=(Event func)
    {
      m_eventListeners.remove(func);
    }

  private:
    std::list<Event> m_eventListeners;
  };
}
