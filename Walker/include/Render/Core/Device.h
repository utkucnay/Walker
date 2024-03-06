#pragma once

#include <Render/Core/Adapter.h>

namespace wkr::render
{
  class Device
  {
  public:
    virtual ~Device() = 0;

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
