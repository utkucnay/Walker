#pragma once

#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Graphics/Resource/UBuffer.h"

namespace wkr::graphics {

class WALKER_API UConstantBufferView {
 public:
  UConstantBufferView(rhi::AResourceViewHandle resourceView)
      : m_ResourceView(std::move(resourceView)),
        m_Buffer(m_ResourceView->GetResource()) {}

 public:
  rhi::AResourceViewHandle GetResourceViewHandle() { return m_ResourceView; }

  UBuffer GetBuffer() { return m_Buffer; }

 private:
  rhi::AResourceViewHandle m_ResourceView;
  UBuffer m_Buffer;
};

}  // namespace wkr::graphics
