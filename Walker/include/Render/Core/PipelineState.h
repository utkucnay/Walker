#pragma once

namespace wkr::render
{
  struct FPipelineStateDesc
  {

  };

  class IPipelineState
  {
  public:
    virtual ~IPipelineState() = default;

  public:
    virtual NativeObject GetNativeObject() const = 0;
  };

  using IPipelineStateHandle = mem::TRef<IPipelineState>;
}
