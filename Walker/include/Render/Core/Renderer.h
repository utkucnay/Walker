#pragma once

#include <Render/Core/SwapChain.h>
#include <Core/Window.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    Renderer();
    ~Renderer();

  public:
    void Render(mem::Visitor<Window> window);
    void CreateSwapChain(mem::Visitor<Window> window);

  private:
    mem::Scope<Device> m_device;

    mem::Scope<CommandAllocator>  m_commandAllocator[3];
    mem::Scope<CommandList>       m_commandList;
    mem::Scope<CommandQueue>      m_commandQueue;

    std::vector<mem::Ref<SwapChain>> m_swapChain;
  };
}
