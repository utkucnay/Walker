#pragma once

#include <Render/Command/Command.h>
#include <Render/Core/Device.h>

#if !defined (COMMAND_INCLUDE_BARRIER)
  #error "Command Didn't Include Correctly"
#endif

namespace wkr::render
{
  class ICommandAllocator : public ICloneable<ICommandAllocator>
  {
  public:
    virtual ~ICommandAllocator() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
    virtual ICommandList::Type GetCommandListType() = 0;
    virtual void Reset() = 0;
  };

  class CommandAllocatorBuilder : IBuilder<ICommandAllocator>
  {
  public:
    CommandAllocatorBuilder& SetCommandListType(ICommandList::Type listType);

  public:
    [[nodiscard]] ICommandAllocator*             BuildRaw  () override final;
    [[nodiscard]] mem::Ref<ICommandAllocator>    BuildRef  () override final;
    [[nodiscard]] mem::Scope<ICommandAllocator>  BuildScope() override final;

  public:
    ICommandList::Type m_listType{};
  };
}
