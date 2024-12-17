#include "Platforms/DirectX12/ResourceView/DX12ResourceView.h"

namespace wkr::graphics::rhi::dx12 {

UResourceView::UResourceView(CD3DX12_CPU_DESCRIPTOR_HANDLE handle,
                             rhi::IResourceHandle resource) {
  m_ResourveViewHandle = handle;
  m_Resource = resource;
}

UResourceView::~UResourceView() {}

}  // namespace wkr::graphics::rhi::dx12
