#pragma once

namespace wkr::render
{
  class IRootSignature
  {
  public:
    virtual ~IRootSignature() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
  };
}
