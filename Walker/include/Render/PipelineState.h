#pragma once

namespace wkr::render
{
  class PipelineState
  {
  public:
    virtual void* GetNativeHandle();
  };
}
