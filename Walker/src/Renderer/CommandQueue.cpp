#pragma once

#include <Render/Command.h>
#include <Render/RendererMakro.h>

#include <Platforms/DirectX12/DX12.h>

namespace wkr::render
{
  //Builder
  CommandQueueBuilder& CommandQueueBuilder::SetCommandListType(
      CommandList::Type listType)
  {
    m_commandListType = listType;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueuePriority(
      CommandQueue::Priority priority)
  {
    m_commandQueuePriority = priority;
    return *this;
  }

  CommandQueueBuilder& CommandQueueBuilder::SetCommandQueueFlags(
      CommandQueue::Flags flags)
  {
    m_commandQueueFlags = flags;
    return *this;
  }

  CommandQueue* CommandQueueBuilder::BuildRaw (mem::Ref<Device> device)
  {
    return mem::Scope<CommandQueueFactory>::Create()->CreateFactoryRaw(
        device,
        {m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags});
  }

  mem::Ref<CommandQueue> CommandQueueBuilder:: BuildRef (mem::Ref<Device> device)
  {
    return mem::Scope<CommandQueueFactory>::Create()->CreateFactoryRef(
        device,
        {m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags});
  }

  mem::Scope<CommandQueue>CommandQueueBuilder:: BuildScope (mem::Ref<Device> device)
  {
    return mem::Scope<CommandQueueFactory>::Create()->CreateFactoryScope(
        device,
        {m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags});
  }

  //Factory
  CommandQueue* CommandQueueFactory::CreateFactoryRaw(
      mem::Ref<Device> device,
      const CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandQueue(device, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandQueue> CommandQueueFactory::CreateFactoryRef(
      mem::Ref<Device> device,
      const CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Ref<DX12CommandQueue>::Create(device, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandQueue> CommandQueueFactory::CreateFactoryScope(
      mem::Ref<Device> device,
      const CommandQueueDesc& desc)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        Scope<DX12CommandQueue>::Create(device, desc))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
