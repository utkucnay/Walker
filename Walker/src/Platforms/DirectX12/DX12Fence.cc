#pragma once

#include "Platforms/DirectX12/Core/DX12Fence.h"
#include "Graphics/Core/UGraphics.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"

namespace wkr::graphics::rhi::dx12 {

UFence::UFence(const FFenceDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  for (int i = 0; i < desc.FrameCount; i++) {
    u64 initialFenceValue = 0;
    m_Fence.push_back(nullptr);
    m_FenceValue.push_back(initialFenceValue);

    HRESULT hr = nDevice->CreateFence(initialFenceValue,
                                      wkrtodx12::ConvertEFenceF(desc.Flag),
                                      IID_PPV_ARGS(&m_Fence[i]));
    if (FAILED(hr)) {
      WKR_CORE_WARNING("Didn't Create DX12 Fence");
      WKR_DX12_ERROR(hr);
    }

    WKR_CORE_LOG("Created DX12 Fence");
  }

  m_FenceEvent = nullptr;
  m_FenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

  m_Desc = desc;

  if (m_FenceEvent == nullptr) {
    WKR_CORE_WARNING("Didn't Create DX12 Fence Event");
    WKR_DX12_ERROR(S_FALSE);
  }

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
  if (m_Fence[frameIndex]->GetCompletedValue() >= m_FenceValue[frameIndex]) {
    return;
  }

  HRESULT hr = m_Fence[frameIndex]->SetEventOnCompletion(
      m_FenceValue[frameIndex], m_FenceEvent);

  if (FAILED(hr)) {
    WKR_CORE_WARNING("Didn't Set Fence Event");
    WKR_DX12_ERROR(hr);
  }

  WaitForSingleObject(m_FenceEvent, INFINITE);
}

}  // namespace wkr::graphics::rhi::dx12
