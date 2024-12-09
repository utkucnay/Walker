#include "Platforms/DirectX12/Command/DX12CommandList.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UCommandList::UCommandList(FCommandListDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  HRESULT hr = nDevice->CreateCommandList(
      NULL, wkrtodx12::ConvertECommandType(desc.CommandType),
      desc.CommandAllocator->GetNativeObject(),
      SAFE_GET_NATIVE_OBJECT(desc.PipelineState), IID_PPV_ARGS(&m_commandList));

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command List");
  WKR_CORE_LOG("Created DX12 Command List");
}

UCommandList::~UCommandList() {
  m_commandList->Release();
}

ECommandType UCommandList::GetType() {
  return static_cast<ECommandType>(m_commandList->GetType());
}

void UCommandList::Reset(ICommandAllocator& commandAllocator,
                         IPipelineState* pipelineState) {
  m_commandList->Reset(commandAllocator.GetNativeObject(),
                       SAFE_GET_NATIVE_OBJECT(pipelineState));
}

void UCommandList::ResourceBarriers(
    const std::vector<IResourceBarrierHandle>& barriers) {
  std::vector<D3D12_RESOURCE_BARRIER> nBarriers;
  std::transform(barriers.begin(), barriers.end(),
                 std::back_inserter(nBarriers), [](auto barrier) {
                   return *static_cast<D3D12_RESOURCE_BARRIER*>(
                       barrier->GetNativeObject());
                 });

  m_commandList->ResourceBarrier(nBarriers.size(), &nBarriers[0]);
}

void UCommandList::OMSetRenderTargets(
    const std::vector<URenderTargetView>& rtvs) {
  std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> nRtvs;
  std::transform(rtvs.begin(), rtvs.end(), std::back_inserter(nRtvs),
                 [](auto rtv) {
                   return *static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(
                       rtv.GetResourceViewHandle()->GetNativeObject());
                 });

  m_commandList->OMSetRenderTargets(nRtvs.size(), &nRtvs[0], false, nullptr);
}

void UCommandList::ClearRenderTargetView(URenderTargetView& rtv,
                                         FColor32 color) {
  D3D12_CPU_DESCRIPTOR_HANDLE* nRtv =
      rtv.GetResourceViewHandle()->GetNativeObject();
  float nColor[] = {(float)color.R / 255, (float)color.G / 255,
                    (float)color.B / 255, (float)color.A / 255};

  m_commandList->ClearRenderTargetView(*nRtv, nColor, 0, nullptr);
}

void UCommandList::CopyResource(IResource& dstResource,
                                IResource& srcResource) {
  m_commandList->CopyResource(dstResource.GetNativeObject(),
                              srcResource.GetNativeObject());
}

void UCommandList::Close() {
  m_commandList->Close();
}

}  // namespace wkr::graphics::rhi::dx12
