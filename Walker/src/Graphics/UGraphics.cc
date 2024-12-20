#include "Graphics/Core/UGraphics.h"
#include "Graphics/Core/GraphicsType.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Command/CommandType.h"
#include "Graphics/RHI/Core/IFence.h"
#include "Graphics/RHI/Resource/ResourceType.h"
#include "Graphics/Resource/Barrier/UTransitionBarrier.h"
#include "Graphics/Resource/UTexture1D.h"
#include "OS/Window/AWindow.h"

namespace wkr::graphics {

UGraphics::UGraphics(FGraphicsDesc& desc) {

  UGraphicsAPI::Init(UGraphicsAPI::EType::DirectX12);

  auto& renderFactory = UGraphicsAPI::GetAbstractFactory();

  rhi::FDeviceDesc deviceDesc = {.Adapter = nullptr };
  m_Device = rhi::IDeviceHandle(renderFactory.GetIDevice()->Create(deviceDesc));
  s_defaultDevice = m_Device;

  rhi::FCommandQueueDesc commandQueueDesc = {
      .CommandType = rhi::ECommandType::kDirect,
      .CommandQueuePriority = rhi::ECommandQueuePriority::kNormal,
      .CommandQueueFlag = rhi::ECommandQueueF::kNone};
  m_DirectCommand.CommandQueue =
      rhi::ICommandQueueHandle(renderFactory.GetICommandQueue()->Create(commandQueueDesc));

  os::FWindowDesc windowDesc = desc.Window->GetDesc();

  rhi::FSwapChainDesc swapChainDesc = {
      .BufferCount = 3,
      .SampleDesc = {.Count = 1, .Quality = 0},
      .SwapEffect = ESwapChainEffect::kFlipDiscard,
      .Window = desc.Window,
      .BufferDesc =
          {
              .Width = windowDesc.Width,
              .Height = windowDesc.Height,
              .RefreshRate = {.Numerator = 0, .Denominator = 1},
              .Format = EResourceFormat::kR8G8B8A8_UNORM,
          },
      .BufferUsage = EResourceUsageF::kRENDER_TARGET_OUTPUT,
      .CommandQueue = m_DirectCommand.CommandQueue,
  };

  m_SwapChain = rhi::ASwapChainHandle(renderFactory.GetASwapChain()->Create(swapChainDesc));

  rhi::FCommandAllocatorDesc commandAllocatorDesc = {
      .CommandType = rhi::ECommandType::kDirect,
  };

  for (u32 i = 0; i < swapChainDesc.BufferCount; i++)
    m_DirectCommand.CommandAllocator.push_back(
        rhi::ICommandAllocatorHandle(renderFactory.GetICommandAllocator()->Create(commandAllocatorDesc)));

  rhi::FCommandListDesc commandListDesc = {
      .CommandType = rhi::ECommandType::kDirect,
      .CommandAllocator = m_DirectCommand.CommandAllocator[0],
  };

  m_DirectCommand.CommandList =
      rhi::ICommandListHandle(renderFactory.GetICommandList()->Create(commandListDesc));

  rhi::FFenceDesc fenceDesc = {
      .FrameCount = m_SwapChain->GetBufferCount(),
      .Flag = EFenceF::kNone,
  };

  m_FenceHandle = rhi::AFenceHandle(renderFactory.GetAFence()->Create(fenceDesc));

}

void UGraphics::CreateResource() {

    FBufferDesc bufferDesc = {.HeapType = EHeapType::kDefault,
                              .BufferSize = WKR_KB(20),
                              .InitState = EResourceStateF::kCommon,
                              .ResourceFlag = EResourceF::kNone};

    m_VertexBuffer = std::move(UBuffer(bufferDesc));

    FTexture1DDesc texDesc = {
      .ResourceFormat = EResourceFormat::kR8G8B8A8_UINT,
      .Width = 20,
      .MipLevels = 0,
    };

    UTexture1D tex1d(texDesc);
}

void UGraphics::LoadResources() {}

UGraphics::~UGraphics() {
  for (uint32_t i = 0; i < m_SwapChain->GetBufferCount(); i++) {
    u32 frameIndex = m_SwapChain->GetFrameIndex();
    m_FenceHandle->FenceEvent(frameIndex);
  }

  m_Device.Reset();
  s_defaultDevice.Reset();
  m_SwapChain.Reset();
  m_DirectCommand.CommandQueue.Reset();
  m_DirectCommand.CommandList.Reset();

  for (int i = 0; i < m_DirectCommand.CommandAllocator.size(); i++)
    m_DirectCommand.CommandAllocator[i].Reset();

  UGraphicsAPI::Destroy();
}

void UGraphics::Render() {
  URenderTargetView renderTarget = m_SwapChain->GetCurrentRenderTarget();
  u32 frameIndex = m_SwapChain->GetFrameIndex();

  m_DirectCommand.CommandAllocator[frameIndex]->Reset();

  m_DirectCommand.CommandList->Reset(
      m_DirectCommand.CommandAllocator[frameIndex].Get(), nullptr);

  FTransitionBarrierDesc transitionBarrierDesc = {
      .Resource = renderTarget.GetTexture2D().GetResource(),
      .BeforeState = EResourceStateF::kRenderTarget,
      .AfterState = EResourceStateF::kPresent,
  };

  UTransitionBarrier rtvTransitionBarrier(transitionBarrierDesc);

  m_DirectCommand.CommandList->ResourceBarriers(
      {rtvTransitionBarrier.GetResourceBarrier().GetPtr()});

  m_DirectCommand.CommandList->OMSetRenderTargets({renderTarget});

  m_DirectCommand.CommandList->ClearRenderTargetView(renderTarget,
                                                     FColor32(0, 255, 0, 255));

  FTransitionBarrierDesc revTransitionBarrierDesc = {
      .Resource = renderTarget.GetTexture2D().GetResource(),
      .BeforeState = EResourceStateF::kPresent,
      .AfterState = EResourceStateF::kRenderTarget,
  };

  UTransitionBarrier revRtvTransitionBarrier(revTransitionBarrierDesc);

  m_DirectCommand.CommandList->ResourceBarriers(
      {revRtvTransitionBarrier.GetResourceBarrier().GetPtr()});

  m_DirectCommand.CommandList->Close();

  m_DirectCommand.CommandQueue->ExecuteCommandList(
      {m_DirectCommand.CommandList.GetPtr()});

  m_DirectCommand.CommandQueue->Signal(m_FenceHandle.Get(), frameIndex);

  m_SwapChain->Present(0, 0);
}

void UGraphics::SwapBuffers() {
  m_SwapChain->SwapBuffers();
}

void UGraphics::Fence() {
  u32 frameIndex = m_SwapChain->GetFrameIndex();
  m_FenceHandle->FenceEvent(frameIndex);
  m_FenceHandle->IncreaseFenceValue(frameIndex);
}

}  // namespace wkr::graphics
