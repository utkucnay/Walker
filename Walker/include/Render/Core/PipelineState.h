#pragma once

namespace wkr::render
{
  struct FPipelineStateDesc
  {

  };

  class IPipelineState
  {
  public:
    virtual ~IPipelineState() = 0;

  public:
    virtual NativeObject GetNativeObject() const = 0;
  };

  using IPipelineStateHandle = mem::TRef<IPipelineState>;
}
