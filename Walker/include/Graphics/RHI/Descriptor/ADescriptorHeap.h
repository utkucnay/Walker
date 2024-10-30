#pragma once

#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/ResourceView/IResourceView.h"

namespace wkr::graphics::rhi {

struct WALKER_API FDescriptorHeapDesc {
  u32 Count = 0;
  EDescriptorHeapType Type = EDescriptorHeapType::kCBV_SRV_UAV;
  EDescriptorHeapF Flag = EDescriptorHeapF::kNone;
};

class WALKER_API IDescriptorHeap {
 public:
  virtual ~IDescriptorHeap() = default;

 public:
  virtual FDescriptorHeapDesc GetDesc() = 0;

  virtual void Bind(const std::vector<IResourceHandle>& resources) = 0;

  // virtual mem::Scope<DescriptorTable> CreateDescriptorTable(
  //     uint32_t offset, uint32_t size);

  template <typename T>
  [[nodiscard]] wkr::mem::TRef<T> Get(std::size_t index) {
    WKR_CORE_ERROR_COND(
        m_resourceViews[index]->GetTypeName() != T::GetStaticTypeName(),
        "Didn't Match View Type " << m_resourceViews[index]->GetTypeName()
                                  << " " << T::GetStaticTypeName());
    return m_resourceViews[index];
  }

 public:
  virtual NativeObject GetNativeObject() = 0;

 protected:
  std::vector<IResourceViewHandle> m_resourceViews;
};

using IDescriptorHeapHandle = wkr::mem::TRef<IDescriptorHeap>;

}  // namespace wkr::graphics::rhi
