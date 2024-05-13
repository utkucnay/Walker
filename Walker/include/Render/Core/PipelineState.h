#pragma once

namespace wkr::render
{
  class IPipelineState
  {
  public:
    virtual ~IPipelineState() = 0;

  public:
    virtual NativeHandle GetNativeHandle() const = 0;
  };
}
