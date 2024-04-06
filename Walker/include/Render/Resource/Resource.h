#pragma once

#include <Render/Core/RendererStructs.h>

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

    enum class Dimension
    {
      Unknown   = 0,
      Buffer    = 1,
      Texture1D = 2,
      Texture2D = 3,
      Texture3D = 4,
    };

    enum class Flag
    {
      None = 0,
      AllowRenderTarget = 0x1,
      AllowDepthStencil = 0x2,
      AllowUnorderedAccess = 0x4,
      DenyShaderResource = 0x8,
      AllowCrossAdapter = 0x10,
      AllowSimultaneousAccess = 0x20,
      VideoDecodeReferenceOnly = 0x40,
      VideoEncodeReferenceOnly = 0x80,
      RaytracingAccelerationStructure = 0x100
    };

    struct ClearValue
    {
      Format format;
      union
      {
        Color32 color;
        struct
        {
          float depth;
          uint8_t stencil;
        } depthStencil;
      };

      ClearValue() { format = Format::UNKNOWN; color = Color32(0,0,0,0); }
    };

  public:
    virtual ~Resource() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual Resource::State GetState() = 0;

    virtual std::string GetTypeName() = 0;
  };

}
