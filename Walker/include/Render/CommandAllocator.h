#pragma once

namespace wkr::render
{
  class CommandAllocator
  {
    virtual void* GetNativeHandle() = 0;
  };
}
