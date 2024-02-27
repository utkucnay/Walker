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

  class CommandAllocatorBuilder : Builder<
                                  CommandAllocator,
                                  mem::Visitor<Device>>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(CommandList::Type listType);

  public:
    CommandAllocator*             BuildRaw  (mem::Visitor<Device> device) override;
    mem::Ref<CommandAllocator>    BuildRef  (mem::Visitor<Device> device) override;
    mem::Scope<CommandAllocator>  BuildScope(mem::Visitor<Device> device) override;

  private:
    CommandList::Type m_commandListType;
  };

  class CommandAllocatorFactory : Factory<
                                    CommandAllocator,
                                    mem::Visitor<Device>,
                                    CommandList::Type>
  {
  public:
    CommandAllocator*             CreateFactoryRaw  (
        mem::Visitor<Device>  device,
        CommandList::Type     listType) override;

    mem::Ref<CommandAllocator>    CreateFactoryRef  (
        mem::Visitor<Device>  device,
        CommandList::Type     listType) override;

    mem::Scope<CommandAllocator>  CreateFactoryScope(
        mem::Visitor<Device>  device,
        CommandList::Type listType) override;
  };
}
