#pragma once

#include <Render/Renderer.h>
#include <Core/Window.h>

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>

#include <combaseapi.h>

namespace wkr::render
{
  class DX12Renderer : public Renderer
  {
  public:
    DX12Renderer(Window* window);
    ~DX12Renderer();

  public:
    void Render() override;
    void SwapChain() override;

  private:
    void UpdatePipeline();
    void WaidForPreviousFrame();

  private:
    constexpr static int frameBufferCount = 3;

    ID3D12Device* m_device;
    IDXGISwapChain3* m_swapChain;
    ID3D12CommandQueue* m_commandQueue;
    ID3D12DescriptorHeap* m_rtvDescriptorHeap;
    ID3D12Resource* m_renderTargets[frameBufferCount];
    ID3D12CommandAllocator* m_commandAllocator[frameBufferCount];
    ID3D12GraphicsCommandList* m_commandList;
    ID3D12Fence* m_fence;

    HANDLE m_fenceEvent;
    UINT64 fenceValue[frameBufferCount];

    int frameIndex;
    int rtvDescriptorSize;
  };
}
