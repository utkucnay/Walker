#pragma once

#include <Render/Command/CommandQueue.h>
#include <Render/Core/RendererMakro.h>

namespace wkr::render
{
  CommandQueue::~CommandQueue()
  {

  }

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

  CommandQueue* CommandQueueBuilder::BuildRaw(
      mem::Visitor<Device> device)
  {
    auto ret = mem::Scope<CommandQueueFactory>::Create()->CreateFactoryRaw(
        device,
        m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags);
    ret->m_listType = m_commandListType;
    ret->m_priority = m_commandQueuePriority;
    ret->m_flags = m_commandQueueFlags;
    return ret;
  }

  mem::Ref<CommandQueue> CommandQueueBuilder::BuildRef(
      mem::Visitor<Device> device)
  {
    auto ret = mem::Scope<CommandQueueFactory>::Create()->CreateFactoryRef(
        device,
        m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags);
    ret->m_listType = m_commandListType;
    ret->m_priority = m_commandQueuePriority;
    ret->m_flags = m_commandQueueFlags;
    return ret;
  }

  mem::Scope<CommandQueue>CommandQueueBuilder::BuildScope(
      mem::Visitor<Device> device)
  {
    auto ret = mem::Scope<CommandQueueFactory>::Create()->CreateFactoryScope(
        device,
        m_commandListType,
        m_commandQueuePriority,
        m_commandQueueFlags);
    ret->m_listType = m_commandListType;
    ret->m_priority = m_commandQueuePriority;
    ret->m_flags = m_commandQueueFlags;
    return ret;
  }

  //Factory
  CommandQueue* CommandQueueFactory::CreateFactoryRaw(
      mem::Visitor<Device>    device,
      CommandList::Type       commandType,
      CommandQueue::Priority  queuePriorty,
      CommandQueue::Flags     flags)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        new DX12CommandQueue(
          device,
          commandType,
          queuePriorty,
          flags))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Ref<CommandQueue> CommandQueueFactory::CreateFactoryRef(
      mem::Visitor<Device>    device,
      CommandList::Type       commandType,
      CommandQueue::Priority  queuePriorty,
      CommandQueue::Flags     flags)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Ref<DX12CommandQueue>::Create(
          device,
          commandType,
          queuePriorty,
          flags))
    END_RENDERERAPI_CREATE()
    return NULL;
  }

  mem::Scope<CommandQueue> CommandQueueFactory::CreateFactoryScope(
      mem::Visitor<Device>    device,
      CommandList::Type       commandType,
      CommandQueue::Priority  queuePriorty,
      CommandQueue::Flags     flags)
  {
    BEGIN_RENDERERAPI_CREATE()
    ADD_RENDERERAPI_DIRECTX12_CREATE(
        mem::Scope<DX12CommandQueue>::Create(
          device,
          commandType,
          queuePriorty,
          flags))
    END_RENDERERAPI_CREATE()
    return NULL;
  }
}
