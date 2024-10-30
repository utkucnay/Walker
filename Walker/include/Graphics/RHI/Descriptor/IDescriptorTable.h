#pragma once

namespace wkr::graphics::rhi {

class WALKER_API IDescriptorTable {
 public:
  virtual ~IDescriptorTable() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
};

}  // namespace wkr::graphics::rhi
