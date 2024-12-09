#pragma once

#include "Graphics/RHI/Resource/View/IResourceView.h"
#include "Graphics/Resource/UBuffer.h"

namespace wkr::graphics {

class UVertexBufferView {

 private:
  rhi::IResourceViewHandle m_ResourceView;
  UBuffer m_VertexBuffer;
};

}  // namespace wkr::graphics
