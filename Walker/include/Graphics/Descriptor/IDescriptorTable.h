#pragma once

namespace wkr::render
{
  class IDescriptorTable
  {
  public:
    virtual ~IDescriptorTable() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
  };
}
