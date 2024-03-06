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
    void Render(Window* window);
    void CreateSwapChain(Window* window);

  private:
    mem::Scope<Device> m_device;

    mem::Scope<CommandAllocator>  m_commandAllocator[3];
    mem::Scope<CommandList>       m_commandList;
    mem::Scope<CommandQueue>      m_commandQueue;

    std::vector<mem::Ref<SwapChain>> m_swapChain;

  public:
    static Device* GetDefaultDevice() { return s_defaultDevice.Get(); }

  private:
    static inline mem::Scope<Device> s_defaultDevice;
  };
}
