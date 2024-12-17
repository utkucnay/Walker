#pragma once

#include "Platforms/DirectX12/Core/DX12Fence.h"
#include <string>
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UFence::UFence(FFenceDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  for (int i = 0; i < desc.FrameCount; i++) {
    u64 initialFenceValue = 0;
    m_Fence.push_back(nullptr);
    m_FenceValue.push_back(initialFenceValue);

    HRESULT hr = nDevice->CreateFence(initialFenceValue,
                                      wkrtodx12::ConvertEFenceF(desc.Flag),
                                      IID_PPV_ARGS(&m_Fence[i]));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Fence");
    WKR_CORE_LOG("Created DX12 Fence");
  }

  m_FenceEvent = nullptr;
  m_FenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

  m_Desc = desc;

  WKR_CORE_ERROR_COND(m_FenceEvent == nullptr,
                      "Didn't Create DX12 Fence Event");
  WKR_CORE_LOG("Created DX12 Fence Event");
}

UFence::~UFence() {
  for (int i = 0; i < m_Fence.size(); i++)
    m_Fence[i]->Release();
}

FFenceDesc UFence::GetDesc() {
  return m_Desc;
}

void UFence::FenceEvent(int frameIndex) {
  WKR_CORE_LOG(<< std::to_string(m_Fence[frameIndex]->GetCompletedValue())
               << " " << std::to_string(m_FenceValue[frameIndex]))
  if (m_Fence[frameIndex]->GetCompletedValue() >= m_FenceValue[frameIndex]) {
    return;
  }

  HRESULT hr = m_Fence[frameIndex]->SetEventOnCompletion(
      m_FenceValue[frameIndex], m_FenceEvent);

  WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Set Fence Event");

  WaitForSingleObject(m_FenceEvent, INFINITE);
}

}  // namespace wkr::graphics::rhi::dx12
