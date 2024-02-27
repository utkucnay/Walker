#include "Render/Adapter.h"
#include <Render/Renderer.h>
#include <Render/RendererMakro.h>
#include <Render/Command.h>

namespace wkr::render
{
  Renderer::Renderer(Window* window)
  {
    RendererAPI::Init(RendererAPI::APIType::DirectX12);

    auto adapters = Adapter::GetAllAdapters();

    mem::Ref<Adapter> adapter;
    for(auto adap : adapters)
    {
      if(adap->desc.dedicatedVideoMemory > 4096)
      {
        adapter = adap;
      }
    }

    m_device = mem::Scope<DeviceFactory>::Create()
      ->CreateFactoryRef(adapter);

    CommandQueueBuilder cqBuilder;
    cqBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None);
    m_commandQueue = cqBuilder.BuildRef(m_device.Get());

    CommandAllocatorBuilder caBuilder;
    caBuilder
      .SetCommandListType(CommandList::Type::Direct);
    for(int i = 0; i < 3; i++)
      m_commandAllocator[i] = caBuilder.BuildRef(m_device.Get());

    CommandListBuilder clBuilder;
    clBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandAllocator(m_commandAllocator[0].Get());
    m_commandList = clBuilder.BuildRef(m_device.Get());

    SwapChainBuilder scBuilder;
    scBuilder
      .SetCommandQueue(m_commandQueue.Get())
      .SetDevice(m_device.Get())
      .SetMSAA(1, 0)
      .SetVsync(SwapChain::VsyncDesc::TripleBuffering);

    m_swapChain = window->SetSwapChain(scBuilder);
  }

  Renderer::~Renderer()
  {

  }

  void Renderer::RenderScene()
  {

  }
}
