#pragma once

namespace wkr::render
{
  class IDescriptorTable
  {
  public:
    virtual void* GetNativeHandle() = 0;
  };
}
