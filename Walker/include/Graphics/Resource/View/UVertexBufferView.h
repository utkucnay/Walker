#pragma once

#include "Graphics/RHI/Resource/View/AResourceView.h"
#include "Graphics/Resource/UBuffer.h"

namespace wkr::graphics {

class UVertexBufferView {

 private:
  rhi::AResourceViewHandle m_ResourceView;
  UBuffer m_VertexBuffer;
};

}  // namespace wkr::graphics
