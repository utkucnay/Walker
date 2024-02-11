#pragma once

namespace wkr
{
  struct EventArg
  {

  };

  class EventListener;

  class Event
  {
  public:
    std::function<void(EventArg)> bind;
  private:
    Ref<Event> nextEvent;
    friend EventListener;
  };

  class EventListener
  {
    Ref<Event> event;
  };
}
