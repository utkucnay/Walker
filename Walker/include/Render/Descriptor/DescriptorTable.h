#pragma once

namespace wkr::render
{
  class IDescriptorTable
  {
  public:
    virtual NativeObject GetNativeObject() = 0;
  };
}
