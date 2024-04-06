#include "d3d12.h"
#include <Platforms/DirectX12/Command/DX12CommandList.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{

  DX12CommandList::DX12CommandList(CommandListBuilder*  clb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)Renderer::GetDefaultDevice()->GetNativeHandle();

    HRESULT hr = nDevice->CreateCommandList(
        NULL,
        static_cast<D3D12_COMMAND_LIST_TYPE>(clb->m_listType),
        static_cast<ID3D12CommandAllocator*>(
          clb->m_commandAllocator->GetNativeHandle()),
        NULL == clb->m_pipelineState ?
        NULL :
        static_cast<ID3D12PipelineState*>(clb->m_pipelineState->GetNativeHandle()),
        IID_PPV_ARGS(&m_commandList));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Command List");
    WKR_CORE_LOG("Created DX12 Command List");
  }

  DX12CommandList::~DX12CommandList()
  {
    m_commandList->Release();
  }

  CommandList::Type DX12CommandList::GetType()
  {
    return static_cast<CommandList::Type>(m_commandList->GetType());
  }

  void DX12CommandList::Reset(
      CommandAllocator* commandAllocator,
      PipelineState* pipelineState)
  {
    auto nCommandAllocator = static_cast<ID3D12CommandAllocator*>(commandAllocator->GetNativeHandle());
    m_commandList->Reset(nCommandAllocator, NULL);
  }

  void DX12CommandList::ResourceBarriers(
        std::vector<rsc::bar::ResourceBarrier*> barriers)
  {
    std::vector<D3D12_RESOURCE_BARRIER> nBarriers;
    std::transform(barriers.begin(), barriers.end(),
        std::back_inserter(nBarriers), [] (auto barrier)
        {
          return *static_cast<D3D12_RESOURCE_BARRIER*>(barrier->GetNativeHandle());
        });
    m_commandList->ResourceBarrier(nBarriers.size(), &nBarriers[0]);
  }

  void DX12CommandList::OMSetRenderTargets(
        std::vector<view::RenderTargetView*> rtvs)
  {
    std::vector<D3D12_CPU_DESCRIPTOR_HANDLE> nRtvs;
    std::transform(rtvs.begin(), rtvs.end(),
        std::back_inserter(nRtvs), [] (auto rtv)
        {
          return *static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(rtv->GetNativeHandle());
        });
    m_commandList->OMSetRenderTargets(nRtvs.size(), &nRtvs[0], false, NULL);
  }

  void DX12CommandList::ClearRenderTargetView(
        view::RenderTargetView* rtv,
        Color32 color)
  {
    auto nRtv = static_cast<D3D12_CPU_DESCRIPTOR_HANDLE*>(rtv->GetNativeHandle());
    float nColor[] =
    {
      (float)color.m_r/ 255,
      (float)color.m_g / 255,
      (float)color.m_b / 255,
      (float)color.m_a / 255};
    m_commandList->ClearRenderTargetView(*nRtv, nColor, 0, NULL);
  }

  void DX12CommandList::CopyResource(
        rsc::Resource* dstResource,
        rsc::Resource* srcResource)
  {
    auto nDstResource = static_cast<ID3D12Resource*>(dstResource->GetNativeHandle());
    auto nSrcResource = static_cast<ID3D12Resource*>(srcResource->GetNativeHandle());

    m_commandList->CopyResource(nDstResource, nSrcResource);
  }

  void DX12CommandList::Close()
  {
    m_commandList->Close();
  }
}
