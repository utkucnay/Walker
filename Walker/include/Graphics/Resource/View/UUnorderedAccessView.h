#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/View/AResourceView.h"

namespace wkr::graphics {

class WALKER_API UUnorderedAccessView {
 public:
  UUnorderedAccessView(rhi::AResourceViewHandle resourceView)
      : m_ResourceView(std::move(resourceView)),
        m_Resource(m_ResourceView->GetResource()) {}

 public:
  rhi::AResourceViewHandle GetResourceView() { return m_ResourceView; }

  rhi::IResourceHandle GetResource() { return m_Resource; }

 private:
  rhi::AResourceViewHandle m_ResourceView;
  rhi::IResourceHandle m_Resource;
};

}  // namespace wkr::graphics
