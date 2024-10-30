#pragma once

namespace wkr::graphics::rhi {

class WALKER_API IResourceBarrier {
 public:
  virtual ~IResourceBarrier() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceBarrierHandle = mem::TRef<IResourceBarrier>;

}  // namespace wkr::graphics::rhi
