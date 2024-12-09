#pragma once

namespace wkr::graphics {

enum class EScanlineOrder {
  kUnspecified = 0,
  kProgressive = 1,
  kUpperFieldFirst = 2,
  kLowerFieldFirst = 3,
};

enum class EScaling {
  kUnspecified = 0,
  kCentered = 1,
  kStretched = 2,
};

struct FRational {
  u32 Numerator = 1;
  u32 Denominator = 0;
};

enum class EFenceF {
  kNone = 0,
  kShared = 0x1,
  kSharedCrossAdapter = 0x2,
  kNonMonitored = 0x4
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(EFenceF)

enum class ERootSignatureType {
  kDescriptorTable = 0,
  kConstants,
  kCBV,
  kSRV,
  kUAV
};

enum class ERootSignatureVisibilty {
  kAll = 0,
  kVertex = 1,
  kHull = 2,
  kDomain = 3,
  kGeometry = 4,
  kPixel = 5,
  kAmplification = 6,
  kMesh = 7,
};

enum class ERootSignatureF {
  kNone = 0,
  kAllowInputAssemblerInputLayout = 0x1,
  kDenyVertexShaderRootAccess = 0x2,
  kDenyHullShaderRootAccess = 0x4,
  kDenyDomainShaderRootAccess = 0x8,
  kDenyGeometryShaderRootAccess = 0x10,
  kDenyPixelShaderRootAccess = 0x20,
  kAllowStreamOutput = 0x40,
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(ERootSignatureF)

enum class ESwapChainEffect {
  kDiscard = 0,
  kSequential = 1,
  kFlipSequential = 3,
  kFlipDiscard = 4,
};

enum class ESwapChainF : u32 {
  kNone = 0,
  kNonprerotated = 1,
  kAllowModeSwitch = 2,
  kGDICompatible = 4,
  kRestrictedContent = 8,
  kRestrictSharedResourceDriver = 16,
  kDisplayOnly = 32,
  kFrameLatencyWaitableObject = 64,
  kForegroundLayer = 128,
  kFullscreenVideo = 256,
  kYuvVideo = 512,
  kHWProtected = 1024,
  kAllowTearing = 2048,
  kRestrictedToAllHolographicDisplays = 4096,
};

WALKER_ENUM_CLASS_BITWISE_DECLARATION(ESwapChainF)

enum class EVsyncDesc : u8 {
  kNone = 0,
  kDoubleBuffering = 1,
  kTripleBuffering = 2,
};

struct FColor32 {
  u8 R = 0;
  u8 G = 0;
  u8 B = 0;
  u8 A = 1;

  FColor32(u8 r, u8 g, u8 b, u8 a) : R(r), G(g), B(b), A(a) {}
};

struct FSample {
  u32 Count = 1;
  u32 Quality = 0;
};

struct FLuid {
  u64 LowPart = 0;
  i64 HighPart = 0;
};

}  // namespace wkr::graphics
