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
    mem::Ref<Event> nextEvent;
    friend EventListener;
  };

  class EventListener
  {
    mem::Ref<Event> event;
  };
}
