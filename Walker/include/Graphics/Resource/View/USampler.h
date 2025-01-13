#pragma once

#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Graphics/Resource/UTexture2D.h"

namespace wkr::graphics {

class WALKER_API USampler {
 public:
  USampler(rhi::AResourceViewHandle resourceHandle)
      : m_ResourceView(std::move(resourceHandle)),
        m_Texture2D(m_ResourceView->GetResource()) {}

 public:
  rhi::AResourceViewHandle GetResourceViewHandle() { return m_ResourceView; }

  UTexture2D GetTexture2D() { return m_Texture2D; }

 private:
  rhi::AResourceViewHandle m_ResourceView;
  UTexture2D m_Texture2D;
};

}  // namespace wkr::graphics
