#pragma once

namespace wkr::render
{
  class DescriptorHeap
  {
  public:
    virtual ~DescriptorHeap() = 0;

  public:
    virtual void* GetNativeHandle() = 0;
  };
}
