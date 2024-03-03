#pragma once

#include <Render/Core/Device.h>

namespace wkr::render
{
  class Device;
  class FenceBuilder;

  class Fence
  {
  public:
    enum class Flag
    {
      None                = 0,
      Shared              = 0x1,
      SharedCrossAdapter  = 0x2,
      NonMonitored        = 0x4
    };

  public:
    Fence(mem::Visitor<FenceBuilder> fb);
    virtual ~Fence() = 0;

  public:
    Fence::Flag GetFlag() const { return m_flag; }

  public:
    virtual void FenceEvent() = 0;
    virtual void* GetNativeHandle();

  protected:
    Fence::Flag m_flag;
  };

  class FenceBuilder : Builder<Fence, mem::Visitor<Device>>
  {
  public:
    FenceBuilder* SetFenceFlag(Fence::Flag fenceFlag);

    Fence*            BuildRaw  (mem::Visitor<Device> device) override;
    mem::Ref<Fence>   BuildRef  (mem::Visitor<Device> device) override;
    mem::Scope<Fence> BuildScope(mem::Visitor<Device> device) override;

  private:
    Fence::Flag m_fenceFlag{};

    friend class Fence;
  };

  class FenceFactory : Factory<
                       Fence,
                       mem::Visitor<Device>,
                       mem::Visitor<FenceBuilder>>
  {
  public:
    Fence*            CreateFactoryRaw(
        mem::Visitor<Device> device,
        mem::Visitor<FenceBuilder> fb) override;

    mem::Ref<Fence>   CreateFactoryRef  (
        mem::Visitor<Device> device,
        mem::Visitor<FenceBuilder> fb) override;

    mem::Scope<Fence> CreateFactoryScope(
        mem::Visitor<Device> device,
        mem::Visitor<FenceBuilder> fb) override;
  };
}
