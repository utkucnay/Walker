#pragma once

#include <Platforms/DirectX12/Core/DX12Fence.h>
#include <Render/Core/Renderer.h>

namespace wkr::render::dx12
{
  UFence::UFence(FFenceDesc& fb)
  {
  }

  UFence::~UFence()
  {
    for(int i = 0; i < m_fence.size(); i++)
      m_fence[i]->Release();
  }

  void UFence::FenceEvent(int frameIndex)
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
