#pragma once

#include "Platforms/DirectX12/Core/DX12Fence.h"
#include "Platforms/DirectX12/Core/DX12TypeMap.h"
#include "Graphics/Core/UGraphics.h"

namespace wkr::render::dx12 {

UFence::UFence(FFenceDesc& desc) {
  ID3D12Device* nDevice = UGraphics::GetDefaultDevice().GetNativeObject();

  for (int i = 0; i < desc.m_frameCount; i++) {
    m_fence.push_back(nullptr);
    m_fenceValue.push_back(0);

    HRESULT hr = nDevice->CreateFence(0, ConvertEFenceFlags(desc.m_flag),
                                      IID_PPV_ARGS(&m_fence[i]));

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Create DX12 Fence");
    WKR_CORE_LOG("Created DX12 Fence");
  }

  m_fenceEvent = nullptr;
  m_fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);

  m_flag = desc.m_flag;

  WKR_CORE_ERROR_COND(m_fenceEvent == nullptr,
                      "Didn't Create DX12 Fence Event");
  WKR_CORE_LOG("Created DX12 Fence Event");
}

UFence::~UFence() {
  for (int i = 0; i < m_fence.size(); i++)
    m_fence[i]->Release();
}

void UFence::FenceEvent(int frameIndex) {
  if (m_fence[frameIndex]->GetCompletedValue() < m_fenceValue[frameIndex]) {
    HRESULT hr = m_fence[frameIndex]->SetEventOnCompletion(
        m_fenceValue[frameIndex], m_fenceEvent);

    WKR_CORE_ERROR_COND(FAILED(hr), "Didn't Set Fence Event");

    WaitForSingleObject(m_fenceEvent, INFINITE);
  }
  IncFenceValue(frameIndex);
}

}  // namespace wkr::render::dx12
