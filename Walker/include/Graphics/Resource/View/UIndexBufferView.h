#pragma once

#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Graphics/Resource/UBuffer.h"

namespace wkr::graphics {

class UIndexBufferView {
 public:
  UIndexBufferView(rhi::AResourceViewHandle resourceHandle)
      : m_ResourceView(std::move(resourceHandle)),
        m_IndexBuffer(resourceHandle->GetResource()) {}

 public:
  rhi::AResourceViewHandle GetResourceViewHandle() { return m_ResourceView; }

  UBuffer GetBuffer() { return m_IndexBuffer; }

 private:
  rhi::AResourceViewHandle m_ResourceView;
  UBuffer m_IndexBuffer;
};

}  // namespace wkr::graphics
