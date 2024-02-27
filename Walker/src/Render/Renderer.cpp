#include <Render/Renderer.h>
#include <Render/RendererMakro.h>
#include <Render/Command.h>

namespace wkr::render
{
  Renderer::Renderer(Window* window)
  {
    RendererAPI::ChangeAPI(RendererAPI::APIType::DirectX12);

    m_device = mem::Scope<DeviceFactory>::Create()
      ->CreateFactoryRef(NULL);

    CommandQueueBuilder cqBuilder;
    cqBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandQueuePriority(CommandQueue::Priority::Normal)
      .SetCommandQueueFlags(CommandQueue::Flags::None);
    m_commandQueue = cqBuilder.BuildRef(m_device.Get());

    CommandAllocatorBuilder caBuilder;
    caBuilder
      .SetCommandListType(CommandList::Type::Direct);
    m_commandAllocator = caBuilder.BuildRef(m_device.Get());

    CommandListBuilder clBuilder;
    clBuilder
      .SetCommandListType(CommandList::Type::Direct)
      .SetCommandAllocator(m_commandAllocator.Get());
    m_commandList = clBuilder.BuildRef(m_device.Get());

    SwapChainBuilder scBuilder;
    scBuilder
      .SetCommandQueue(m_commandQueue.Get())
      .SetDevice(m_device.Get())
      .SetMSAA(1, 0)
      .SetVsync(SwapChain::VsyncDesc::TripleBuffering);

    window->SetSwapChain(scBuilder);
  }

  Renderer::~Renderer()
  {

  }

  void Renderer::RenderScene()
  {

  }
}
