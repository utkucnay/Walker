#pragma once

#include <Render/Resource/Resource.h>
#include <Platforms/DirectX12/DX12.h>
#include <Render/Descriptor/DescriptorHeap.h>

namespace wkr::render
{
  class DX12DescriptorHeap : public DescriptorHeap
  {
  public:
    DX12DescriptorHeap(
        mem::Visitor<Device> device,
        mem::Visitor<DescriptorHeapBuilder> dhb);
    ~DX12DescriptorHeap() override;

  public:
    uint32_t              GetCount() override final;
    DescriptorHeap::Type  GetType()  override final;
    DescriptorHeap::Flags GetFlags() override final;
    void Bind(
        mem::Visitor<Device> device,
        int count,
        std::vector<mem::WeakRef<rsc::Resource>> resources) override final;

  public:
    void* GetNativeHandle() override { return m_descriptorHeap; }

  private:
    ID3D12DescriptorHeap* m_descriptorHeap;
  };
}
