#pragma once

#include "Graphics/Core/GraphicsType.h"

namespace wkr::graphics {

enum class WALKER_API EResourceStateF : u32 {
  kCommon = 0,
  kVertexAndConstantBuffer = 0x1,
  kIndexBuffer = 0x2,
  kRenderTarget = 0x4,
  kUnorederedAccess = 0x8,
  kDepthWrite = 0x10,
  kDepthRead = 0x20,
  kNonPixelShaderResource = 0x40,
  kPixelShaderResource = 0x80,
  kStreamOut = 0x100,
  kIndirectArgument = 0x200,
  kCopyDest = 0x400,
  kCopySource = 0x800,
  kResolveDest = 0x1000,
  kResolveSource = 0x2000,
  kRaytracingAccelerationStructure = 0x400000,
  kShadingRateSource = 0x1000000,
  kReservedInternal8000,
  kReservedInternal4000,
  kReservedInternal100000,
  kReservedInternal40000000,
  kReservedInternal80000000,
  kGenericRead,
  kAllShaderResource,
  kPresent = 0,
  kPredication = 0x200,
  kVideoDecodeRead = 0x10000,
  kVideoDecodeWrite = 0x20000,
  kVideoProcessRead = 0x40000,
  kVideoProcessWrite = 0x80000,
  kVideoEncodeRead = 0x200000,
  kVideoEncodeWrite = 0x800000
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EResourceStateF)

enum class WALKER_API EResourceFormat : u32 {
  kUNKNOWN = 0,
  kR32G32B32A32_TYPELESS = 1,
  kR32G32B32A32_FLOAT = 2,
  kR32G32B32A32_UINT = 3,
  kR32G32B32A32_SINT = 4,
  kR32G32B32_TYPELESS = 5,
  kR32G32B32_FLOAT = 6,
  kR32G32B32_UINT = 7,
  kR32G32B32_SINT = 8,
  kR16G16B16A16_TYPELESS = 9,
  kR16G16B16A16_FLOAT = 10,
  kR16G16B16A16_UNORM = 11,
  kR16G16B16A16_UINT = 12,
  kR16G16B16A16_SNORM = 13,
  kR16G16B16A16_SINT = 14,
  kR32G32_TYPELESS = 15,
  kR32G32_FLOAT = 16,
  kR32G32_UINT = 17,
  kR32G32_SINT = 18,
  kR32G8X24_TYPELESS = 19,
  kD32_FLOAT_S8X24_UINT = 20,
  kR32_FLOAT_X8X24_TYPELESS = 21,
  kX32_TYPELESS_G8X24_UINT = 22,
  kR10G10B10A2_TYPELESS = 23,
  kR10G10B10A2_UNORM = 24,
  kR10G10B10A2_UINT = 25,
  kR11G11B10_FLOAT = 26,
  kR8G8B8A8_TYPELESS = 27,
  kR8G8B8A8_UNORM = 28,
  kR8G8B8A8_UNORM_SRGB = 29,
  kR8G8B8A8_UINT = 30,
  kR8G8B8A8_SNORM = 31,
  kR8G8B8A8_SINT = 32,
  kR16G16_TYPELESS = 33,
  kR16G16_FLOAT = 34,
  kR16G16_UNORM = 35,
  kR16G16_UINT = 36,
  kR16G16_SNORM = 37,
  kR16G16_SINT = 38,
  kR32_TYPELESS = 39,
  kD32_FLOAT = 40,
  kR32_FLOAT = 41,
  kR32_UINT = 42,
  kR32_SINT = 43,
  kR24G8_TYPELESS = 44,
  kD24_UNORM_S8_UINT = 45,
  kR24_UNORM_X8_TYPELESS = 46,
  kX24_TYPELESS_G8_UINT = 47,
  kR8G8_TYPELESS = 48,
  kR8G8_UNORM = 49,
  kR8G8_UINT = 50,
  kR8G8_SNORM = 51,
  kR8G8_SINT = 52,
  kR16_TYPELESS = 53,
  kR16_FLOAT = 54,
  kD16_UNORM = 55,
  kR16_UNORM = 56,
  kR16_UINT = 57,
  kR16_SNORM = 58,
  kR16_SINT = 59,
  kR8_TYPELESS = 60,
  kR8_UNORM = 61,
  kR8_UINT = 62,
  kR8_SNORM = 63,
  kR8_SINT = 64,
  kA8_UNORM = 65,
  kR1_UNORM = 66,
  kR9G9B9E5_SHAREDEXP = 67,
  kR8G8_B8G8_UNORM = 68,
  kG8R8_G8B8_UNORM = 69,
  kBC1_TYPELESS = 70,
  kBC1_UNORM = 71,
  kBC1_UNORM_SRGB = 72,
  kBC2_TYPELESS = 73,
  kBC2_UNORM = 74,
  kBC2_UNORM_SRGB = 75,
  kBC3_TYPELESS = 76,
  kBC3_UNORM = 77,
  kBC3_UNORM_SRGB = 78,
  kBC4_TYPELESS = 79,
  kBC4_UNORM = 80,
  kBC4_SNORM = 81,
  kBC5_TYPELESS = 82,
  kBC5_UNORM = 83,
  kBC5_SNORM = 84,
  kB5G6R5_UNORM = 85,
  kB5G5R5A1_UNORM = 86,
  kB8G8R8A8_UNORM = 87,
  kB8G8R8X8_UNORM = 88,
  kR10G10B10_XR_BIAS_A2_UNORM = 89,
  kB8G8R8A8_TYPELESS = 90,
  kB8G8R8A8_UNORM_SRGB = 91,
  kB8G8R8X8_TYPELESS = 92,
  kB8G8R8X8_UNORM_SRGB = 93,
  kBC6H_TYPELESS = 94,
  kBC6H_UF16 = 95,
  kBC6H_SF16 = 96,
  kBC7_TYPELESS = 97,
  kBC7_UNORM = 98,
  kBC7_UNORM_SRGB = 99,
  kAYUV = 100,
  kY410 = 101,
  kY416 = 102,
  kNV12 = 103,
  kP010 = 104,
  kP016 = 105,
  kYUY2 = 107,
  kY210 = 108,
  kY216 = 109,
  kNV11 = 110,
  kAI44 = 111,
  kIA44 = 112,
  kP8 = 113,
  kA8P8 = 114,
  kB4G4R4A4_UNORM = 115,
  kP208 = 130,
  kV208 = 131,
  kV408 = 132,
  kSAMPLER_FEEDBACK_MIN_MIP_OPAQUE,
  kSAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE,
  kFORCE_UINT = 0xffffffff
};

enum class WALKER_API EResourceLayout {
  kUnknown = 0,
  kRowMajor = 1,
  kUndefinedSwizzle64KB = 2,
  kStandardSwizzle64KB = 3,
};

enum class WALKER_API EResourceDimension {
  kUnknown = 0,
  kBuffer = 1,
  kTexture1D = 2,
  kTexture2D = 3,
  kTexture3D = 4,
};

enum class WALKER_API EResourceF {
  kNone = 0,
  kAllowRenderTarget = 0x1,
  kAllowDepthStencil = 0x2,
  kAllowUnorderedAccess = 0x4,
  kDenyShaderResource = 0x8,
  kAllowCrossAdapter = 0x10,
  kAllowSimultaneousAccess = 0x20,
  kVideoDecodeReferenceOnly = 0x40,
  kVideoEncodeReferenceOnly = 0x80,
  kRaytracingAccelerationStructure = 0x100
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EResourceF)

enum class WALKER_API EResourceUsageF {
  kCPU_ACCESS_NONE = 0,
  kCPU_ACCESS_DYNAMIC = 1,
  kCPU_ACCESS_READ_WRITE = 2,
  kCPU_ACCESS_SCRATCH = 3,
  kCPU_ACCESS_FIELD = 15,
  kSHADER_INPUT = 0x00000010UL,
  kRENDER_TARGET_OUTPUT = 0x00000020UL,
  kBACK_BUFFER = 0x00000040UL,
  kSHARED = 0x00000080UL,
  kREAD_ONLY = 0x00000100UL,
  kDISCARD_ON_PRESENT = 0x00000200UL,
  kUNORDERED_ACCESS = 0x00000400UL
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EResourceUsageF)

struct WALKER_API FClearValue {
  EResourceFormat Format = EResourceFormat::kUNKNOWN;

  union {
    FColor32 Color = {0, 0, 0, 0};

    struct {
      float Depth;
      uint8_t Stencil;
    };
  };
};

enum class WALKER_API EHeapType {
  kDefault = 1,
  kUpload = 2,
  kReadback = 3,
  kCustom = 4,
  kGPUUpload = 5,
};

enum class WALKER_API ECPUPageProperty {
  kUnknown = 0,
  kNotAvailable = 1,
  kWriteCombine = 2,
  kWriteBack = 3,
};

enum class WALKER_API EMemoryPool {
  kUnknown = 0,
  kL0 = 1,
  kL1 = 2,
};

enum class WALKER_API EAlignment : u64 {
  kDefault = WKR_KB(64),
  kDefaultMSAA = WKR_MB(4),
};

enum class WALKER_API EHeapF : u32 {
  kNone = 0,
  kShared = 0x1,
  kDenyBuffers = 0x4,
  kAllowDisplay = 0x8,
  kSharedCrossAdapter = 0x20,
  kDenyRT_DS_Textures = 0x40,
  kDenyNonRT_DS_Textures = 0x80,
  kHardwareProtected = 0x100,
  kAllowWriteWatch = 0x200,
  kAllowShaderAtomics = 0x400,
  kCreateNotResident = 0x800,
  kCreateNotZeroed = 0x1000,
  kToolsUseManualWriteTracking,
  kAllowAllBuffersAndTextures = 0,
  kAllowOnlyBuffers = 0xc0,
  kAllowOnlyNonRT_DS_Textures = 0x44,
  kAllowOnlyRT_DS_Textures = 0x84
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EHeapF)

struct WALKER_API FModeDesc {
  u32 Width;
  u32 Height;
  FRational RefreshRate;
  EScanlineOrder ScanlineOrdering;
  EScaling Scaling;
  EResourceFormat Format;
};

enum class WALKER_API EResourceDescType {
  kCommitted,
  kReserved,
  kPlaced,
};

struct WALKER_API FResource {
  u64 Alignment = 0;
  u64 Width = 0;
  u32 Height = 0;
  u16 DepthOrArraySize = 0;
  u16 MipLevels = 0;
  FSample Sample = {0, 0};
  EResourceFormat Format = EResourceFormat::kUNKNOWN;
  EResourceF Flag = EResourceF::kNone;
  EResourceLayout Layout = EResourceLayout::kUnknown;
  EResourceDimension Dimension = EResourceDimension::kUnknown;
};

}  // namespace wkr::graphics
