#pragma once

#include "Graphics/RHI/Resource/View/IResourceView.h"
#include "Graphics/Resource/UTexture2D.h"

namespace wkr::graphics::rsc {

class WALKER_API URenderTargetView {
 public:
 protected:
  rhi::IResourceViewHandle m_ResourceView;
  UTexture2D m_Texture2D;
};

using URenderTargetViewHandle = mem::TRef<URenderTargetView>;

}  // namespace wkr::graphics::rsc
