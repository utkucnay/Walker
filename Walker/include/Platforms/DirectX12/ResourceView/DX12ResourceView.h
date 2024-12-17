#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/View/AResourceView.h"

namespace wkr::graphics::rhi::dx12 {

class UResourceView : public AResourceView {
 public:
  UResourceView(CD3DX12_CPU_DESCRIPTOR_HANDLE handle,
                  rhi::IResourceHandle resource);

  ~UResourceView() override;

 public:
  NativeObject GetNativeObject() override final {
    return &m_ResourveViewHandle;
  }

 protected:
  CD3DX12_CPU_DESCRIPTOR_HANDLE m_ResourveViewHandle;
};

}  // namespace wkr::graphics::rhi::dx12
