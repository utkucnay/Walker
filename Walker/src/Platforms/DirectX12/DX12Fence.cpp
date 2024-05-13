#pragma once

#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  UDX12Fence::UDX12Fence(FenceBuilder& fb)
  {
    CreateWithBuilder(*this, fb);
  }

  UDX12Fence::~UDX12Fence()
  {
    for(int i = 0; i < m_fence.size(); i++)
      m_fence[i]->Release();
  }

  void UDX12Fence::FenceEvent(int frameIndex)
  {
    if(m_fence[frameIndex]->GetCompletedValue() < m_fenceValue[frameIndex])
    {
      HRESULT hr = m_fence[frameIndex]->
        SetEventOnCompletion(m_fenceValue[frameIndex], m_fenceEvent);
      WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Set Fence Event");
      WaitForSingleObject(m_fenceEvent, INFINITE);
    }
    IncFenceValue(frameIndex);
  }

  void UDX12Fence::Clone(IFence& fence)
  {
    auto dx12Fence = static_cast<UDX12Fence&>(fence);

    CreateWithBuilder(
        dx12Fence,
        mem::Scope<FenceBuilder>::Create()
        ->SetFrameCount(2)
        .SetFenceFlag(IFence::Flag::None)
        );
  }

  void UDX12Fence::CreateWithBuilder(UDX12Fence& fence, FenceBuilder& fb)
  {
    auto nDevice = (ID3D12Device*)URenderer::GetDefaultDevice().GetNativeHandle();

    for(int i = 0; i < fb.m_frameCount; i++)
    {
      fence.m_fence.push_back(NULL);
      fence.m_fenceValue.push_back(0);

      HRESULT hr = nDevice->CreateFence(
          0,
          static_cast<D3D12_FENCE_FLAGS>(fb.m_fenceFlag),
          IID_PPV_ARGS(&fence.m_fence[i]));

      WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Fence");
      WKR_CORE_LOG("Created DX12 Fence");
    }

    fence.m_fenceEvent = NULL;
    fence.m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

    fence.m_flag = fb.m_fenceFlag;

    WKR_CORE_ERROR_COND(fence.m_fenceEvent == NULL, "Didn't Create DX12 Fence Event");
    WKR_CORE_LOG("Created DX12 Fence Event");
  }
}
