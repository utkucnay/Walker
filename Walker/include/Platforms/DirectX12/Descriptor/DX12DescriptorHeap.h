#pragma once

#include "Graphics/Resource/IResource.h"
#include "Graphics/Descriptor/ADescriptorHeap.h"

namespace wkr::render::dx12
{
  class UDescriptorHeap : public IDescriptorHeap
  {
  public:
    UDescriptorHeap(FDescriptorHeapDesc& desc);
    ~UDescriptorHeap() override;

  public:
    u32 GetCount() override final;

    EDescriptorHeapType  GetType()  override final;
    EDescriptorHeapFlags GetFlags() override final;
    void Bind(
        const std::vector<IResourceHandle>& resources) override final;

  public:
    NativeObject GetNativeObject() override { return m_descriptorHeap; }

  private:
    ID3D12DescriptorHeap* m_descriptorHeap;
  };
}
