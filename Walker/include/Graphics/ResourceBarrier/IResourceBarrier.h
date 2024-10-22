#pragma once

namespace wkr::render
{
  class IResourceBarrier
  {
  public:
    virtual ~IResourceBarrier() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
  };

  using IResourceBarrierHandle = mem::TRef<IResourceBarrier>;
}
