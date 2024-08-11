#pragma once

#include <OS/OSAbstractFactory.h>

namespace wkr::os
{
  class OSFactory
  {
  public:
    static void Init();
    static IAbstractFactory& Get() { return s_instance.Get(); }

  private:
    static inline mem::TScope<IAbstractFactory> s_instance;
  };
}
