#include "Render/Resource/Buffer.h"
#include "Render/Resource/ResourceTypes.h"
#include <Render/Core/Renderer.h>
#include <Render/Core/RendererAPI.h>

namespace wkr::render
{
  URenderer::URenderer(FRendererDesc& desc)
  {
    URendererAPI::Init(URendererAPI::EType::DirectX12);

    auto& renderFactory = URendererAPI::GetAbstractFactory();

    FDeviceDesc deviceDesc = {};
    m_device = renderFactory.GetIDevice()->Create(deviceDesc);

    s_defaultDevice = m_device;

    FCommandQueueDesc commandQueueDesc = {};
    commandQueueDesc.m_commandType = ECommandType::Direct;
    commandQueueDesc.m_commandQueuePriority = ECommandQueuePriority::Normal;
    commandQueueDesc.m_commandQueueFlags = ECommandQueueFlags::None;
    m_commandDirectQueue = renderFactory.GetICommandQueue()->Create(commandQueueDesc);

    FSwapChainDesc swapChainDesc = {};
    swapChainDesc.m_window = desc.window;
    swapChainDesc.m_commandQueue = m_commandDirectQueue;
    swapChainDesc.m_bufferCount = 3;
    swapChainDesc.m_bufferUsage = EResourceUsageF::RENDER_TARGET_OUTPUT;
    swapChainDesc.m_swapEffect = ESwapChainEffect::FlipDiscard;

    swapChainDesc.m_sampleDesc.count = 1;
    swapChainDesc.m_sampleDesc.quality = 0;

    swapChainDesc.m_bufferDesc = {};
    swapChainDesc.m_bufferDesc.m_width = desc.window->GetWidth();
    swapChainDesc.m_bufferDesc.m_height = desc.window->GetHeight();
    swapChainDesc.m_bufferDesc.m_format = EResourceFormat::R8G8B8A8_UNORM;
    swapChainDesc.m_bufferDesc.m_refreshRate.m_numerator = 0;
    swapChainDesc.m_bufferDesc.m_refreshRate.m_denominator = 1;

    m_swapChain = renderFactory.GetASwapChain()->Create(swapChainDesc);
    desc.window->SetSwapChain(m_swapChain);

    FCommandAllocatorDesc commandAllocatorDesc;
    commandAllocatorDesc.commandType = ECommandType::Direct;

    for(u32 i = 0; i < m_swapChain->GetBufferCount(); i++)
      m_commandDirectAllocator.push_back(renderFactory.GetICommandAllocator()
                                         ->Create(commandAllocatorDesc));

    FCommandListDesc commandListDesc = {};
    commandListDesc.m_commandAllocator = m_commandDirectAllocator[0];
    commandListDesc.m_commandType = ECommandType::Direct;

    m_commandDirectList = renderFactory.GetICommandList()
    ->Create(commandListDesc);



    FBufferDesc bufferDesc = {};
    bufferDesc.heapType = EHeapType::Default;
    bufferDesc.initState = EResourceStateF::Common;
    bufferDesc.bufferSize = 20 KB;
    bufferDesc.resourceFlag = EResourceF::None;

    vertexBuffer = new UBuffer(bufferDesc);
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
    ARenderTargetViewHandle renderTarget = m_swapChain->GetCurrentRenderTarget();
    u32 frameIndex = m_swapChain->GetFrameIndex();

    m_commandDirectAllocator[frameIndex]->Reset();

    m_commandDirectList->Reset(m_commandDirectAllocator[frameIndex].Get(), nullptr);

    auto& renderFactory = URendererAPI::GetAbstractFactory();

    FTransitionBarrierDesc transitionBarrierDesc = {};
    transitionBarrierDesc.m_resource = renderTarget->GetTexture2D()->GetResource();
    transitionBarrierDesc.m_beforeState = EResourceStateF::RenderTarget;
    transitionBarrierDesc.m_afterState = EResourceStateF::Present;

    ITransitionBarrierHandle barrier = renderFactory.GetITransitionBarrier()
    ->Create(transitionBarrierDesc);

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


    transitionBarrierDesc.m_beforeState = EResourceStateF::Present;
    transitionBarrierDesc.m_afterState = EResourceStateF::RenderTarget;

    ITransitionBarrierHandle reverseBarrier = renderFactory.GetITransitionBarrier()
    ->Create(transitionBarrierDesc);

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
