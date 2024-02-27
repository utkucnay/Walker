#pragma once

#include <Render/SwapChain.h>
#include <Core/Window.h>
#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    Renderer(Window* window);
    ~Renderer();

  public:
    void RenderScene();

  private:
    mem::Ref<Device> m_device;

    mem::Ref<CommandAllocator>  m_commandAllocator[3];
    mem::Ref<CommandList>       m_commandList;
    mem::Ref<CommandQueue>      m_commandQueue;

    mem::Ref<SwapChain> m_swapChain;
  };
}
