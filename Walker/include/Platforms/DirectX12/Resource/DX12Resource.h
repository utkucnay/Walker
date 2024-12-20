#pragma once

#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics::rhi::dx12 {

class UResource : public IResource {
 public:
  UResource(FResourceDesc& desc);
  UResource(ID3D12Resource* resource) : m_Resource(resource) { m_Resource->AddRef(); };
  ~UResource() override;

 public:
  FResource GetResourceDesc() override final;
  FHeapProperties GetHeapProperties() override final;
  NativeObject GetNativeObject() override final { return m_Resource; }

 private:
  ID3D12Resource* m_Resource;
};

}  // namespace wkr::graphics::rhi::dx12
