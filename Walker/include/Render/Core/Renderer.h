#pragma once

#include <Render/Core/SwapChain.h>
#include <Core/Window.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    Renderer(Window* window);
    ~Renderer();

  public:
    void Render();
    void CreateSwapChain(Window* window);

  private:
    mem::Scope<Device> m_device;

    std::vector<mem::Scope<CommandAllocator>>  m_commandAllocator;
    mem::Scope<CommandList>       m_commandList;
    mem::Scope<CommandQueue>      m_commandQueue;

    mem::Ref<SwapChain> m_swapChain;

  public:
    static Device* GetDefaultDevice() { return s_defaultDevice.Get(); }

  private:
    static inline mem::Scope<Device> s_defaultDevice;
  };
}
