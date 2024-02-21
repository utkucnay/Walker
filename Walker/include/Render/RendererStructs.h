#pragma once

namespace wkr::render
{
  struct Rational
  {
    uint32_t Numerator;
    uint32_t Denominator;
  };

  enum class Usage
  {
    DXGI_CPU_ACCESS_NONE                = 0,
    DXGI_CPU_ACCESS_DYNAMIC             = 1,
    DXGI_CPU_ACCESS_READ_WRITE          = 2,
    DXGI_CPU_ACCESS_SCRATCH             = 3,
    DXGI_CPU_ACCESS_FIELD               = 15,
    DXGI_USAGE_SHADER_INPUT             = 1L << (0 + 4),
    DXGI_USAGE_RENDER_TARGET_OUTPUT     = 1L << (1 + 4),
    DXGI_USAGE_BACK_BUFFER              = 1L << (2 + 4),
    DXGI_USAGE_SHARED                   = 1L << (3 + 4),
    DXGI_USAGE_READ_ONLY                = 1L << (4 + 4),
    DXGI_USAGE_DISCARD_ON_PRESENT       = 1L << (5 + 4),
    DXGI_USAGE_UNORDERED_ACCESS         = 1L << (6 + 4)
  };

  enum class Format
  {
    Unkown                  = 0,
    R32G32B32A32_Typeless   = 1,
    R32G32B32A32_Float      = 2,
    R32G32B32A32_UInt       = 3,
    R32G32B32A32_SInt       = 4,
    R32G32B32_Typeless      = 5,
    R32G32B32_Float         = 6,
    R32G32B32_UInt          = 7,
    R32G32B32_SInt          = 8,
    R16G16B16A16_Typeless   = 9,
    R16G16B16A16_Float      = 10,
    R16G16B16A16_UNorm      = 11,
    R16G16B16A16_UInt       = 12,
    R16G16B16A16_SNorm      = 13,
    R16G16B16A16_SInt       = 14
  };

  enum class ScanlineOrder
  {
    Unspecified         = 0,
    Progressive         = 1,
    UpperFieldFirst     = 2,
    LowerFieldFirst     = 3
  };

  enum class Scaling
  {
    Unspecified  = 0,
    Centered     = 1,
    Stretched    = 2
  };

  struct ModeDesc
  {
    uint32_t      width;
    uint32_t      height;
    Rational      refreshRate;
    Format        format;
    ScanlineOrder scanlineOrdering;
    Scaling       scaling;
  };

  struct SampleDesc
  {
    uint32_t count;
    uint32_t quality;
  };

}
