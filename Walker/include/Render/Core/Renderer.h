#pragma once

#include "Render/Resource/Buffers.h"
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
    void CreateResource();
    void LoadResources();

  private:
    mem::Scope<Device> m_device;

    std::vector<mem::Scope<CommandAllocator>>  m_commandDirectAllocator;
    mem::Scope<CommandList>       m_commandDirectList;
    mem::Scope<CommandQueue>      m_commandDirectQueue;


    std::vector<mem::Scope<CommandAllocator>>  m_commandCopyAllocator;
    mem::Scope<CommandList>       m_commandCopyList;
    mem::Scope<CommandQueue>      m_commandCopyQueue;

    mem::Ref<SwapChain> m_swapChain;

    mem::Scope<rsc::Buffers> m_vertexBuffer;
    mem::Scope<rsc::Buffers> m_vertexUploadBuffer;

    //std::queue<ResourceLoadCommand> m_resourceCommandLoad;
  public:
    static Device* GetDefaultDevice() { return s_defaultDevice.Get(); }

  private:
    static inline mem::Scope<Device> s_defaultDevice;
  };
}
