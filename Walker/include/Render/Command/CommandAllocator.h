#pragma once

#include <Render/Command/Command.h>
#include <Render/Core/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class Device;
  class CommandAllocatorBuilder;

  class CommandAllocator
  {
  public:
    virtual ~CommandAllocator() {}

  public:
    virtual void* GetNativeHandle() = 0;
    virtual void Reset() = 0;
  };

  class CommandAllocatorBuilder : Builder<CommandAllocator>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(CommandList::Type listType);

  public:
    CommandAllocator*             BuildRaw  () override final;
    mem::Ref<CommandAllocator>    BuildRef  () override final;
    mem::Scope<CommandAllocator>  BuildScope() override final;

  public:
    CommandList::Type m_listType{};
  };
}
