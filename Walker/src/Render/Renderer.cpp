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

    DeviceBuilder dBuilder;
    dBuilder
      .SetAdapter(adapter.Get());
    s_defaultDevice = dBuilder.BuildScope();

    CommandQueueBuilder cqBuilder;
    cqBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None);
    m_commandQueue = cqBuilder.BuildScope();

    CreateSwapChain(window);

    CommandAllocatorBuilder caBuilder;
    caBuilder
      .SetCommandListType(CommandList::Type::Direct);
    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandAllocator.push_back(caBuilder.BuildScope());

    CommandListBuilder clBuilder;
    clBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandAllocator(m_commandAllocator[0].Get());
    m_commandList = clBuilder.BuildScope();

  }

  void Renderer::CreateSwapChain(Window* window)
  {
    SwapChainBuilder scBuilder;
    scBuilder
      .SetCommandQueue(m_commandQueue.Get())
      .SetDevice(m_device.Get())
      .SetMSAA(1, 0)
      .SetVsync(SwapChain::VsyncDesc::None);

    m_swapChain = window->SetSwapChain(&scBuilder);
  }

  Renderer::~Renderer()
  {
    for(uint32_t i = 0; i < m_swapChain->GetBufferCount(); i++)
    {
      m_swapChain->GetCurrentFence()->FenceEvent(i);
    }

    m_device.Release();
    m_swapChain.Reset();
    m_commandQueue.Release();
    m_commandList.Release();

    for(int i = 0; i < m_commandAllocator.size(); i++)
      m_commandAllocator[i].Release();
  }

  void Renderer::Render()
  {
    auto swapChain = m_swapChain;
    auto renderTarget = swapChain->GetCurrentRenderTarget();
    uint32_t frameIndex = swapChain->GetFrameIndex();

    m_commandAllocator[frameIndex]->Reset();

    m_commandList->Reset(m_commandAllocator[frameIndex].Get(), NULL);

    m_commandList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create()
          ->SetResource(renderTarget->GetResource<rsc::Texture2D>())
          ->SetBeforeState(rsc::Resource::State::RenderTarget)
          ->SetAfterState(rsc::Resource::State::Present).BuildScope().Get()
        });

    m_commandList->OMSetRenderTargets(
        {
          renderTarget
        });

    m_commandList->ClearRenderTargetView(renderTarget,
        Color32(0, 255, 0, 255));

    m_commandList->ResourceBarriers(
        {
          mem::Scope<rsc::bar::TransitionBarrierBuilder>::Create()
          ->SetResource(renderTarget->GetResource<rsc::Texture2D>())
          ->SetBeforeState(rsc::Resource::State::Present)
          ->SetAfterState(rsc::Resource::State::RenderTarget).BuildScope().Get()
        });

    m_commandList->Close();

    m_commandQueue->ExecuteCommandList(
        {
          m_commandList.Get()
        });

    m_commandQueue->Signal(swapChain->GetCurrentFence(), frameIndex);

    swapChain->Present(0, 0);
  }
}
