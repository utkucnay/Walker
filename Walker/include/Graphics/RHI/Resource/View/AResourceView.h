#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics::rhi {

class WALKER_API AResourceView {
 public:
  virtual ~AResourceView() = default;

public:
  virtual NativeObject GetNativeObject() = 0;
  IResourceHandle GetResource() { return m_Resource; }

protected:
  IResourceHandle m_Resource;
};

using AResourceViewHandle = mem::TRef<AResourceView>;

}  // namespace wkr::graphics::rhi
