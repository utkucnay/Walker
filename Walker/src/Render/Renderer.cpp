#include <Render/Resource/Heap.h>
#include <Render/Core/Device.h>
#include <Render/Core/Renderer.h>
#include <Render/Core/RendererAPI.h>
#include <Render/Command/Command.h>
#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/TransitionBarrier.h>

namespace wkr::render
{
  URenderer::URenderer(mem::WeakRef<UWindow> window)
  {
    RendererAPI::Init(RendererAPI::APIType::DirectX12);

    auto adapters = IAdapter::GetAllAdapters();

    mem::Ref<IAdapter> findedAdapter;
    for(auto adapter : adapters)
    {
      if(adapter->GetDedicatedVideoMemory() > 4096)
      {
        findedAdapter = adapter;
      }
    }

    s_defaultDevice = mem::Scope<DeviceBuilder>::Create().Get()
      .SetAdapter(findedAdapter)
      .BuildScope();

    m_commandDirectQueue = mem::Scope<CommandQueueBuilder>::Create().Get()
      .SetCommandListType(ICommandList::Type::Direct)
      .SetCommandQueuePriority(ICommandQueue::Priority::Normal)
      .SetCommandQueueFlags(ICommandQueue::Flags::None)
      .BuildRef();

    CreateSwapChain(window);

    for(u32 i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandDirectAllocator.push_back(
          mem::Scope<CommandAllocatorBuilder>::Create()
          ->SetCommandListType(ICommandList::Type::Direct)
          .BuildRef());

    m_commandDirectList = mem::Scope<CommandListBuilder>::Create(
        m_commandDirectAllocator[0]).Get()
      .SetCommandListType(ICommandList::Type::Direct)
      .BuildRef();

    m_commandCopyQueue = mem::Scope<CommandQueueBuilder>::Create().Get()
      .SetCommandListType(ICommandList::Type::Copy)
      .SetCommandQueuePriority(ICommandQueue::Priority::Normal)
      .SetCommandQueueFlags(ICommandQueue::Flags::None)
      .BuildRef();

    for(u32 i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandCopyAllocator.push_back(
          mem::Scope<CommandAllocatorBuilder>::Create()
          ->SetCommandListType(ICommandList::Type::Copy)
          .BuildRef());

    m_commandCopyList = mem::Scope<CommandListBuilder>::Create(
        m_commandCopyAllocator[0]).Get()
      .SetCommandListType(ICommandList::Type::Copy)
      .BuildRef();
  }

  void URenderer::CreateSwapChain(mem::WeakRef<UWindow> window)
  {
    m_swapChain = mem::Scope<SwapChainBuilder>::Create(
        window, m_commandDirectQueue).Get()
      .SetMSAA(1, 0)
      .SetVsync(USwapChain::VsyncDesc::None)
      .BuildRef();

    window.Lock()->SetSwapChain(m_swapChain);
  }

  void URenderer::CreateResource()
  {
    m_vertexBuffer = mem::Scope<rsc::GenericBuffersBuilder>::Create()
      ->SetCommittedType(rsc::IHeap::Type::Default, rsc::IHeap::Flag::None)
      .SetSize(2 MB)
      .BuildRef();

    m_vertexUploadBuffer = mem::Scope<rsc::GenericBuffersBuilder>::Create()
      ->SetCommittedType(rsc::IHeap::Type::Upload, rsc::IHeap::Flag::None)
      .SetSize(2 MB)
      .BuildRef();
  }

  void URenderer::LoadResources()
  {

  }

  URenderer::~URenderer()
  {
    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
    {
      m_swapChain->GetCurrentFence().FenceEvent(i);
    }

    m_device.Reset();
    m_swapChain.Reset();
    m_commandDirectQueue.Reset();
    m_commandDirectList.Reset();

    for(int i = 0; i < m_commandDirectAllocator.size(); i++)
      m_commandDirectAllocator[i].Reset();
  }

  void URenderer::Render()
  {
    mem::Ref<view::URenderTargetView> renderTarget = m_swapChain->GetCurrentRenderTarget();
    u32 frameIndex = m_swapChain->GetFrameIndex();

    m_commandDirectAllocator[frameIndex]->Reset();

    m_commandDirectList->Reset(m_commandDirectAllocator[frameIndex].Get());

    m_commandDirectList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create(
              static_cast<mem::WeakRef<rsc::IResource>>(renderTarget->GetTexture())).Get()
          .SetBeforeState(rsc::IResource::State::RenderTarget)
          .SetAfterState(rsc::IResource::State::Present)
          .BuildRef()
        });

    m_commandDirectList->OMSetRenderTargets(
        {
          renderTarget
        });

    m_commandDirectList->ClearRenderTargetView(renderTarget.Get(),
        Color32(0, 255, 0, 255));

    m_commandDirectList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create(
              static_cast<mem::WeakRef<rsc::IResource>>(renderTarget->GetTexture())).Get()
          .SetBeforeState(rsc::IResource::State::Present)
          .SetAfterState(rsc::IResource::State::RenderTarget)
          .BuildRef()
        });

    m_commandDirectList->Close();

    m_commandDirectQueue->ExecuteCommandList(
        {
          m_commandDirectList
        });

    m_commandDirectQueue->Signal(m_swapChain->GetCurrentFence(), frameIndex);

    m_swapChain->Present(0, 0);
  }
}
