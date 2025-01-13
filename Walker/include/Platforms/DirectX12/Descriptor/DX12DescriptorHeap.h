#pragma once

#include "Graphics/RHI/Descriptor/ADescriptorHeap.h"
#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics::rhi::dx12 {

class UDescriptorHeap : public ADescriptorHeap {
 public:
  explicit UDescriptorHeap(const FDescriptorHeapDesc& desc);
  ~UDescriptorHeap() override;

 public:
  FDescriptorHeapDesc GetDesc() override final;
  void Bind(const std::vector<IResourceHandle>& resources) override final;
  NativeObject GetNativeObject() override { return m_descriptorHeap; }

 private:
  void BindRTV(const std::vector<IResourceHandle>& resources);

 private:
  ID3D12DescriptorHeap* m_descriptorHeap;
};

}  // namespace wkr::graphics::rhi::dx12
