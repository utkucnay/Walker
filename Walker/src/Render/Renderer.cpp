#include <Render/Core/Renderer.h>
#include <Render/Core/RendererMakro.h>
#include <Render/Command/Command.h>

namespace wkr::render
{
  Renderer::Renderer()
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

    m_device = mem::Scope<DeviceFactory>::Create()
      ->CreateFactoryScope(adapter.Get());

    CommandQueueBuilder cqBuilder;
    cqBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None);
    m_commandQueue = cqBuilder.BuildScope(m_device.Get());

    CommandAllocatorBuilder caBuilder;
    caBuilder
      .SetCommandListType(CommandList::Type::Direct);
    for(int i = 0; i < 3; i++)
      m_commandAllocator[i] = caBuilder.BuildScope(m_device.Get());

    CommandListBuilder clBuilder;
    clBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandAllocator(m_commandAllocator[0].Get());
    m_commandList = clBuilder.BuildScope(m_device.Get());

  }

  void Renderer::CreateSwapChain(mem::Visitor<Window> window)
  {
    SwapChainBuilder scBuilder;
    scBuilder
      .SetCommandQueue(m_commandQueue.Get())
      .SetDevice(m_device.Get())
      .SetMSAA(1, 0)
      .SetVsync(SwapChain::VsyncDesc::None);

    m_swapChain.push_back(window->SetSwapChain(&scBuilder));
  }

  Renderer::~Renderer()
  {

  }

  void Renderer::Render(mem::Visitor<Window> window)
  {

  }
}
