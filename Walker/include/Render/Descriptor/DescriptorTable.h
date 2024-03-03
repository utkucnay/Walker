#pragma once

namespace wkr::render
{
  class DescriptorTable
  {
  public:
    virtual void* GetNativeHandle() = 0;
  };
}
