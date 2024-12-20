#pragma once

#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Graphics/Resource/UBuffer.h"

namespace wkr::graphics {

class WALKER_API UVertexBufferView {
 public:
  UVertexBufferView(rhi::AResourceViewHandle resourceHandle)
      : m_ResourceView(std::move(resourceHandle)),
        m_VertexBuffer(resourceHandle->GetResource()) {}

 public:
  rhi::AResourceViewHandle GetResourceViewHandle() { return m_ResourceView; }

  UBuffer GetBuffer() { return m_VertexBuffer; }

 private:
  rhi::AResourceViewHandle m_ResourceView;
  UBuffer m_VertexBuffer;
};

}  // namespace wkr::graphics
