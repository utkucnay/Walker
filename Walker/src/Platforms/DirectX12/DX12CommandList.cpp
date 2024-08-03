#include <Platforms/DirectX12/Command/DX12CommandList.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  UCommandList::UCommandList(FCommandListDesc& clb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice().GetNativeHandle();
  }

  UCommandList::~UCommandList()
  {
    m_commandList->Release();
  }

  ECommandType UCommandList::GetType()
  {
    return static_cast<ECommandType>(m_commandList->GetType());
  }

  void UCommandList::Reset(
      ICommandAllocator& commandAllocator,
      IPipelineState* pipelineState)
  {
    auto nCommandAllocator = static_cast<ID3D12CommandAllocator*>(
        commandAllocator.GetNativeHandle());
    auto nPipelineState = pipelineState == nullptr ? nullptr
      : static_cast<ID3D12PipelineState*>(pipelineState.GetNativeHandle());
    m_commandList->Reset(nCommandAllocator, nPipelineState);
  }

  void UCommandList::ResourceBarriers(
        const std::vector<IResourceBarrier*>& barriers)
  {
    std::vector<D3D12_RESOURCE_BARRIER> nBarriers;
    std::transform(barriers.begin(), barriers.end(),
        std::back_inserter(nBarriers), [] (auto barrier)
        {
          return *static_cast<D3D12_RESOURCE_BARRIER*>(barrier->GetNativeHandle());
        });
    m_commandList->ResourceBarrier(nBarriers.size(), &nBarriers[0]);
  }

  void UCommandList::OMSetRenderTargets(
        const std::vector<URenderTargetView*>& rtvs)
  {
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> nRtvs;
    std::transform(rtvs.begin(), rtvs.end(),
        std::back_inserter(nRtvs), [] (auto rtv)
        {
          return *static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(rtv->GetNativeHandle());
        });
    m_commandList->OMSetRenderTargets(nRtvs.size(), &nRtvs[0], false, NULL);
  }

  void UCommandList::ClearRenderTargetView(
        URenderTargetView& rtv,
        FColor32 color)
  {
    auto nRtv = static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(rtv.GetNativeHandle());
    float nColor[] =
    {
      (float)color.m_r / 255,
      (float)color.m_g / 255,
      (float)color.m_b / 255,
      (float)color.m_a / 255};
    m_commandList->ClearRenderTargetView(*nRtv, nColor, 0, NULL);
  }

  void UCommandList::CopyResource(
        IResource& dstResource,
        IResource& srcResource)
  {
    auto nDstResource = static_cast<ID3D12Resource*>(dstResource.GetNativeHandle());
    auto nSrcResource = static_cast<ID3D12Resource*>(srcResource.GetNativeHandle());

    m_commandList->CopyResource(nDstResource, nSrcResource);
  }

  void UCommandList::Close()
  {
    m_commandList->Close();
  }
}
