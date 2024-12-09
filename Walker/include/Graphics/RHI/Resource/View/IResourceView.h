#pragma once

namespace wkr::graphics::rhi {

struct WALKER_API FResourceViewDesc{

};

class WALKER_API IResourceView {

 public:
  virtual NativeObject GetNativeObject() = 0;
};

using IResourceViewHandle = mem::TRef<IResourceView>;

}  // namespace wkr::graphics::rhi
