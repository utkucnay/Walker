#pragma once

namespace wkr::render
{
  class IShader
  {
  public:
    virtual ~IShader() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
  };
}
