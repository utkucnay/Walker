#pragma once

namespace wkr::render
{
  class RootSignature
  {
  public:
    virtual ~RootSignature() {}

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
