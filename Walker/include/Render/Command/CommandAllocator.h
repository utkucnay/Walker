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
    CommandAllocator(mem::Visitor<CommandAllocatorBuilder> cab);
    virtual ~CommandAllocator() = 0;

  public:
    virtual void* GetNativeHandle() = 0;

  protected:
    CommandList::Type m_listType;
  };

  class CommandAllocatorBuilder : Builder<
                                  CommandAllocator,
                                  mem::Visitor<Device>>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(CommandList::Type listType);

  public:
    CommandAllocator*             BuildRaw  (
        mem::Visitor<Device> device) override final;
    mem::Ref<CommandAllocator>    BuildRef  (
        mem::Visitor<Device> device) override final;
    mem::Scope<CommandAllocator>  BuildScope(
        mem::Visitor<Device> device) override final;

  private:
    CommandList::Type m_commandListType{};

    friend class CommandAllocator;
  };

  class CommandAllocatorFactory : Factory<
                                    CommandAllocator,
                                    mem::Visitor<Device>,
                                    mem::Visitor<CommandAllocatorBuilder>>
  {
  public:
    CommandAllocator*             CreateFactoryRaw  (
        mem::Visitor<Device>                  device,
        mem::Visitor<CommandAllocatorBuilder> listType) override final;

    mem::Ref<CommandAllocator>    CreateFactoryRef  (
        mem::Visitor<Device>                  device,
        mem::Visitor<CommandAllocatorBuilder> listType) override final;

    mem::Scope<CommandAllocator>  CreateFactoryScope(
        mem::Visitor<Device>                  device,
        mem::Visitor<CommandAllocatorBuilder> listType) override final;
  };
}
