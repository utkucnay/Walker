#pragma once

#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Render/Core/Renderer.h>

namespace wkr::render
{
  DX12Fence::DX12Fence(FenceBuilder* fb)
  {
    ID3D12Device* nDevice = (ID3D12Device*)Renderer::GetDefaultDevice()->GetNativeHandle();

    for(int i = 0; i < fb->m_frameCount; i++)
    {
      m_fence.push_back(NULL);
      m_fenceValue.push_back(0);

      HRESULT hr = nDevice->CreateFence(
          0,
          static_cast<D3D12_FENCE_FLAGS>(fb->m_fenceFlag),
          IID_PPV_ARGS(&m_fence[i]));

      WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Fence");
      WKR_CORE_LOG("Created DX12 Fence");
    }

    m_fenceEvent = NULL;
    m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

    WKR_CORE_ERROR_COND(m_fenceEvent == NULL, "Didn't Create DX12 Fence Event");
    WKR_CORE_LOG("Created DX12 Fence Event");
  }

  DX12Fence::~DX12Fence()
  {
    for(int i = 0; i < m_fence.size(); i++)
      m_fence[i]->Release();
  }

  void DX12Fence::FenceEvent(int frameIndex)
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
}
