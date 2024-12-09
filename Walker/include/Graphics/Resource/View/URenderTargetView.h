#pragma once

#include "Graphics/RHI/Resource/View/IResourceView.h"
#include "Graphics/Resource/UTexture2D.h"

namespace wkr::graphics {

class WALKER_API URenderTargetView {
 public:
 public:
  rhi::IResourceViewHandle& GetResourceViewHandle() { return m_ResourceView; }

  UTexture2D& GetTexture2D() { return m_Texture2D; }

 private:
  rhi::IResourceViewHandle m_ResourceView;
  UTexture2D m_Texture2D;
};

}  // namespace wkr::graphics
