#include <Render/Core/Renderer.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  URenderer::URenderer(FRendererDesc& desc)
  {
    URendererAPI::Init(URendererAPI::EType::DirectX12);

    auto& renderFactory = URendererAPI::GetAbstractFactory();

    FDeviceDesc deviceDesc = {};
    m_device = renderFactory.GetDeviceFactory()->CreateRef(deviceDesc);

    s_defaultDevice = m_device;

    FCommandQueueDesc commandQueueDesc = {};
    commandQueueDesc.m_commandType = ECommandType::Direct;
    commandQueueDesc.m_commandQueuePriority = ECommandQueuePriority::Normal;
    commandQueueDesc.m_commandQueueFlags = ECommandQueueFlags::None;
    m_commandDirectQueue = renderFactory.GetCommandQueueFactory()->CreateRef(commandQueueDesc);

    FSwapChainDesc swapChainDesc = {};
    swapChainDesc.m_window = desc.window;
    swapChainDesc.m_commandQueue = m_commandDirectQueue;
    swapChainDesc.m_bufferCount = 3;
    swapChainDesc.m_bufferUsage = EResourceUsage::RENDER_TARGET_OUTPUT;
    swapChainDesc.m_swapEffect = ESwapChainEffect::FlipDiscard;

    swapChainDesc.m_sampleDesc.count = 1;
    swapChainDesc.m_sampleDesc.quality = 0;

    swapChainDesc.m_bufferDesc = {};
    swapChainDesc.m_bufferDesc.m_width = desc.window->GetWidth();
    swapChainDesc.m_bufferDesc.m_height = desc.window->GetHeight();
    swapChainDesc.m_bufferDesc.m_format = EResourceFormat::R8G8B8A8_UNORM;
    swapChainDesc.m_bufferDesc.m_refreshRate.m_numerator = 0;
    swapChainDesc.m_bufferDesc.m_refreshRate.m_denominator = 1;

    m_swapChain = renderFactory.GetSwapChainFactory()->CreateRef(swapChainDesc);
    desc.window->SetSwapChain(m_swapChain);

    FCommandAllocatorDesc commandAllocatorDesc;
    commandAllocatorDesc.commandType = ECommandType::Direct;

    for(u32 i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandDirectAllocator.push_back(renderFactory.GetCommandAllocatorFactory()
                                         ->CreateRef(commandAllocatorDesc));

    FCommandListDesc commandListDesc = {};
    commandListDesc.m_commandAllocator = m_commandDirectAllocator[0];
    commandListDesc.m_commandType = ECommandType::Direct;

    m_commandDirectList = renderFactory.GetCommandListFactory()
    ->CreateRef(commandListDesc);
  }

  void URenderer::CreateResource()
  {
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
    s_defaultDevice.Reset();
    m_swapChain.Reset();
    m_commandDirectQueue.Reset();
    m_commandDirectList.Reset();

    for(int i = 0; i < m_commandDirectAllocator.size(); i++)
      m_commandDirectAllocator[i].Reset();
  }

  void URenderer::Render()
  {
    URenderTargetViewHandle renderTarget = m_swapChain->GetCurrentRenderTarget();
    u32 frameIndex = m_swapChain->GetFrameIndex();

    m_commandDirectAllocator[frameIndex]->Reset();

    m_commandDirectList->Reset(m_commandDirectAllocator[frameIndex].Get(), nullptr);

    auto& renderFactory = URendererAPI::GetAbstractFactory();

    FTransitionBarrierDesc transitionBarrierDesc = {};
    transitionBarrierDesc.m_resource = renderTarget->m_resource.Lock();
    transitionBarrierDesc.m_beforeState = EResourceState::RenderTarget;
    transitionBarrierDesc.m_afterState = EResourceState::Present;

    auto barrier = renderFactory.GetTransitionBarrierFactory()
    ->CreateRef(transitionBarrierDesc);

    m_commandDirectList->ResourceBarriers(
        {
          barrier.GetPtr()
        });

    m_commandDirectList->OMSetRenderTargets(
        {
          renderTarget.GetPtr()
        });

    m_commandDirectList->ClearRenderTargetView(renderTarget.Get(),
        FColor32(0, 255, 0, 255));


    transitionBarrierDesc.m_beforeState = EResourceState::Present;
    transitionBarrierDesc.m_afterState = EResourceState::RenderTarget;

    auto reverseBarrier = renderFactory.GetTransitionBarrierFactory()
    ->CreateRef(transitionBarrierDesc);

    m_commandDirectList->ResourceBarriers(
        {
          reverseBarrier.GetPtr()
        });

    m_commandDirectList->Close();

    m_commandDirectQueue->ExecuteCommandList(
        {
          m_commandDirectList.GetPtr()
        });

    m_commandDirectQueue->Signal(m_swapChain->GetCurrentFence(), frameIndex);

    m_swapChain->Present(0, 0);
  }
}
