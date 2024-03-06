#pragma once

namespace wkr::render::rsc
{
  class Resource
  {
  public:
    enum class State
    {
      Common                          = 0,
      VertextAndConstantBuffer        = 0x1,
      IndexBuffer                     = 0x2,
      RenderTarget                    = 0x4,
      UnorederedAccess                = 0x8,
      DepthWrite                      = 0x10,
      DepthRead                       = 0x20,
      NonPixelShaderResource          = 0x40,
      PixelShaderResource             = 0x80,
      StreamOut                       = 0x100,
      IndirectArgument                = 0x200,
      CopyDest                        = 0x400,
      CopySource                      = 0x800,
      ResolveDest                     = 0x1000,
      ResolveSource                   = 0x2000,
      RaytracingAccelerationStructure = 0x400000,
      ShadingRateSource               = 0x1000000,
      ReservedInternal8000,
      ReservedInternal4000,
      ReservedInternal100000,
      ReservedInternal40000000,
      ReservedInternal80000000,
      GenericRead,
      AllShaderResource,
      Present                         = 0,
      Predication                     = 0x200,
      VideoDecodeRead                 = 0x10000,
      VideoDecodeWrite                = 0x20000,
      VideoProcessRead                = 0x40000,
      VideoProcessWrite               = 0x80000,
      VideoEncodeRead                 = 0x200000,
      VideoEncodeWrite                = 0x800000,
    };

  public:
    virtual ~Resource() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual Resource::State GetState() = 0;

    virtual std::string GetTypeName() = 0;
  };
}
