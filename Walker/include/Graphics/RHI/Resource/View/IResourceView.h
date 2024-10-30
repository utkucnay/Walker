#pragma once

namespace wkr::graphics::rhi {

class WALKER_API IResourceView {
 public:
  virtual ~IResourceView() = default;

 public:
  virtual NativeObject GetNativeObject() = 0;
  virtual std::string GetTypeName() = 0;
};

using IResourceViewHandle = mem::TRef<IResourceView>;

}  // namespace wkr::graphics::rhi
