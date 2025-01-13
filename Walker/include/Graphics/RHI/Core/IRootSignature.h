#pragma once

namespace wkr::graphics::rhi {

struct WALKER_API FRootSignatureDesc {

};

class WALKER_API IRootSignature {
 public:
  virtual ~IRootSignature() {}

 public:
  virtual NativeObject GetNativeObject() = 0;
};

}  // namespace wkr::graphics::rhi
