#include "Render/Resource/Heap.h"
#include <Render/Core/Device.h>
#include <Render/Core/Renderer.h>
#include <Render/Core/RendererAPI.h>
#include <Render/Command/Command.h>
#include <Render/Resource/Resource.h>
#include <Render/ResourceBarrier/TransitionBarrier.h>

namespace wkr::render
{
  Renderer::Renderer(Window* window)
  {
    RendererAPI::Init(RendererAPI::APIType::DirectX12);

    auto adapters = Adapter::GetAllAdapters();

    mem::Ref<Adapter> adapter;
    for(auto adap : adapters)
    {
      if(adap->GetDedicatedVideoMemory() > 4096)
      {
        adapter = adap;
      }
    }

    s_defaultDevice = mem::Scope<DeviceBuilder>::Create()
      ->SetAdapter(adapter.Get())
      .BuildScope()
      ;

    m_commandDirectQueue = mem::Scope<CommandQueueBuilder>::Create()
      ->SetCommandListType(CommandList::Type::Direct)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None)
      .BuildScope()
      ;

    CreateSwapChain(window);

    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandDirectAllocator.push_back(
          mem::Scope<CommandAllocatorBuilder>::Create()
          ->SetCommandListType(CommandList::Type::Direct)
          .BuildScope()
          );

    m_commandDirectList = mem::Scope<CommandListBuilder>::Create()
      ->SetCommandListType(CommandList::Type::Direct)
      .SetCommandAllocator(m_commandDirectAllocator[0].Get())
      .BuildScope();

    m_commandCopyQueue = mem::Scope<CommandQueueBuilder>::Create()
      ->SetCommandListType(CommandList::Type::Copy)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None)
      .BuildScope()
      ;

    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandCopyAllocator.push_back(
          mem::Scope<CommandAllocatorBuilder>::Create()
          ->SetCommandListType(CommandList::Type::Copy)
          .BuildScope()
          );

    m_commandCopyList = mem::Scope<CommandListBuilder>::Create()
      ->SetCommandListType(CommandList::Type::Copy)
      .SetCommandAllocator(m_commandCopyAllocator[0].Get())
      .BuildScope()
      ;
  }

  void Renderer::CreateSwapChain(Window* window)
  {
    m_swapChain = window->SetSwapChain(&mem::Scope<SwapChainBuilder>::Create()
      ->SetCommandQueue(m_commandDirectQueue.Get())
      .SetDevice(m_device.Get())
      .SetMSAA(1, 0)
      .SetVsync(SwapChain::VsyncDesc::None)
      );
  }

  void Renderer::CreateResource()
  {
    m_vertexBuffer = mem::Scope<rsc::GenericBuffersBuilder>::Create()
      ->SetCommittedType(rsc::Heap::Type::Default, rsc::Heap::Flag::None)
      .SetSize(2 MB)
      .BuildScope()
      ;

    m_vertexUploadBuffer = mem::Scope<rsc::GenericBuffersBuilder>::Create()
      ->SetCommittedType(rsc::Heap::Type::Upload, rsc::Heap::Flag::None)
      .SetSize(2 MB)
      .BuildScope()
      ;
  }

  void Renderer::LoadResources()
  {

  }

  Renderer::~Renderer()
  {
    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
    {
      m_swapChain->GetCurrentFence()->FenceEvent(i);
    }

    m_device.Release();
    m_swapChain.Reset();
    m_commandDirectQueue.Release();
    m_commandDirectList.Release();

    for(int i = 0; i < m_commandDirectAllocator.size(); i++)
      m_commandDirectAllocator[i].Release();
  }

  void Renderer::Render()
  {
    auto swapChain = m_swapChain;
    auto renderTarget = swapChain->GetCurrentRenderTarget();
    uint32_t frameIndex = swapChain->GetFrameIndex();

    m_commandDirectAllocator[frameIndex]->Reset();

    m_commandDirectList->Reset(m_commandDirectAllocator[frameIndex].Get(), NULL);

    m_commandDirectList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create()
          ->SetResource(renderTarget->GetResource<rsc::Texture2D>())
          ->SetBeforeState(rsc::Resource::State::RenderTarget)
          ->SetAfterState(rsc::Resource::State::Present)
          .BuildScope().Get()
        });

    m_commandDirectList->OMSetRenderTargets(
        {
          renderTarget
        });

    m_commandDirectList->ClearRenderTargetView(renderTarget,
        Color32(0, 255, 0, 255));

    m_commandDirectList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create()
          ->SetResource(renderTarget->GetResource<rsc::Texture2D>())
          ->SetBeforeState(rsc::Resource::State::Present)
          ->SetAfterState(rsc::Resource::State::RenderTarget)
          .BuildScope().Get()
        });

    m_commandDirectList->Close();

    m_commandDirectQueue->ExecuteCommandList(
        {
          m_commandDirectList.Get()
        });

    m_commandDirectQueue->Signal(swapChain->GetCurrentFence(), frameIndex);

    swapChain->Present(0, 0);
  }
}
