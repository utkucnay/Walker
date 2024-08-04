#pragma once

namespace wkr::render
{
  enum class EScanlineOrder
  {
    Unspecified         = 0,
    Progressive         = 1,
    UpperFieldFirst     = 2,
    LowerFieldFirst     = 3,
  };

  enum class EScaling
  {
    Unspecified  = 0,
    Centered     = 1,
    Stretched    = 2,
  };

  struct FRational
  {
    u32 m_numerator;
    u32 m_denominator;
  };

  enum class EFenceFlag
  {
    None                = 0,
    Shared              = 0x1,
    SharedCrossAdapter  = 0x2,
    NonMonitored        = 0x4
  };

  enum class ERootSignatureType
  {
    DescriptorTable = 0,
    Constants,
    CBV,
    SRV,
    UAV
  };

  enum class ERootSignatureVisibilty
  {
    All             = 0,
    Vertex          = 1,
    Hull            = 2,
    Domain          = 3,
    Geometry        = 4,
    Pixel           = 5,
    Amplification   = 6,
    Mesh            = 7,
  };

  enum class ERootSignatureFlag
  {
    None                                = 0,
    AllowInputAssemblerInputLayout      = 0x1,
    DenyVertexShaderRootAccess          = 0x2,
    DenyHullShaderRootAccess            = 0x4,
    DenyDomainShaderRootAccess          = 0x8,
    DenyGeometryShaderRootAccess        = 0x10,
    DenyPixelShaderRootAccess           = 0x20,
    AllowStreamOutput                   = 0x40,
  };

  enum class ESwapChainEffect
  {
    Discard         = 0,
    Sequential      = 1,
    FlipSequential  = 3,
    FlipDiscard     = 4,
  };

  enum class ESwapChainFlag : u32
  {
    Nonprerotated                         = 1,
    AllowModeSwitch                       = 2,
    GDICompatible                         = 4,
    RestrictedContent                     = 8,
    RestrictSharedResourceDriver          = 16,
    DisplayOnly                           = 32,
    FrameLatencyWaitableObject            = 64,
    ForegroundLayer                       = 128,
    FullscreenVideo                       = 256,
    YuvVideo                              = 512,
    HWProtected                           = 1024,
    AllowTearing                          = 2048,
    RestrictedToAllHolographicDisplays    = 4096,
  };

  enum class EVsyncDesc : u8
  {
    None            = 0,
    DoubleBuffering = 1,
    TripleBuffering = 2,
  };

  struct FColor32
  {
    FColor32() : m_r(0), m_g(0), m_b(0), m_a(0) {}
    FColor32(
        u8 r,
        u8 g,
        u8 b,
        u8 a)
      : m_r(r),
        m_g(g),
        m_b(b),
        m_a(a) {}

    u8 m_r;
    u8 m_g;
    u8 m_b;
    u8 m_a;
  };

  struct FSample
  {
    u32 count;
    u32 quality;

    FSample()
    {
      count = 1;
      quality = 0;
    }

    FSample(u32 count, u32 quality)
    {
      this->count = count;
      this->quality = quality;
    }
  };

  struct FLuid
  {
    u64 lowPart;
    i64 highPart;
  };
}
