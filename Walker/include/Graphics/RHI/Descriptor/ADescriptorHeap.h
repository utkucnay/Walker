#pragma once

#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/View/IResourceView.h"

namespace wkr::graphics::rhi {

struct WALKER_API FDescriptorHeapDesc {
  u32 Count = 0;
  EDescriptorHeapType Type = EDescriptorHeapType::kCBV_SRV_UAV;
  EDescriptorHeapF Flag = EDescriptorHeapF::kNone;
};

class WALKER_API ADescriptorHeap {
 public:
  virtual ~ADescriptorHeap() = default;

 public:
  virtual FDescriptorHeapDesc GetDesc() = 0;
  virtual void Bind(const std::vector<IResourceHandle>& resources) = 0;
  virtual NativeObject GetNativeObject() = 0;

  // virtual mem::Scope<DescriptorTable> CreateDescriptorTable(
  //     uint32_t offset, uint32_t size);

 protected:
  std::vector<IResourceViewHandle> m_ResourceViews;
};

using IDescriptorHeapHandle = wkr::mem::TRef<ADescriptorHeap>;

}  // namespace wkr::graphics::rhi
