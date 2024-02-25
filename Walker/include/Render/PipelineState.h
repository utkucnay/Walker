#pragma once

namespace wkr::render
{
  class PipelineState
  {
  public:
    virtual ~PipelineState() = 0;

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
