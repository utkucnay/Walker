#pragma once

#include "Graphics/Core/GraphicsType.h"
#include "Graphics/RHI/Command/CommandType.h"
#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"
#include "Graphics/RHI/Resource/ResourceType.h"
#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "d3d12.h"

namespace wkr::graphics::rhi
{

namespace wkrtodx12
{
  static std::unordered_map<ECommandType, D3D12_COMMAND_LIST_TYPE> ECommandTypeMap =
  {
    {ECommandType::kBundle,        D3D12_COMMAND_LIST_TYPE_BUNDLE        },
    {ECommandType::kDirect,        D3D12_COMMAND_LIST_TYPE_DIRECT        },
    {ECommandType::kCompute,       D3D12_COMMAND_LIST_TYPE_COMPUTE       },
    {ECommandType::kCopy,          D3D12_COMMAND_LIST_TYPE_COPY          },
    {ECommandType::kVideoDecode,   D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE  },
    {ECommandType::kVideoProcess,  D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS },
    {ECommandType::kVideoEncode,   D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE  },
    {ECommandType::kNone,          D3D12_COMMAND_LIST_TYPE_NONE          },
  };
  static inline D3D12_COMMAND_LIST_TYPE
  ConvertECommandType(ECommandType commandType)
  {
    return ECommandTypeMap[commandType];
  }

  static std::unordered_map<ECommandQueueF, D3D12_COMMAND_QUEUE_FLAGS> ECommandQueueFMap =
  {
    {ECommandQueueF::kNone,              D3D12_COMMAND_QUEUE_FLAG_NONE               },
    {ECommandQueueF::kDisableGPUTimeout, D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT},
  };
  static inline D3D12_COMMAND_QUEUE_FLAGS
  ConvertECommandQueueF(ECommandQueueF flag)
  {
    D3D12_COMMAND_QUEUE_FLAGS ret = {};

    for(auto iter : ECommandQueueFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= ECommandQueueFMap[iter.first];

    return ret;
  }

  static std::unordered_map<EFenceF, D3D12_FENCE_FLAGS> EFenceFMap =
  {
    {EFenceF::kNone,                D3D12_FENCE_FLAG_NONE},
    {EFenceF::kShared,              D3D12_FENCE_FLAG_SHARED},
    {EFenceF::kNonMonitored,        D3D12_FENCE_FLAG_NON_MONITORED},
    {EFenceF::kSharedCrossAdapter,  D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER},
  };
  static inline D3D12_FENCE_FLAGS
  ConvertEFenceF(EFenceF flag)
  {
    D3D12_FENCE_FLAGS ret = {};

    for(auto iter : EFenceFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= EFenceFMap[iter.first];

    return ret;
  }

  static std::unordered_map<EResourceUsageF, DXGI_USAGE> EResourceUsageFMap =
  {
    {EResourceUsageF::kSHARED, DXGI_USAGE_SHARED},
    {EResourceUsageF::kREAD_ONLY, DXGI_USAGE_READ_ONLY},
    {EResourceUsageF::kSHADER_INPUT, DXGI_USAGE_SHADER_INPUT},
    {EResourceUsageF::kBACK_BUFFER, DXGI_USAGE_BACK_BUFFER},
    {EResourceUsageF::kUNORDERED_ACCESS, DXGI_USAGE_UNORDERED_ACCESS},
    {EResourceUsageF::kRENDER_TARGET_OUTPUT, DXGI_USAGE_RENDER_TARGET_OUTPUT},
    {EResourceUsageF::kDISCARD_ON_PRESENT, DXGI_USAGE_DISCARD_ON_PRESENT},

    {EResourceUsageF::kCPU_ACCESS_NONE, DXGI_CPU_ACCESS_NONE},
    {EResourceUsageF::kCPU_ACCESS_FIELD, DXGI_CPU_ACCESS_FIELD},
    {EResourceUsageF::kCPU_ACCESS_DYNAMIC, DXGI_CPU_ACCESS_DYNAMIC},
    {EResourceUsageF::kCPU_ACCESS_SCRATCH, DXGI_CPU_ACCESS_SCRATCH},
    {EResourceUsageF::kCPU_ACCESS_READ_WRITE, DXGI_CPU_ACCESS_READ_WRITE},
  };
  static inline DXGI_USAGE
  ConvertEResourceUsage(EResourceUsageF flag)
  {

    DXGI_USAGE ret = {};

    for(auto iter : EResourceUsageFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= EResourceUsageFMap[iter.first];

    return ret;
  }

  static std::unordered_map<EResourceFormat, DXGI_FORMAT> EResourceFormatMap =
  {
    { EResourceFormat::kUNKNOWN, DXGI_FORMAT_UNKNOWN },
    { EResourceFormat::kR32G32B32A32_TYPELESS, DXGI_FORMAT_R32G32B32A32_TYPELESS },
    { EResourceFormat::kR32G32B32A32_FLOAT, DXGI_FORMAT_R32G32B32A32_FLOAT },
    { EResourceFormat::kR32G32B32A32_UINT, DXGI_FORMAT_R32G32B32A32_UINT },
    { EResourceFormat::kR32G32B32A32_SINT, DXGI_FORMAT_R32G32B32A32_SINT },
    { EResourceFormat::kR32G32B32_TYPELESS, DXGI_FORMAT_R32G32B32_TYPELESS },
    { EResourceFormat::kR32G32B32_FLOAT, DXGI_FORMAT_R32G32B32_FLOAT },
    { EResourceFormat::kR32G32B32_UINT, DXGI_FORMAT_R32G32B32_UINT },
    { EResourceFormat::kR32G32B32_SINT, DXGI_FORMAT_R32G32B32_SINT },
    { EResourceFormat::kR16G16B16A16_TYPELESS, DXGI_FORMAT_R16G16B16A16_TYPELESS },
    { EResourceFormat::kR16G16B16A16_FLOAT, DXGI_FORMAT_R16G16B16A16_FLOAT },
    { EResourceFormat::kR16G16B16A16_UNORM, DXGI_FORMAT_R16G16B16A16_UNORM },
    { EResourceFormat::kR16G16B16A16_UINT, DXGI_FORMAT_R16G16B16A16_UINT },
    { EResourceFormat::kR16G16B16A16_SNORM, DXGI_FORMAT_R16G16B16A16_SNORM },
    { EResourceFormat::kR16G16B16A16_SINT, DXGI_FORMAT_R16G16B16A16_SINT },
    { EResourceFormat::kR32G32_TYPELESS, DXGI_FORMAT_R32G32_TYPELESS },
    { EResourceFormat::kR32G32_FLOAT, DXGI_FORMAT_R32G32_FLOAT },
    { EResourceFormat::kR32G32_UINT, DXGI_FORMAT_R32G32_UINT },
    { EResourceFormat::kR32G32_SINT, DXGI_FORMAT_R32G32_SINT },
    { EResourceFormat::kR32G8X24_TYPELESS, DXGI_FORMAT_R32G8X24_TYPELESS },
    { EResourceFormat::kD32_FLOAT_S8X24_UINT, DXGI_FORMAT_D32_FLOAT_S8X24_UINT },
    { EResourceFormat::kR32_FLOAT_X8X24_TYPELESS, DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS },
    { EResourceFormat::kX32_TYPELESS_G8X24_UINT, DXGI_FORMAT_X32_TYPELESS_G8X24_UINT },
    { EResourceFormat::kR10G10B10A2_TYPELESS, DXGI_FORMAT_R10G10B10A2_TYPELESS },
    { EResourceFormat::kR10G10B10A2_UNORM, DXGI_FORMAT_R10G10B10A2_UNORM },
    { EResourceFormat::kR10G10B10A2_UINT, DXGI_FORMAT_R10G10B10A2_UINT },
    { EResourceFormat::kR11G11B10_FLOAT, DXGI_FORMAT_R11G11B10_FLOAT },
    { EResourceFormat::kR8G8B8A8_TYPELESS, DXGI_FORMAT_R8G8B8A8_TYPELESS },
    { EResourceFormat::kR8G8B8A8_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM },
    { EResourceFormat::kR8G8B8A8_UNORM_SRGB, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB },
    { EResourceFormat::kR8G8B8A8_UINT, DXGI_FORMAT_R8G8B8A8_UINT },
    { EResourceFormat::kR8G8B8A8_SNORM, DXGI_FORMAT_R8G8B8A8_SNORM },
    { EResourceFormat::kR8G8B8A8_SINT, DXGI_FORMAT_R8G8B8A8_SINT },
    { EResourceFormat::kR16G16_TYPELESS, DXGI_FORMAT_R16G16_TYPELESS },
    { EResourceFormat::kR16G16_FLOAT, DXGI_FORMAT_R16G16_FLOAT },
    { EResourceFormat::kR16G16_UNORM, DXGI_FORMAT_R16G16_UNORM },
    { EResourceFormat::kR16G16_UINT, DXGI_FORMAT_R16G16_UINT },
    { EResourceFormat::kR16G16_SNORM, DXGI_FORMAT_R16G16_SNORM },
    { EResourceFormat::kR16G16_SINT, DXGI_FORMAT_R16G16_SINT },
    { EResourceFormat::kR32_TYPELESS, DXGI_FORMAT_R32_TYPELESS },
    { EResourceFormat::kD32_FLOAT, DXGI_FORMAT_D32_FLOAT },
    { EResourceFormat::kR32_FLOAT, DXGI_FORMAT_R32_FLOAT },
    { EResourceFormat::kR32_UINT, DXGI_FORMAT_R32_UINT },
    { EResourceFormat::kR32_SINT, DXGI_FORMAT_R32_SINT },
    { EResourceFormat::kR24G8_TYPELESS, DXGI_FORMAT_R24G8_TYPELESS },
    { EResourceFormat::kD24_UNORM_S8_UINT, DXGI_FORMAT_D24_UNORM_S8_UINT },
    { EResourceFormat::kR24_UNORM_X8_TYPELESS, DXGI_FORMAT_R24_UNORM_X8_TYPELESS },
    { EResourceFormat::kX24_TYPELESS_G8_UINT, DXGI_FORMAT_X24_TYPELESS_G8_UINT },
    { EResourceFormat::kR8G8_TYPELESS, DXGI_FORMAT_R8G8_TYPELESS },
    { EResourceFormat::kR8G8_UNORM, DXGI_FORMAT_R8G8_UNORM },
    { EResourceFormat::kR8G8_UINT, DXGI_FORMAT_R8G8_UINT },
    { EResourceFormat::kR8G8_SNORM, DXGI_FORMAT_R8G8_SNORM },
    { EResourceFormat::kR8G8_SINT, DXGI_FORMAT_R8G8_SINT },
    { EResourceFormat::kR16_TYPELESS, DXGI_FORMAT_R16_TYPELESS },
    { EResourceFormat::kR16_FLOAT, DXGI_FORMAT_R16_FLOAT },
    { EResourceFormat::kD16_UNORM, DXGI_FORMAT_D16_UNORM },
    { EResourceFormat::kR16_UNORM, DXGI_FORMAT_R16_UNORM },
    { EResourceFormat::kR16_UINT, DXGI_FORMAT_R16_UINT },
    { EResourceFormat::kR16_SNORM, DXGI_FORMAT_R16_SNORM },
    { EResourceFormat::kR16_SINT, DXGI_FORMAT_R16_SINT },
    { EResourceFormat::kR8_TYPELESS, DXGI_FORMAT_R8_TYPELESS },
    { EResourceFormat::kR8_UNORM, DXGI_FORMAT_R8_UNORM },
    { EResourceFormat::kR8_UINT, DXGI_FORMAT_R8_UINT },
    { EResourceFormat::kR8_SNORM, DXGI_FORMAT_R8_SNORM },
    { EResourceFormat::kR8_SINT, DXGI_FORMAT_R8_SINT },
    { EResourceFormat::kA8_UNORM, DXGI_FORMAT_A8_UNORM },
    { EResourceFormat::kR1_UNORM, DXGI_FORMAT_R1_UNORM },
    { EResourceFormat::kR9G9B9E5_SHAREDEXP, DXGI_FORMAT_R9G9B9E5_SHAREDEXP },
    { EResourceFormat::kR8G8_B8G8_UNORM, DXGI_FORMAT_R8G8_B8G8_UNORM },
    { EResourceFormat::kG8R8_G8B8_UNORM, DXGI_FORMAT_G8R8_G8B8_UNORM },
    { EResourceFormat::kBC1_TYPELESS, DXGI_FORMAT_BC1_TYPELESS },
    { EResourceFormat::kBC1_UNORM, DXGI_FORMAT_BC1_UNORM },
    { EResourceFormat::kBC1_UNORM_SRGB, DXGI_FORMAT_BC1_UNORM_SRGB },
    { EResourceFormat::kBC2_TYPELESS, DXGI_FORMAT_BC2_TYPELESS },
    { EResourceFormat::kBC2_UNORM, DXGI_FORMAT_BC2_UNORM },
    { EResourceFormat::kBC2_UNORM_SRGB, DXGI_FORMAT_BC2_UNORM_SRGB },
    { EResourceFormat::kBC3_TYPELESS, DXGI_FORMAT_BC3_TYPELESS },
    { EResourceFormat::kBC3_UNORM, DXGI_FORMAT_BC3_UNORM },
    { EResourceFormat::kBC3_UNORM_SRGB, DXGI_FORMAT_BC3_UNORM_SRGB },
    { EResourceFormat::kBC4_TYPELESS, DXGI_FORMAT_BC4_TYPELESS },
    { EResourceFormat::kBC4_UNORM, DXGI_FORMAT_BC4_UNORM },
    { EResourceFormat::kBC4_SNORM, DXGI_FORMAT_BC4_SNORM },
    { EResourceFormat::kBC5_TYPELESS, DXGI_FORMAT_BC5_TYPELESS },
    { EResourceFormat::kBC5_UNORM, DXGI_FORMAT_BC5_UNORM },
    { EResourceFormat::kBC5_SNORM, DXGI_FORMAT_BC5_SNORM },
    { EResourceFormat::kB5G6R5_UNORM, DXGI_FORMAT_B5G6R5_UNORM },
    { EResourceFormat::kB5G5R5A1_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM },
    { EResourceFormat::kB8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM },
    { EResourceFormat::kB8G8R8X8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM },
    { EResourceFormat::kR10G10B10_XR_BIAS_A2_UNORM, DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM },
    { EResourceFormat::kB8G8R8A8_TYPELESS, DXGI_FORMAT_B8G8R8A8_TYPELESS },
    { EResourceFormat::kB8G8R8A8_UNORM_SRGB, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB },
    { EResourceFormat::kB8G8R8X8_TYPELESS, DXGI_FORMAT_B8G8R8X8_TYPELESS },
    { EResourceFormat::kB8G8R8X8_UNORM_SRGB, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB },
    { EResourceFormat::kBC6H_TYPELESS, DXGI_FORMAT_BC6H_TYPELESS },
    { EResourceFormat::kBC6H_UF16, DXGI_FORMAT_BC6H_UF16 },
    { EResourceFormat::kBC6H_SF16, DXGI_FORMAT_BC6H_SF16 },
    { EResourceFormat::kBC7_TYPELESS, DXGI_FORMAT_BC7_TYPELESS },
    { EResourceFormat::kBC7_UNORM, DXGI_FORMAT_BC7_UNORM },
    { EResourceFormat::kBC7_UNORM_SRGB, DXGI_FORMAT_BC7_UNORM_SRGB },
    { EResourceFormat::kAYUV, DXGI_FORMAT_AYUV },
    { EResourceFormat::kY410, DXGI_FORMAT_Y410 },
    { EResourceFormat::kY416, DXGI_FORMAT_Y416 },
    { EResourceFormat::kNV12, DXGI_FORMAT_NV12 },
    { EResourceFormat::kP010, DXGI_FORMAT_P010 },
    { EResourceFormat::kP016, DXGI_FORMAT_P016 },
    { EResourceFormat::kYUY2, DXGI_FORMAT_YUY2 },
    { EResourceFormat::kY210, DXGI_FORMAT_Y210 },
    { EResourceFormat::kY216, DXGI_FORMAT_Y216 },
    { EResourceFormat::kNV11, DXGI_FORMAT_NV11 },
    { EResourceFormat::kAI44, DXGI_FORMAT_AI44 },
    { EResourceFormat::kIA44, DXGI_FORMAT_IA44 },
    { EResourceFormat::kP8, DXGI_FORMAT_P8 },
    { EResourceFormat::kA8P8, DXGI_FORMAT_A8P8 },
    { EResourceFormat::kB4G4R4A4_UNORM, DXGI_FORMAT_B4G4R4A4_UNORM },
    { EResourceFormat::kP208, DXGI_FORMAT_P208 },
    { EResourceFormat::kV208, DXGI_FORMAT_V208 },
    { EResourceFormat::kV408, DXGI_FORMAT_V408 },
    { EResourceFormat::kSAMPLER_FEEDBACK_MIN_MIP_OPAQUE, DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE },
    { EResourceFormat::kSAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE, DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE },
    { EResourceFormat::kFORCE_UINT, DXGI_FORMAT_FORCE_UINT },
  };
  static inline DXGI_FORMAT
  ConvertEResourceFormat(EResourceFormat format)
  {
    return EResourceFormatMap[format];
  }

  static std::unordered_map<EScaling, DXGI_MODE_SCALING> EScalingMap =
  {
    { EScaling::kCentered, DXGI_MODE_SCALING_CENTERED },
    { EScaling::kStretched, DXGI_MODE_SCALING_STRETCHED },
    { EScaling::kUnspecified, DXGI_MODE_SCALING_UNSPECIFIED },
  };
  static inline DXGI_MODE_SCALING
  ConvertEScaling(EScaling scaling)
  {
    return EScalingMap[scaling];
  }

  static std::unordered_map<EScanlineOrder, DXGI_MODE_SCANLINE_ORDER> EScanlineOrderMap =
  {
    { EScanlineOrder::kUnspecified, DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED },
    { EScanlineOrder::kProgressive, DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE },
    { EScanlineOrder::kLowerFieldFirst, DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST },
    { EScanlineOrder::kUpperFieldFirst, DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST },
  };
  static inline DXGI_MODE_SCANLINE_ORDER
  ConvertEScanlineOrder(EScanlineOrder scanlineOrder)
  {
    return EScanlineOrderMap[scanlineOrder];
  }

  static std::unordered_map<ESwapChainEffect, DXGI_SWAP_EFFECT> ESwapChainEffectMap =
  {
    { ESwapChainEffect::kDiscard, DXGI_SWAP_EFFECT_DISCARD },
    { ESwapChainEffect::kSequential, DXGI_SWAP_EFFECT_SEQUENTIAL },
    { ESwapChainEffect::kFlipDiscard, DXGI_SWAP_EFFECT_FLIP_DISCARD },
    { ESwapChainEffect::kFlipSequential, DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL },
  };
  static inline DXGI_SWAP_EFFECT
  ConvertESwapChainEffect(ESwapChainEffect swapChainEffect)
  {
    return ESwapChainEffectMap[swapChainEffect];
  }

  static std::unordered_map<EDescriptorHeapType, D3D12_DESCRIPTOR_HEAP_TYPE> EDescriptorHeapTypeMap =
  {
    { EDescriptorHeapType::kDSV, D3D12_DESCRIPTOR_HEAP_TYPE_DSV },
    { EDescriptorHeapType::kRTV, D3D12_DESCRIPTOR_HEAP_TYPE_RTV },
    { EDescriptorHeapType::kSampler, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER },
    { EDescriptorHeapType::kCBV_SRV_UAV, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV },
    { EDescriptorHeapType::kNumTypes, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES },
  };
  static inline D3D12_DESCRIPTOR_HEAP_TYPE
  ConvertEDescriptorHeapType(EDescriptorHeapType descriptorHeapType)
  {
    return EDescriptorHeapTypeMap[descriptorHeapType];
  }

  static std::unordered_map<EDescriptorHeapF, D3D12_DESCRIPTOR_HEAP_FLAGS> EDescriptorHeapFMap =
  {
    { EDescriptorHeapF::kNone, D3D12_DESCRIPTOR_HEAP_FLAG_NONE },
    { EDescriptorHeapF::kShaderVisable, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE },
  };
  static inline D3D12_DESCRIPTOR_HEAP_FLAGS
  ConvertEDescriptorHeapF(EDescriptorHeapF descriptorHeapFlag)
  {
    D3D12_DESCRIPTOR_HEAP_FLAGS ret = {};

    for(auto iter : EDescriptorHeapFMap)
      if(HAS_FLAG(iter.first, descriptorHeapFlag))
        ret |= EDescriptorHeapFMap[iter.first];

    return ret;
  }

  static inline DXGI_SAMPLE_DESC
  ConvertFSampleDesc(FSample& desc)
  {
    DXGI_SAMPLE_DESC ret = {};

    ret.Count = desc.Count;
    ret.Quality = desc.Quality;

    return ret;
  }

  static std::unordered_map<EResourceStateF, D3D12_RESOURCE_STATES> EResourceStateFMap =
  {
    { EResourceStateF::kCommon                          , D3D12_RESOURCE_STATE_COMMON },
    { EResourceStateF::kVertexAndConstantBuffer         , D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER },
    { EResourceStateF::kIndexBuffer                     , D3D12_RESOURCE_STATE_INDEX_BUFFER },
    { EResourceStateF::kRenderTarget                    , D3D12_RESOURCE_STATE_RENDER_TARGET },
    { EResourceStateF::kUnorederedAccess                , D3D12_RESOURCE_STATE_UNORDERED_ACCESS },
    { EResourceStateF::kDepthWrite                      , D3D12_RESOURCE_STATE_DEPTH_WRITE },
    { EResourceStateF::kDepthRead                       , D3D12_RESOURCE_STATE_DEPTH_READ },
    { EResourceStateF::kNonPixelShaderResource          , D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE },
    { EResourceStateF::kPixelShaderResource             , D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE },
    { EResourceStateF::kStreamOut                       , D3D12_RESOURCE_STATE_STREAM_OUT },
    { EResourceStateF::kIndirectArgument                , D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT },
    { EResourceStateF::kCopyDest                        , D3D12_RESOURCE_STATE_COPY_DEST },
    { EResourceStateF::kCopySource                      , D3D12_RESOURCE_STATE_COPY_SOURCE },
    { EResourceStateF::kResolveDest                     , D3D12_RESOURCE_STATE_RESOLVE_DEST },
    { EResourceStateF::kResolveSource                   , D3D12_RESOURCE_STATE_RESOLVE_SOURCE },
    { EResourceStateF::kRaytracingAccelerationStructure , D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE },
    { EResourceStateF::kShadingRateSource               , D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE },
    { EResourceStateF::kReservedInternal8000            , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_8000 },
    { EResourceStateF::kReservedInternal4000            , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_4000 },
    { EResourceStateF::kReservedInternal100000          , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_100000 },
    { EResourceStateF::kReservedInternal40000000        , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_40000000 },
    { EResourceStateF::kReservedInternal80000000        , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_80000000 },
    { EResourceStateF::kGenericRead                     , D3D12_RESOURCE_STATE_GENERIC_READ },
    { EResourceStateF::kAllShaderResource               , D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE },
    { EResourceStateF::kPresent                         , D3D12_RESOURCE_STATE_PRESENT },
    { EResourceStateF::kPredication                     , D3D12_RESOURCE_STATE_PREDICATION },
    { EResourceStateF::kVideoDecodeRead                 , D3D12_RESOURCE_STATE_VIDEO_DECODE_READ },
    { EResourceStateF::kVideoDecodeWrite                , D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE },
    { EResourceStateF::kVideoProcessRead                , D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ },
    { EResourceStateF::kVideoProcessWrite               , D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE },
    { EResourceStateF::kVideoEncodeRead                 , D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ },
    { EResourceStateF::kVideoEncodeWrite                , D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE },
  };
  static inline D3D12_RESOURCE_STATES
  ConvertEResourceStateF(EResourceStateF resourceState)
  {
    D3D12_RESOURCE_STATES ret = {};

    for(auto iter : EResourceStateFMap)
      if(HAS_FLAG(iter.first, resourceState))
        ret |= EResourceStateFMap[iter.first];

    return EResourceStateFMap[resourceState];
  }

  static inline mem::TScope<D3D12_CLEAR_VALUE>
  ConvertFClearValue(FClearValue* clearValue)
  {
    if(clearValue == nullptr) return nullptr;

    D3D12_CLEAR_VALUE* ret = new D3D12_CLEAR_VALUE();

    ret->Format = ConvertEResourceFormat(clearValue->Format);
    ret->DepthStencil.Depth = clearValue->Depth;
    ret->DepthStencil.Stencil = clearValue->Stencil;

    return ret;
  }

  static std::unordered_map<EResourceDimension, D3D12_RESOURCE_DIMENSION> EResourceDimensionMap =
  {
    { EResourceDimension::kUnknown   , D3D12_RESOURCE_DIMENSION_UNKNOWN },
    { EResourceDimension::kBuffer    , D3D12_RESOURCE_DIMENSION_BUFFER },
    { EResourceDimension::kTexture1D , D3D12_RESOURCE_DIMENSION_TEXTURE1D },
    { EResourceDimension::kTexture2D , D3D12_RESOURCE_DIMENSION_TEXTURE2D },
    { EResourceDimension::kTexture3D , D3D12_RESOURCE_DIMENSION_TEXTURE3D },
  };
  static inline D3D12_RESOURCE_DIMENSION
  ConvertEResourceDimension(EResourceDimension resourceDimension)
  {
    return EResourceDimensionMap[resourceDimension];
  }

  static std::unordered_map<EResourceLayout, D3D12_TEXTURE_LAYOUT> EResourceLayoutMap =
  {
    { EResourceLayout::kUnknown              , D3D12_TEXTURE_LAYOUT_UNKNOWN },
    { EResourceLayout::kRowMajor             , D3D12_TEXTURE_LAYOUT_ROW_MAJOR },
    { EResourceLayout::kStandardSwizzle64KB  , D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE },
    { EResourceLayout::kUndefinedSwizzle64KB , D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE  },
  };
  static inline D3D12_TEXTURE_LAYOUT
  ConvertEResourceLayout(EResourceLayout resourceLayout)
  {
    return EResourceLayoutMap[resourceLayout];
  }

  static std::unordered_map<EResourceF, D3D12_RESOURCE_FLAGS> EResourceFMap =
  {
    { EResourceF::kNone, D3D12_RESOURCE_FLAG_NONE },
    { EResourceF::kAllowCrossAdapter, D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER },
    { EResourceF::kAllowDepthStencil, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL },
    { EResourceF::kAllowRenderTarget, D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET },
    { EResourceF::kDenyShaderResource, D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE },
    { EResourceF::kAllowUnorderedAccess, D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS },
    { EResourceF::kAllowSimultaneousAccess, D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS },
    { EResourceF::kVideoDecodeReferenceOnly, D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY },
    { EResourceF::kVideoEncodeReferenceOnly, D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY },
    { EResourceF::kRaytracingAccelerationStructure, D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE },
  };
  static inline D3D12_RESOURCE_FLAGS
  ConvertEResourceF(EResourceF resourceFlag)
  {
    D3D12_RESOURCE_FLAGS ret = {};

    for(auto iter : EResourceFMap)
      if(HAS_FLAG(iter.first, resourceFlag))
        ret |= EResourceFMap[iter.first];

    return ret;
  }

  static inline D3D12_RESOURCE_DESC
  ConvertFResource(FResource& desc)
  {
    D3D12_RESOURCE_DESC ret = {};

    ret.Dimension = ConvertEResourceDimension(desc.Dimension);
    ret.Alignment = desc.Alignment;
    ret.Width = desc.Width;
    ret.Height = desc.Height;
    ret.DepthOrArraySize = desc.DepthOrArraySize;
    ret.MipLevels = desc.MipLevels;
    ret.Format = ConvertEResourceFormat(desc.Format);
    ret.SampleDesc = ConvertFSampleDesc(desc.Sample);
    ret.Layout = ConvertEResourceLayout(desc.Layout);
    ret.Flags = ConvertEResourceF(desc.Flag);

    return ret;
  }

  static std::unordered_map<EHeapType, D3D12_HEAP_TYPE> EHeapTypeMap =
  {
    { EHeapType::kDefault, D3D12_HEAP_TYPE_DEFAULT },
    { EHeapType::kCustom, D3D12_HEAP_TYPE_CUSTOM },
    { EHeapType::kUpload, D3D12_HEAP_TYPE_UPLOAD },
    { EHeapType::kReadback, D3D12_HEAP_TYPE_READBACK },
    { EHeapType::kGPUUpload, D3D12_HEAP_TYPE_GPU_UPLOAD },
  };
  static inline D3D12_HEAP_TYPE
  ConvertEHeapType(EHeapType heapType)
  {
    return EHeapTypeMap[heapType];
  }

  static std::unordered_map<ECPUPageProperty, D3D12_CPU_PAGE_PROPERTY> ECPUPagePropertyMap =
  {
    { ECPUPageProperty::kUnknown, D3D12_CPU_PAGE_PROPERTY_UNKNOWN },
    { ECPUPageProperty::kWriteBack, D3D12_CPU_PAGE_PROPERTY_WRITE_BACK },
    { ECPUPageProperty::kWriteCombine, D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE },
    { ECPUPageProperty::kNotAvailable, D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE },
  };
  static inline D3D12_CPU_PAGE_PROPERTY
  ConvertECPUPageProperty(ECPUPageProperty cpuPageProperty)
  {
    return ECPUPagePropertyMap[cpuPageProperty];
  }

  static std::unordered_map<EMemoryPool, D3D12_MEMORY_POOL> EMemoyPoolMap =
  {
    { EMemoryPool::kUnknown, D3D12_MEMORY_POOL_UNKNOWN },
    { EMemoryPool::kL0, D3D12_MEMORY_POOL_L0 },
    { EMemoryPool::kL1, D3D12_MEMORY_POOL_L1 },
  };
  static inline D3D12_MEMORY_POOL
  ConvertEMemoryPool(EMemoryPool memoryPool)
  {
    return EMemoyPoolMap[memoryPool];
  }

  static std::unordered_map<EHeapF, D3D12_HEAP_FLAGS> EHeapFMap =
  {
    { EHeapF::kNone, D3D12_HEAP_FLAG_NONE },
    { EHeapF::kShared, D3D12_HEAP_FLAG_SHARED },
    { EHeapF::kDenyBuffers, D3D12_HEAP_FLAG_DENY_BUFFERS },
    { EHeapF::kAllowDisplay, D3D12_HEAP_FLAG_ALLOW_DISPLAY },
    { EHeapF::kAllowWriteWatch, D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH },
    { EHeapF::kCreateNotZeroed, D3D12_HEAP_FLAG_CREATE_NOT_ZEROED },
    { EHeapF::kAllowOnlyBuffers, D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS },
    { EHeapF::kCreateNotResident, D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT },
    { EHeapF::kHardwareProtected, D3D12_HEAP_FLAG_HARDWARE_PROTECTED },
    { EHeapF::kAllowShaderAtomics, D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS },
    { EHeapF::kDenyRT_DS_Textures, D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES },
    { EHeapF::kSharedCrossAdapter, D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER },
    { EHeapF::kDenyNonRT_DS_Textures, D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES },
    { EHeapF::kAllowOnlyRT_DS_Textures, D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES },
    { EHeapF::kAllowOnlyNonRT_DS_Textures, D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES },
    { EHeapF::kAllowAllBuffersAndTextures, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES },
    { EHeapF::kToolsUseManualWriteTracking, D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING },
  };
  static inline D3D12_HEAP_FLAGS
  ConvertEHeapF(EHeapF heapFlag)
  {
    D3D12_HEAP_FLAGS ret = {};

    for ( auto iter : EHeapFMap )
      if ( HAS_FLAG(iter.first, heapFlag) )
        ret |= EHeapFMap[iter.first];

    return ret;
  }

  static inline D3D12_HEAP_PROPERTIES
  ConvertFHeapProperty(FHeapProperties& desc)
  {
    D3D12_HEAP_PROPERTIES ret = {
      .Type = ConvertEHeapType(desc.Type),
      .CPUPageProperty = ConvertECPUPageProperty(desc.CpuPageProperty),
      .MemoryPoolPreference = ConvertEMemoryPool(desc.MemoryPool),
      .CreationNodeMask = 0,
      .VisibleNodeMask = 0,
    };

    return ret;
  }

  static std::unordered_map<ECommandQueuePriority, INT> ECommandQueuePriorityMap =
  {
    {ECommandQueuePriority::kNormal, D3D12_COMMAND_QUEUE_PRIORITY_NORMAL},
    {ECommandQueuePriority::kHigh, D3D12_COMMAND_QUEUE_PRIORITY_HIGH},
    {ECommandQueuePriority::kRealtime, D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME},
  };
  static inline INT
  ConvertECommandQueuePriority(ECommandQueuePriority commandQueuePriority)
  {
    return ECommandQueuePriorityMap[commandQueuePriority];
  }

  static std::unordered_map<EResourceBarrierType, D3D12_RESOURCE_BARRIER_TYPE> EResourceBarrierTypeMap =
  {
    {EResourceBarrierType::kTransition, D3D12_RESOURCE_BARRIER_TYPE_TRANSITION },
    {EResourceBarrierType::kUAV, D3D12_RESOURCE_BARRIER_TYPE_UAV },
    {EResourceBarrierType::kAliasing, D3D12_RESOURCE_BARRIER_TYPE_ALIASING },
  };
  static inline D3D12_RESOURCE_BARRIER_TYPE
  ConvertEResourceBarrierType(EResourceBarrierType barrierType)
  {
    return EResourceBarrierTypeMap[barrierType];
  }

  static std::unordered_map<EResourceBarrierF, D3D12_RESOURCE_BARRIER_FLAGS> EResourceBarrierFMap =
  {
    {EResourceBarrierF::kNone, D3D12_RESOURCE_BARRIER_FLAG_NONE },
    {EResourceBarrierF::kEndOnly, D3D12_RESOURCE_BARRIER_FLAG_END_ONLY },
    {EResourceBarrierF::kBeginOnly, D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY },
  };

  static inline D3D12_RESOURCE_BARRIER_FLAGS
  ConvertEResourceBarrierF(EResourceBarrierF barrierFlag)
  {
    D3D12_RESOURCE_BARRIER_FLAGS ret = {};

    for ( auto iter : EResourceBarrierFMap )
      if ( HAS_FLAG(iter.first, barrierFlag) )
        ret |= EResourceBarrierFMap[iter.first];

    return ret;
  }

  static std::unordered_map<ESwapChainF, UINT> ESwapChainFMap =
  {
    {ESwapChainF::kNone, 0},
    {ESwapChainF::kYuvVideo, DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO },
    {ESwapChainF::kDisplayOnly, DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY },
    {ESwapChainF::kHWProtected, DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED },
    {ESwapChainF::kAllowTearing, DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING },
    {ESwapChainF::kGDICompatible, DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE },
    {ESwapChainF::kNonprerotated, DXGI_SWAP_CHAIN_FLAG_NONPREROTATED },
    {ESwapChainF::kAllowModeSwitch, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH },
    {ESwapChainF::kForegroundLayer, DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER},
    {ESwapChainF::kFullscreenVideo, DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO},
    {ESwapChainF::kRestrictedContent, DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT },
    {ESwapChainF::kFrameLatencyWaitableObject, DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT },
    {ESwapChainF::kRestrictSharedResourceDriver, DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER },
    {ESwapChainF::kRestrictedToAllHolographicDisplays, DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS },
  };
  static inline UINT
  ConvertESwapChainF(ESwapChainF flag)
  {
    UINT ret = 0;

    for ( auto iter : ESwapChainFMap )
      if ( HAS_FLAG(iter.first, flag) )
        ret |= ESwapChainFMap[iter.first];

    return ret;
  }

}


namespace dx12towkr
{
  static std::unordered_map<D3D12_COMMAND_LIST_TYPE, ECommandType> ECommandTypeMap =
  {
    {D3D12_COMMAND_LIST_TYPE_BUNDLE, ECommandType::kBundle               },
    {D3D12_COMMAND_LIST_TYPE_DIRECT, ECommandType::kDirect               },
    {D3D12_COMMAND_LIST_TYPE_COMPUTE, ECommandType::kCompute             },
    {D3D12_COMMAND_LIST_TYPE_COPY, ECommandType::kCopy                   },
    {D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE, ECommandType::kVideoDecode    },
    {D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS, ECommandType::kVideoProcess  },
    {D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE, ECommandType::kVideoEncode    },
    {D3D12_COMMAND_LIST_TYPE_NONE, ECommandType::kNone                   },
  };
  static inline ECommandType
  ConvertECommandType(D3D12_COMMAND_LIST_TYPE commandType)
  {
    return ECommandTypeMap[commandType];
  }

  static std::unordered_map<D3D12_COMMAND_QUEUE_FLAGS, ECommandQueueF> ECommandQueueFMap =
  {
    {D3D12_COMMAND_QUEUE_FLAG_NONE, ECommandQueueF::kNone                            },
    {D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT, ECommandQueueF::kDisableGPUTimeout} ,
  };
  static inline ECommandQueueF
  ConvertECommandQueueF(D3D12_COMMAND_QUEUE_FLAGS flag)
  {
    ECommandQueueF ret = {};

    for(auto iter : ECommandQueueFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= ECommandQueueFMap[iter.first];

    return ret;
  }

  static std::unordered_map<D3D12_FENCE_FLAGS, EFenceF> EFenceFMap =
  {
    {D3D12_FENCE_FLAG_NONE,EFenceF::kNone                },
    {D3D12_FENCE_FLAG_SHARED, EFenceF::kShared              },
    {D3D12_FENCE_FLAG_NON_MONITORED, EFenceF::kNonMonitored        },
    {D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER, EFenceF::kSharedCrossAdapter  },
  };
  static inline EFenceF
  ConvertEFenceF(D3D12_FENCE_FLAGS flag)
  {
    EFenceF ret = {};

    for(auto iter : EFenceFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= EFenceFMap[iter.first];

    return ret;
  }

  static std::unordered_map<DXGI_USAGE, EResourceUsageF> EResourceUsageFMap =
  {
    {DXGI_USAGE_SHARED, EResourceUsageF::kSHARED},
    {DXGI_USAGE_READ_ONLY, EResourceUsageF::kREAD_ONLY},
    {DXGI_USAGE_SHADER_INPUT, EResourceUsageF::kSHADER_INPUT},
    {DXGI_USAGE_BACK_BUFFER, EResourceUsageF::kBACK_BUFFER},
    {DXGI_USAGE_UNORDERED_ACCESS, EResourceUsageF::kUNORDERED_ACCESS},
    {DXGI_USAGE_RENDER_TARGET_OUTPUT, EResourceUsageF::kRENDER_TARGET_OUTPUT},
    {DXGI_USAGE_DISCARD_ON_PRESENT, EResourceUsageF::kDISCARD_ON_PRESENT},
    {DXGI_CPU_ACCESS_NONE, EResourceUsageF::kCPU_ACCESS_NONE},
    {DXGI_CPU_ACCESS_FIELD, EResourceUsageF::kCPU_ACCESS_FIELD},
    {DXGI_CPU_ACCESS_DYNAMIC, EResourceUsageF::kCPU_ACCESS_DYNAMIC},
    {DXGI_CPU_ACCESS_SCRATCH, EResourceUsageF::kCPU_ACCESS_SCRATCH},
    {DXGI_CPU_ACCESS_READ_WRITE, EResourceUsageF::kCPU_ACCESS_READ_WRITE},
  };
  static inline EResourceUsageF
  ConvertEResourceUsage(DXGI_USAGE flag)
  {
    EResourceUsageF ret = {};

    for(auto iter : EResourceUsageFMap)
      if(HAS_FLAG(iter.first, flag))
        ret |= EResourceUsageFMap[iter.first];

    return ret;
  }

  static std::unordered_map<DXGI_FORMAT, EResourceFormat> EResourceFormatMap =
  {
    { DXGI_FORMAT_UNKNOWN, EResourceFormat::kUNKNOWN },
    { DXGI_FORMAT_R32G32B32A32_TYPELESS, EResourceFormat::kR32G32B32A32_TYPELESS },
    { DXGI_FORMAT_R32G32B32A32_FLOAT, EResourceFormat::kR32G32B32A32_FLOAT },
    { DXGI_FORMAT_R32G32B32A32_UINT, EResourceFormat::kR32G32B32A32_UINT },
    { DXGI_FORMAT_R32G32B32A32_SINT, EResourceFormat::kR32G32B32A32_SINT },
    { DXGI_FORMAT_R32G32B32_TYPELESS, EResourceFormat::kR32G32B32_TYPELESS },
    { DXGI_FORMAT_R32G32B32_FLOAT, EResourceFormat::kR32G32B32_FLOAT },
    { DXGI_FORMAT_R32G32B32_UINT, EResourceFormat::kR32G32B32_UINT },
    { DXGI_FORMAT_R32G32B32_SINT, EResourceFormat::kR32G32B32_SINT },
    { DXGI_FORMAT_R16G16B16A16_TYPELESS, EResourceFormat::kR16G16B16A16_TYPELESS },
    { DXGI_FORMAT_R16G16B16A16_FLOAT, EResourceFormat::kR16G16B16A16_FLOAT },
    { DXGI_FORMAT_R16G16B16A16_UNORM, EResourceFormat::kR16G16B16A16_UNORM },
    { DXGI_FORMAT_R16G16B16A16_UINT, EResourceFormat::kR16G16B16A16_UINT },
    { DXGI_FORMAT_R16G16B16A16_SNORM, EResourceFormat::kR16G16B16A16_SNORM },
    { DXGI_FORMAT_R16G16B16A16_SINT, EResourceFormat::kR16G16B16A16_SINT },
    { DXGI_FORMAT_R32G32_TYPELESS, EResourceFormat::kR32G32_TYPELESS },
    { DXGI_FORMAT_R32G32_FLOAT, EResourceFormat::kR32G32_FLOAT },
    { DXGI_FORMAT_R32G32_UINT, EResourceFormat::kR32G32_UINT },
    { DXGI_FORMAT_R32G32_SINT, EResourceFormat::kR32G32_SINT },
    { DXGI_FORMAT_R32G8X24_TYPELESS, EResourceFormat::kR32G8X24_TYPELESS },
    { DXGI_FORMAT_D32_FLOAT_S8X24_UINT, EResourceFormat::kD32_FLOAT_S8X24_UINT },
    { DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS, EResourceFormat::kR32_FLOAT_X8X24_TYPELESS },
    { DXGI_FORMAT_X32_TYPELESS_G8X24_UINT, EResourceFormat::kX32_TYPELESS_G8X24_UINT },
    { DXGI_FORMAT_R10G10B10A2_TYPELESS, EResourceFormat::kR10G10B10A2_TYPELESS },
    { DXGI_FORMAT_R10G10B10A2_UNORM, EResourceFormat::kR10G10B10A2_UNORM },
    { DXGI_FORMAT_R10G10B10A2_UINT, EResourceFormat::kR10G10B10A2_UINT },
    { DXGI_FORMAT_R11G11B10_FLOAT, EResourceFormat::kR11G11B10_FLOAT },
    { DXGI_FORMAT_R8G8B8A8_TYPELESS, EResourceFormat::kR8G8B8A8_TYPELESS },
    { DXGI_FORMAT_R8G8B8A8_UNORM, EResourceFormat::kR8G8B8A8_UNORM },
    { DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, EResourceFormat::kR8G8B8A8_UNORM_SRGB },
    { DXGI_FORMAT_R8G8B8A8_UINT, EResourceFormat::kR8G8B8A8_UINT },
    { DXGI_FORMAT_R8G8B8A8_SNORM, EResourceFormat::kR8G8B8A8_SNORM },
    { DXGI_FORMAT_R8G8B8A8_SINT, EResourceFormat::kR8G8B8A8_SINT },
    { DXGI_FORMAT_R16G16_TYPELESS, EResourceFormat::kR16G16_TYPELESS },
    { DXGI_FORMAT_R16G16_FLOAT, EResourceFormat::kR16G16_FLOAT },
    { DXGI_FORMAT_R16G16_UNORM, EResourceFormat::kR16G16_UNORM },
    { DXGI_FORMAT_R16G16_UINT, EResourceFormat::kR16G16_UINT },
    { DXGI_FORMAT_R16G16_SNORM, EResourceFormat::kR16G16_SNORM },
    { DXGI_FORMAT_R16G16_SINT, EResourceFormat::kR16G16_SINT },
    { DXGI_FORMAT_R32_TYPELESS, EResourceFormat::kR32_TYPELESS },
    { DXGI_FORMAT_D32_FLOAT, EResourceFormat::kD32_FLOAT },
    { DXGI_FORMAT_R32_FLOAT, EResourceFormat::kR32_FLOAT },
    { DXGI_FORMAT_R32_UINT, EResourceFormat::kR32_UINT },
    { DXGI_FORMAT_R32_SINT, EResourceFormat::kR32_SINT },
    { DXGI_FORMAT_R24G8_TYPELESS, EResourceFormat::kR24G8_TYPELESS },
    { DXGI_FORMAT_D24_UNORM_S8_UINT, EResourceFormat::kD24_UNORM_S8_UINT },
    { DXGI_FORMAT_R24_UNORM_X8_TYPELESS, EResourceFormat::kR24_UNORM_X8_TYPELESS },
    { DXGI_FORMAT_X24_TYPELESS_G8_UINT, EResourceFormat::kX24_TYPELESS_G8_UINT },
    { DXGI_FORMAT_R8G8_TYPELESS, EResourceFormat::kR8G8_TYPELESS },
    { DXGI_FORMAT_R8G8_UNORM, EResourceFormat::kR8G8_UNORM },
    { DXGI_FORMAT_R8G8_UINT, EResourceFormat::kR8G8_UINT },
    { DXGI_FORMAT_R8G8_SNORM, EResourceFormat::kR8G8_SNORM },
    { DXGI_FORMAT_R8G8_SINT, EResourceFormat::kR8G8_SINT },
    { DXGI_FORMAT_R16_TYPELESS, EResourceFormat::kR16_TYPELESS },
    { DXGI_FORMAT_R16_FLOAT, EResourceFormat::kR16_FLOAT },
    { DXGI_FORMAT_D16_UNORM, EResourceFormat::kD16_UNORM },
    { DXGI_FORMAT_R16_UNORM, EResourceFormat::kR16_UNORM },
    { DXGI_FORMAT_R16_UINT, EResourceFormat::kR16_UINT },
    { DXGI_FORMAT_R16_SNORM, EResourceFormat::kR16_SNORM },
    { DXGI_FORMAT_R16_SINT, EResourceFormat::kR16_SINT },
    { DXGI_FORMAT_R8_TYPELESS, EResourceFormat::kR8_TYPELESS },
    { DXGI_FORMAT_R8_UNORM, EResourceFormat::kR8_UNORM },
    { DXGI_FORMAT_R8_UINT, EResourceFormat::kR8_UINT },
    { DXGI_FORMAT_R8_SNORM, EResourceFormat::kR8_SNORM },
    { DXGI_FORMAT_R8_SINT, EResourceFormat::kR8_SINT },
    { DXGI_FORMAT_A8_UNORM, EResourceFormat::kA8_UNORM },
    { DXGI_FORMAT_R1_UNORM, EResourceFormat::kR1_UNORM },
    { DXGI_FORMAT_R9G9B9E5_SHAREDEXP, EResourceFormat::kR9G9B9E5_SHAREDEXP },
    { DXGI_FORMAT_R8G8_B8G8_UNORM, EResourceFormat::kR8G8_B8G8_UNORM },
    { DXGI_FORMAT_G8R8_G8B8_UNORM, EResourceFormat::kG8R8_G8B8_UNORM },
    { DXGI_FORMAT_BC1_TYPELESS, EResourceFormat::kBC1_TYPELESS },
    { DXGI_FORMAT_BC1_UNORM, EResourceFormat::kBC1_UNORM },
    { DXGI_FORMAT_BC1_UNORM_SRGB, EResourceFormat::kBC1_UNORM_SRGB },
    { DXGI_FORMAT_BC2_TYPELESS, EResourceFormat::kBC2_TYPELESS },
    { DXGI_FORMAT_BC2_UNORM, EResourceFormat::kBC2_UNORM },
    { DXGI_FORMAT_BC2_UNORM_SRGB, EResourceFormat::kBC2_UNORM_SRGB },
    { DXGI_FORMAT_BC3_TYPELESS, EResourceFormat::kBC3_TYPELESS },
    { DXGI_FORMAT_BC3_UNORM, EResourceFormat::kBC3_UNORM },
    { DXGI_FORMAT_BC3_UNORM_SRGB, EResourceFormat::kBC3_UNORM_SRGB },
    { DXGI_FORMAT_BC4_TYPELESS, EResourceFormat::kBC4_TYPELESS },
    { DXGI_FORMAT_BC4_UNORM, EResourceFormat::kBC4_UNORM },
    { DXGI_FORMAT_BC4_SNORM, EResourceFormat::kBC4_SNORM },
    { DXGI_FORMAT_BC5_TYPELESS, EResourceFormat::kBC5_TYPELESS },
    { DXGI_FORMAT_BC5_UNORM, EResourceFormat::kBC5_UNORM },
    { DXGI_FORMAT_BC5_SNORM, EResourceFormat::kBC5_SNORM },
    { DXGI_FORMAT_B5G6R5_UNORM, EResourceFormat::kB5G6R5_UNORM },
    { DXGI_FORMAT_B5G5R5A1_UNORM, EResourceFormat::kB5G5R5A1_UNORM },
    { DXGI_FORMAT_B8G8R8A8_UNORM, EResourceFormat::kB8G8R8A8_UNORM },
    { DXGI_FORMAT_B8G8R8X8_UNORM, EResourceFormat::kB8G8R8X8_UNORM },
    { DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM, EResourceFormat::kR10G10B10_XR_BIAS_A2_UNORM },
    { DXGI_FORMAT_B8G8R8A8_TYPELESS, EResourceFormat::kB8G8R8A8_TYPELESS },
    { DXGI_FORMAT_B8G8R8A8_UNORM_SRGB, EResourceFormat::kB8G8R8A8_UNORM_SRGB },
    { DXGI_FORMAT_B8G8R8X8_TYPELESS, EResourceFormat::kB8G8R8X8_TYPELESS },
    { DXGI_FORMAT_B8G8R8X8_UNORM_SRGB, EResourceFormat::kB8G8R8X8_UNORM_SRGB },
    { DXGI_FORMAT_BC6H_TYPELESS, EResourceFormat::kBC6H_TYPELESS },
    { DXGI_FORMAT_BC6H_UF16, EResourceFormat::kBC6H_UF16 },
    { DXGI_FORMAT_BC6H_SF16, EResourceFormat::kBC6H_SF16 },
    { DXGI_FORMAT_BC7_TYPELESS, EResourceFormat::kBC7_TYPELESS },
    { DXGI_FORMAT_BC7_UNORM, EResourceFormat::kBC7_UNORM },
    { DXGI_FORMAT_BC7_UNORM_SRGB, EResourceFormat::kBC7_UNORM_SRGB },
    { DXGI_FORMAT_AYUV, EResourceFormat::kAYUV },
    { DXGI_FORMAT_Y410, EResourceFormat::kY410 },
    { DXGI_FORMAT_Y416, EResourceFormat::kY416 },
    { DXGI_FORMAT_NV12, EResourceFormat::kNV12 },
    { DXGI_FORMAT_P010, EResourceFormat::kP010 },
    { DXGI_FORMAT_P016, EResourceFormat::kP016 },
    { DXGI_FORMAT_YUY2, EResourceFormat::kYUY2 },
    { DXGI_FORMAT_Y210, EResourceFormat::kY210 },
    { DXGI_FORMAT_Y216, EResourceFormat::kY216 },
    { DXGI_FORMAT_NV11, EResourceFormat::kNV11 },
    { DXGI_FORMAT_AI44, EResourceFormat::kAI44 },
    { DXGI_FORMAT_IA44, EResourceFormat::kIA44 },
    { DXGI_FORMAT_P8, EResourceFormat::kP8 },
    { DXGI_FORMAT_A8P8, EResourceFormat::kA8P8 },
    { DXGI_FORMAT_B4G4R4A4_UNORM, EResourceFormat::kB4G4R4A4_UNORM },
    { DXGI_FORMAT_P208, EResourceFormat::kP208 },
    { DXGI_FORMAT_V208, EResourceFormat::kV208 },
    { DXGI_FORMAT_V408, EResourceFormat::kV408 },
    { DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE, EResourceFormat::kSAMPLER_FEEDBACK_MIN_MIP_OPAQUE },
    { DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE, EResourceFormat::kSAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE },
    { DXGI_FORMAT_FORCE_UINT, EResourceFormat::kFORCE_UINT },
  };
  static inline EResourceFormat
  ConvertEResourceFormat(DXGI_FORMAT format)
  {
    return EResourceFormatMap[format];
  }

  static std::unordered_map<DXGI_MODE_SCALING, EScaling> EScalingMap =
  {
    { DXGI_MODE_SCALING_CENTERED, EScaling::kCentered },
    { DXGI_MODE_SCALING_STRETCHED, EScaling::kStretched },
    { DXGI_MODE_SCALING_UNSPECIFIED, EScaling::kUnspecified },
  };
  static inline EScaling
  ConvertEScaling(DXGI_MODE_SCALING scaling)
  {
    return EScalingMap[scaling];
  }

  static std::unordered_map<DXGI_MODE_SCANLINE_ORDER, EScanlineOrder> EScanlineOrderMap =
  {
    { DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED, EScanlineOrder::kUnspecified },
    { DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE, EScanlineOrder::kProgressive },
    { DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST, EScanlineOrder::kLowerFieldFirst },
    { DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST, EScanlineOrder::kUpperFieldFirst },
  };
  static inline EScanlineOrder
  ConvertEScanlineOrder(DXGI_MODE_SCANLINE_ORDER scanlineOrder)
  {
    return EScanlineOrderMap[scanlineOrder];
  }

  static std::unordered_map<DXGI_SWAP_EFFECT, ESwapChainEffect> ESwapChainEffectMap =
  {
    { DXGI_SWAP_EFFECT_DISCARD, ESwapChainEffect::kDiscard },
    { DXGI_SWAP_EFFECT_SEQUENTIAL, ESwapChainEffect::kSequential },
    { DXGI_SWAP_EFFECT_FLIP_DISCARD, ESwapChainEffect::kFlipDiscard },
    { DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL, ESwapChainEffect::kFlipSequential },
  };
  static inline ESwapChainEffect
  ConvertESwapChainEffect(DXGI_SWAP_EFFECT swapChainEffect)
  {
    return ESwapChainEffectMap[swapChainEffect];
  }

  static std::unordered_map<D3D12_DESCRIPTOR_HEAP_TYPE, EDescriptorHeapType> EDescriptorHeapTypeMap =
  {
    { D3D12_DESCRIPTOR_HEAP_TYPE_DSV, EDescriptorHeapType::kDSV },
    { D3D12_DESCRIPTOR_HEAP_TYPE_RTV, EDescriptorHeapType::kRTV },
    { D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, EDescriptorHeapType::kSampler },
    { D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, EDescriptorHeapType::kCBV_SRV_UAV },
    { D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES, EDescriptorHeapType::kNumTypes },
  };
  static inline EDescriptorHeapType
  ConvertEDescriptorHeapType(D3D12_DESCRIPTOR_HEAP_TYPE descriptorHeapType)
  {
    return EDescriptorHeapTypeMap[descriptorHeapType];
  }

  static std::unordered_map<D3D12_DESCRIPTOR_HEAP_FLAGS, EDescriptorHeapF> EDescriptorHeapFMap =
  {
    { D3D12_DESCRIPTOR_HEAP_FLAG_NONE, EDescriptorHeapF::kNone },
    { D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE, EDescriptorHeapF::kShaderVisable },
  };
  static inline EDescriptorHeapF
  ConvertEDescriptorHeapF(D3D12_DESCRIPTOR_HEAP_FLAGS descriptorHeapFlag)
  {
    EDescriptorHeapF ret = {};

    for(auto iter : EDescriptorHeapFMap)
      if(HAS_FLAG(iter.first, descriptorHeapFlag))
        ret |= EDescriptorHeapFMap[iter.first];

    return ret;
  }

  static inline FSample
  ConvertFSampleDesc(DXGI_SAMPLE_DESC& desc)
  {
    FSample ret = {
      .Count = desc.Count,
      .Quality = desc.Quality,
    };

    return ret;
  }

  static std::unordered_map<D3D12_RESOURCE_STATES, EResourceStateF> EResourceStateFMap =
  {
    { D3D12_RESOURCE_STATE_COMMON, EResourceStateF::kCommon                           },
    { D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER, EResourceStateF::kVertexAndConstantBuffer          },
    { D3D12_RESOURCE_STATE_INDEX_BUFFER, EResourceStateF::kIndexBuffer                      },
    { D3D12_RESOURCE_STATE_RENDER_TARGET, EResourceStateF::kRenderTarget                     },
    { D3D12_RESOURCE_STATE_UNORDERED_ACCESS, EResourceStateF::kUnorederedAccess                 },
    { D3D12_RESOURCE_STATE_DEPTH_WRITE, EResourceStateF::kDepthWrite                       },
    { D3D12_RESOURCE_STATE_DEPTH_READ, EResourceStateF::kDepthRead                        },
    { D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, EResourceStateF::kNonPixelShaderResource           },
    { D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE, EResourceStateF::kPixelShaderResource              },
    { D3D12_RESOURCE_STATE_STREAM_OUT, EResourceStateF::kStreamOut                        },
    { D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT, EResourceStateF::kIndirectArgument                 },
    { D3D12_RESOURCE_STATE_COPY_DEST, EResourceStateF::kCopyDest                         },
    { D3D12_RESOURCE_STATE_COPY_SOURCE, EResourceStateF::kCopySource                       },
    { D3D12_RESOURCE_STATE_RESOLVE_DEST, EResourceStateF::kResolveDest                      },
    { D3D12_RESOURCE_STATE_RESOLVE_SOURCE, EResourceStateF::kResolveSource                    },
    { D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE, EResourceStateF::kRaytracingAccelerationStructure  },
    { D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE, EResourceStateF::kShadingRateSource                },
    { D3D12_RESOURCE_STATE_RESERVED_INTERNAL_8000, EResourceStateF::kReservedInternal8000             },
    { D3D12_RESOURCE_STATE_RESERVED_INTERNAL_4000, EResourceStateF::kReservedInternal4000             },
    { D3D12_RESOURCE_STATE_RESERVED_INTERNAL_100000, EResourceStateF::kReservedInternal100000           },
    { D3D12_RESOURCE_STATE_RESERVED_INTERNAL_40000000, EResourceStateF::kReservedInternal40000000         },
    { D3D12_RESOURCE_STATE_RESERVED_INTERNAL_80000000, EResourceStateF::kReservedInternal80000000         },
    { D3D12_RESOURCE_STATE_GENERIC_READ, EResourceStateF::kGenericRead                      },
    { D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE, EResourceStateF::kAllShaderResource                },
    { D3D12_RESOURCE_STATE_PRESENT, EResourceStateF::kPresent                          },
    { D3D12_RESOURCE_STATE_PREDICATION, EResourceStateF::kPredication                      },
    { D3D12_RESOURCE_STATE_VIDEO_DECODE_READ, EResourceStateF::kVideoDecodeRead                  },
    { D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE, EResourceStateF::kVideoDecodeWrite                 },
    { D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ, EResourceStateF::kVideoProcessRead                 },
    { D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE, EResourceStateF::kVideoProcessWrite                },
    { D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ, EResourceStateF::kVideoEncodeRead                  },
    { D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE, EResourceStateF::kVideoEncodeWrite                 },
  };
  static inline EResourceStateF
  ConvertEResourceStateF(D3D12_RESOURCE_STATES resourceState)
  {
    EResourceStateF ret = {};

    for(auto iter : EResourceStateFMap)
      if(HAS_FLAG(iter.first, resourceState))
        ret |= EResourceStateFMap[iter.first];


    return ret;
  }

  static inline mem::TScope<FClearValue>
  ConvertFClearValue(D3D12_CLEAR_VALUE* clearValue)
  {
    if(clearValue == nullptr) return nullptr;

    FClearValue* ret = new FClearValue();

    ret->Format = ConvertEResourceFormat(clearValue->Format);
    ret->Depth = clearValue->DepthStencil.Depth;
    ret->Stencil = clearValue->DepthStencil.Stencil;

    return ret;
  }

  static std::unordered_map<D3D12_RESOURCE_DIMENSION, EResourceDimension> EResourceDimensionMap =
  {
    { D3D12_RESOURCE_DIMENSION_UNKNOWN, EResourceDimension::kUnknown    },
    { D3D12_RESOURCE_DIMENSION_BUFFER, EResourceDimension::kBuffer     },
    { D3D12_RESOURCE_DIMENSION_TEXTURE1D, EResourceDimension::kTexture1D  },
    { D3D12_RESOURCE_DIMENSION_TEXTURE2D, EResourceDimension::kTexture2D  },
    { D3D12_RESOURCE_DIMENSION_TEXTURE3D, EResourceDimension::kTexture3D  },
  };
  static inline EResourceDimension
  ConvertEResourceDimension(D3D12_RESOURCE_DIMENSION resourceDimension)
  {
    return EResourceDimensionMap[resourceDimension];
  }

  static std::unordered_map<D3D12_TEXTURE_LAYOUT, EResourceLayout> EResourceLayoutMap =
  {
    { D3D12_TEXTURE_LAYOUT_UNKNOWN, EResourceLayout::kUnknown               },
    { D3D12_TEXTURE_LAYOUT_ROW_MAJOR, EResourceLayout::kRowMajor              },
    { D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE, EResourceLayout::kStandardSwizzle64KB   },
    { D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE, EResourceLayout::kUndefinedSwizzle64KB   },
  };
  static inline EResourceLayout
  ConvertEResourceLayout(D3D12_TEXTURE_LAYOUT resourceLayout)
  {
    return EResourceLayoutMap[resourceLayout];
  }

  static std::unordered_map<D3D12_RESOURCE_FLAGS, EResourceF> EResourceFMap =
  {
    { D3D12_RESOURCE_FLAG_NONE, EResourceF::kNone },
    { D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER, EResourceF::kAllowCrossAdapter },
    { D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL, EResourceF::kAllowDepthStencil },
    { D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET, EResourceF::kAllowRenderTarget },
    { D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE, EResourceF::kDenyShaderResource },
    { D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS, EResourceF::kAllowUnorderedAccess },
    { D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS, EResourceF::kAllowSimultaneousAccess },
    { D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY, EResourceF::kVideoDecodeReferenceOnly },
    { D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY, EResourceF::kVideoEncodeReferenceOnly },
    { D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE, EResourceF::kRaytracingAccelerationStructure },
  };
  static inline EResourceF
  ConvertEResourceF(D3D12_RESOURCE_FLAGS resourceFlag)
  {
    EResourceF ret = {};

    for(auto iter : EResourceFMap)
      if(HAS_FLAG(iter.first, resourceFlag))
        ret |= EResourceFMap[iter.first];

    return ret;
  }

  static inline FResource
  ConvertFResource(D3D12_RESOURCE_DESC& desc)
  {
    FResource ret = {
      .Alignment = desc.Alignment,
      .Width = desc.Width,
      .Height = desc.Height,
      .DepthOrArraySize = desc.DepthOrArraySize,
      .MipLevels = desc.MipLevels,
      .Sample = ConvertFSampleDesc(desc.SampleDesc),
      .Format = ConvertEResourceFormat(desc.Format),
      .Flag = ConvertEResourceF(desc.Flags),
      .Layout = ConvertEResourceLayout(desc.Layout),
      .Dimension = ConvertEResourceDimension(desc.Dimension),
    };

    return ret;
  }

  static std::unordered_map<D3D12_HEAP_TYPE, EHeapType> EHeapTypeMap =
  {
    { D3D12_HEAP_TYPE_DEFAULT, EHeapType::kDefault },
    { D3D12_HEAP_TYPE_CUSTOM, EHeapType::kCustom },
    { D3D12_HEAP_TYPE_UPLOAD, EHeapType::kUpload },
    { D3D12_HEAP_TYPE_READBACK, EHeapType::kReadback },
    { D3D12_HEAP_TYPE_GPU_UPLOAD, EHeapType::kGPUUpload },
  };
  static inline EHeapType
  ConvertEHeapType(D3D12_HEAP_TYPE heapType)
  {
    return EHeapTypeMap[heapType];
  }

  static std::unordered_map<D3D12_CPU_PAGE_PROPERTY, ECPUPageProperty> ECPUPagePropertyMap =
  {
    { D3D12_CPU_PAGE_PROPERTY_UNKNOWN, ECPUPageProperty::kUnknown },
    { D3D12_CPU_PAGE_PROPERTY_WRITE_BACK, ECPUPageProperty::kWriteBack },
    { D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE, ECPUPageProperty::kWriteCombine },
    { D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE, ECPUPageProperty::kNotAvailable },
  };
  static inline ECPUPageProperty
  ConvertECPUPageProperty(D3D12_CPU_PAGE_PROPERTY cpuPageProperty)
  {
    return ECPUPagePropertyMap[cpuPageProperty];
  }

  static std::unordered_map<D3D12_MEMORY_POOL, EMemoryPool> EMemoryPoolMap =
  {
    { D3D12_MEMORY_POOL_UNKNOWN, EMemoryPool::kUnknown },
    { D3D12_MEMORY_POOL_L0, EMemoryPool::kL0 },
    { D3D12_MEMORY_POOL_L1, EMemoryPool::kL1 },
  };
  static inline EMemoryPool
  ConvertEMemoryPool(D3D12_MEMORY_POOL memoryPool)
  {
    return EMemoryPoolMap[memoryPool];
  }

  static std::unordered_map<D3D12_HEAP_FLAGS, EHeapF> EHeapFMap =
  {
    { D3D12_HEAP_FLAG_NONE, EHeapF::kNone },
    { D3D12_HEAP_FLAG_SHARED, EHeapF::kShared },
    { D3D12_HEAP_FLAG_DENY_BUFFERS, EHeapF::kDenyBuffers },
    { D3D12_HEAP_FLAG_ALLOW_DISPLAY, EHeapF::kAllowDisplay },
    { D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH, EHeapF::kAllowWriteWatch },
    { D3D12_HEAP_FLAG_CREATE_NOT_ZEROED, EHeapF::kCreateNotZeroed },
    { D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS, EHeapF::kAllowOnlyBuffers },
    { D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT, EHeapF::kCreateNotResident },
    { D3D12_HEAP_FLAG_HARDWARE_PROTECTED, EHeapF::kHardwareProtected },
    { D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS, EHeapF::kAllowShaderAtomics },
    { D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES, EHeapF::kDenyRT_DS_Textures },
    { D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER, EHeapF::kSharedCrossAdapter },
    { D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES, EHeapF::kDenyNonRT_DS_Textures },
    { D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES, EHeapF::kAllowOnlyRT_DS_Textures },
    { D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES, EHeapF::kAllowOnlyNonRT_DS_Textures },
    { D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, EHeapF::kAllowAllBuffersAndTextures },
    { D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING, EHeapF::kToolsUseManualWriteTracking },
  };
  static inline EHeapF
  ConvertEHeapF(D3D12_HEAP_FLAGS heapFlag)
  {
    EHeapF ret = {};

    for ( auto iter : EHeapFMap )
      if ( HAS_FLAG(iter.first, heapFlag) )
        ret |= EHeapFMap[iter.first];

    return ret;
  }

  static inline FHeapProperties
  ConvertFHeapProperty(D3D12_HEAP_PROPERTIES& desc)
  {
    FHeapProperties ret = {
      .Type = ConvertEHeapType(desc.Type),
      .MemoryPool = ConvertEMemoryPool(desc.MemoryPoolPreference),
      .CpuPageProperty = ConvertECPUPageProperty(desc.CPUPageProperty),
    };

    return ret;
  }

  static std::unordered_map<INT, ECommandQueuePriority> ECommandQueuePriorityMap =
  {
    {D3D12_COMMAND_QUEUE_PRIORITY_NORMAL,           ECommandQueuePriority::kNormal },
    {D3D12_COMMAND_QUEUE_PRIORITY_HIGH,             ECommandQueuePriority::kHigh },
    {D3D12_COMMAND_QUEUE_PRIORITY_GLOBAL_REALTIME,  ECommandQueuePriority::kRealtime },
  };
  static inline ECommandQueuePriority
  ConvertECommandQueuePriority(INT commandQueuePriority)
  {
    return ECommandQueuePriorityMap[commandQueuePriority];
  }

  static std::unordered_map<D3D12_RESOURCE_BARRIER_TYPE, EResourceBarrierType> EResourceBarrierTypeMap =
  {
    {D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,EResourceBarrierType::kTransition  },
    {D3D12_RESOURCE_BARRIER_TYPE_UAV,EResourceBarrierType::kUAV  },
    {D3D12_RESOURCE_BARRIER_TYPE_ALIASING,EResourceBarrierType::kAliasing  },
  };
  static inline EResourceBarrierType
  ConvertEResourceBarrierType(D3D12_RESOURCE_BARRIER_TYPE barrierType)
  {
    return EResourceBarrierTypeMap[barrierType];
  }

  static std::unordered_map<D3D12_RESOURCE_BARRIER_FLAGS, EResourceBarrierF> EResourceBarrierFMap =
  {
    {D3D12_RESOURCE_BARRIER_FLAG_NONE,EResourceBarrierF::kNone  },
    {D3D12_RESOURCE_BARRIER_FLAG_END_ONLY,EResourceBarrierF::kEndOnly  },
    {D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY,EResourceBarrierF::kBeginOnly  },
  };
  static inline EResourceBarrierF
  ConvertEResourceBarrierF(D3D12_RESOURCE_BARRIER_FLAGS barrierFlag)
  {
    EResourceBarrierF ret = {};

    for ( auto iter : EResourceBarrierFMap )
      if ( HAS_FLAG(iter.first, barrierFlag) )
        ret |= EResourceBarrierFMap[iter.first];

    return ret;
  }

  static std::unordered_map<UINT, ESwapChainF> ESwapChainFMap =
  {
    {0, ESwapChainF::kNone},
    {DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO,ESwapChainF::kYuvVideo  },
    {DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY,ESwapChainF::kDisplayOnly  },
    {DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED,ESwapChainF::kHWProtected  },
    {DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING,ESwapChainF::kAllowTearing  },
    {DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE,ESwapChainF::kGDICompatible  },
    {DXGI_SWAP_CHAIN_FLAG_NONPREROTATED,ESwapChainF::kNonprerotated  },
    {DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH,ESwapChainF::kAllowModeSwitch  },
    {DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER,ESwapChainF::kForegroundLayer },
    {DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO,ESwapChainF::kFullscreenVideo },
    {DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT,ESwapChainF::kRestrictedContent  },
    {DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT,ESwapChainF::kFrameLatencyWaitableObject  },
    {DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER,ESwapChainF::kRestrictSharedResourceDriver  },
    {DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS,ESwapChainF::kRestrictedToAllHolographicDisplays  },
  };
  static inline ESwapChainF
  ConvertESwapChainF(UINT flag)
  {
    ESwapChainF ret = ESwapChainF::kNone;

    for ( auto iter : ESwapChainFMap )
      if ( HAS_FLAG(iter.first, flag) )
        ret |= ESwapChainFMap[iter.first];

    return ret;
  }
}

}
