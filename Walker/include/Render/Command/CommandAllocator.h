#pragma once

#include <Render/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class Device;

  class CommandAllocator
  {
  public:
    virtual ~CommandAllocator() = 0;

  public:
    virtual void* GetNativeHandle() = 0;

  public:
    CommandList::Type listType;
  };

  class CommandAllocatorBuilder : Builder<CommandAllocator, Device*>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(CommandList::Type listType);

  public:
    CommandAllocator*             BuildRaw  (Device* device) override;
    mem::Ref<CommandAllocator>    BuildRef  (Device* device) override;
    mem::Scope<CommandAllocator>  BuildScope(Device* device) override;

  private:
    CommandList::Type m_commandListType;
  };

  class CommandAllocatorFactory : Factory<
                                    CommandAllocator,
                                    Device*,
                                    CommandList::Type>
  {
  public:
    CommandAllocator*             CreateFactoryRaw  (
        Device*           device,
        CommandList::Type listType) override;

    mem::Ref<CommandAllocator>    CreateFactoryRef  (
        Device*           device,
        CommandList::Type listType) override;

    mem::Scope<CommandAllocator>  CreateFactoryScope(
        Device*           device,
        CommandList::Type listType) override;
  };
}
