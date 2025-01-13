#pragma once

#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"

namespace wkr::graphics::rhi::dx12 {

class UResourceBarrier : public IResourceBarrier {
 public:
  explicit UResourceBarrier(const FResourceBarrierDesc& desc);
  ~UResourceBarrier() override {}

 public:
  FResourceBarrierDesc GetDesc() override final;
  NativeObject GetNativeObject() override final { return &m_ResourceBarrier; }

 private:
  D3D12_RESOURCE_BARRIER m_ResourceBarrier;
};

}  // namespace wkr::graphics::rhi::dx12
