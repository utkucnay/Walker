#pragma once

#include <Render/Device.h>

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

  class CommandAllocatorBuilder : Builder<CommandAllocator, mem::Ref<Device>>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(CommandList::Type listType);

  public:
    CommandAllocator*             BuildRaw  (mem::Ref<Device> device) override;
    mem::Ref<CommandAllocator>    BuildRef  (mem::Ref<Device> device) override;
    mem::Scope<CommandAllocator>  BuildScope(mem::Ref<Device> device) override;

  private:
    CommandList::Type m_commandListType;
  };

  class CommandAllocatorFactory : Factory<
                                    CommandAllocator,
                                    mem::Ref<Device>,
                                    CommandList::Type>
  {
  public:
    CommandAllocator*             CreateFactoryRaw  (
        mem::Ref<Device>     device,
        CommandList::Type listType) override;

    mem::Ref<CommandAllocator>    CreateFactoryRef  (
        mem::Ref<Device>     device,
        CommandList::Type listType) override;

    mem::Scope<CommandAllocator>  CreateFactoryScope(
        mem::Ref<Device>     device,
        CommandList::Type listType) override;
  };
}
