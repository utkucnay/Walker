#pragma once

namespace wkr::render
{
  class RootSignature
  {
  public:
    virtual ~RootSignature() = 0;

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
