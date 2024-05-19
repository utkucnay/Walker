#include <Platforms/DirectX12/Command/DX12CommandList.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{

  UDX12CommandList::UDX12CommandList(CommandListBuilder& clb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)URenderer::GetDefaultDevice().GetNativeHandle();
    auto lPipelineState = clb.m_pipelineState.Lock();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(clb.m_listType),
        static_cast<ID3D12CommandAllocator*>(
          clb.m_commandAllocator.Lock().Get().GetNativeHandle()),
        NULL == lPipelineState ?
        NULL :
        static_cast<ID3D12PipelineState*>(lPipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&m_commandList));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command List");
    WKR_CORE_LOG("Created DX12 Command List");
  }

  UDX12CommandList::~UDX12CommandList()
  {
    m_commandList->Release();
  }

  ICommandList::Type UDX12CommandList::GetType()
  {
    return static_cast<ICommandList::Type>(m_commandList->GetType());
  }

  void UDX12CommandList::Reset(
      ICommandAllocator& commandAllocator)
  {
    auto nCommandAllocator = static_cast<ID3D12CommandAllocator*>(
        commandAllocator.GetNativeHandle());
    m_commandList->Reset(nCommandAllocator, NULL);
  }

  void UDX12CommandList::Reset(
      ICommandAllocator& commandAllocator,
      IPipelineState& pipelineState)
  {
    auto nCommandAllocator = static_cast<ID3D12CommandAllocator*>(
        commandAllocator.GetNativeHandle());
    auto nPipelineState = static_cast<ID3D12PipelineState*>(
        pipelineState.GetNativeHandle());
    m_commandList->Reset(nCommandAllocator, nPipelineState);
  }

  void UDX12CommandList::ResourceBarriers(
        const std::vector<mem::Ref<rsc::bar::IResourceBarrier>>& barriers)
  {
    std::vector<D3D12_RESOURCE_BARRIER> nBarriers;
    std::transform(barriers.begin(), barriers.end(),
        std::back_inserter(nBarriers), [] (auto barrier)
        {
          return *static_cast<D3D12_RESOURCE_BARRIER*>(barrier->GetNativeHandle());
        });
    m_commandList->ResourceBarrier(nBarriers.size(), &nBarriers[0]);
  }

  void UDX12CommandList::OMSetRenderTargets(
        const std::vector<mem::Ref<view::URenderTargetView>>& rtvs)
  {
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> nRtvs;
    std::transform(rtvs.begin(), rtvs.end(),
        std::back_inserter(nRtvs), [] (auto rtv)
        {
          return *static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(rtv->GetNativeHandle());
        });
    m_commandList->OMSetRenderTargets(nRtvs.size(), &nRtvs[0], false, NULL);
  }

  void UDX12CommandList::ClearRenderTargetView(
        view::URenderTargetView& rtv,
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

  void UDX12CommandList::CopyResource(
        rsc::IResource& dstResource,
        rsc::IResource& srcResource)
  {
    auto nDstResource = static_cast<ID3D12Resource*>(dstResource.GetNativeHandle());
    auto nSrcResource = static_cast<ID3D12Resource*>(srcResource.GetNativeHandle());

    m_commandList->CopyResource(nDstResource, nSrcResource);
  }

  void UDX12CommandList::Close()
  {
    m_commandList->Close();
  }
}
