#pragma once

namespace wkr::render
{
  class RenderTargetView
  {
  public:
    virtual ~RenderTargetView() = 0;

  public:
    virtual void* GetNativeHandle() = 0;
    virtual void* GetGPUVirtualAdress() = 0;
  };
}
