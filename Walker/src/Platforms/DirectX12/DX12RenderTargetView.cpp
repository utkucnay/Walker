#include <Platforms/DirectX12/ResourceView/DX12RenderTargetView.h>

namespace wkr::render::view
{
  DX12RenderTargetView::DX12RenderTargetView(
        mem::Visitor<Device> device,
        mem::Visitor<rsc::Resource> resource,
        mem::Visitor<DescriptorHeap> heap,
        uint32_t index)
  {
    auto nDevice = static_cast<ID3D12Device*>(device->GetNativeHandle());
    auto nResource = static_cast<ID3D12Resource*>(resource->GetNativeHandle());
    auto nDescriptorHeap = static_cast<ID3D12DescriptorHeap*>(heap->GetNativeHandle());

    int rtvSize = nDevice->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

    auto rDesc = nResource->GetDesc();
    bool supRenderTarget = (rDesc.Flags & D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET) != 0;

    if(supRenderTarget)
    {
      WKR_CORE_WARNING("Didn't Support Resource To Render Target View");
      return;
    }

    CD3DX12_CPU_DESCRIPTOR_HANDLE tHandle(nDescriptorHeap->GetCPUDescriptorHandleForHeapStart());
    tHandle.Offset(index, rtvSize);
    nDevice->CreateRenderTargetView(nResource, NULL, tHandle);
    m_resourveViewHandle = std::move(tHandle);
  }

  DX12RenderTargetView::~DX12RenderTargetView()
  {
  }
}
