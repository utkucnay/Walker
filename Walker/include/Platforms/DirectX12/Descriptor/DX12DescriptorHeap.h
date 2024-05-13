#pragma once

#include <Render/Resource/Resource.h>
#include <Platforms/DirectX12/DX12.h>
#include <Render/Descriptor/DescriptorHeap.h>

namespace wkr::render
{
  class UDX12DescriptorHeap : public IDescriptorHeap
  {
  public:
    UDX12DescriptorHeap(DescriptorHeapBuilder& dhb);
    ~UDX12DescriptorHeap() override;

  public:
    u32 GetCount() override final;

    IDescriptorHeap::Type  GetType()  override final;
    IDescriptorHeap::Flags GetFlags() override final;
    void Bind(
        const std::vector<mem::WeakRef<rsc::IResource>>& resources) override final;

  public:
    NativeHandle GetNativeHandle() override { return m_descriptorHeap; }

  private:
    ID3D12DescriptorHeap* m_descriptorHeap;
  };
}
