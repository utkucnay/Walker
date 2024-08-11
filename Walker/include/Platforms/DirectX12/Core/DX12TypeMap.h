#pragma once

#include "Core/Base.h"
#include "Render/Resource/Heap.h"
#include "Render/Resource/Resource.h"
#include "d3d12.h"
#include <Render/Descriptor/DescriptorTypes.h>
#include <Render/Resource/ResourceTypes.h>
#include <Render/Command/CommandTypes.h>
#include <Render/Core/CoreTypes.h>
#include <unordered_map>

namespace wkr::render::dx12
{
  static inline D3D12_COMMAND_LIST_TYPE
  ConvertECommandType(ECommandType commandType)
  {
    static std::unordered_map<ECommandType, D3D12_COMMAND_LIST_TYPE> map =
    {
      {ECommandType::Bundle,        D3D12_COMMAND_LIST_TYPE_BUNDLE        },
      {ECommandType::Direct,        D3D12_COMMAND_LIST_TYPE_DIRECT        },
      {ECommandType::Compute,       D3D12_COMMAND_LIST_TYPE_COMPUTE       },
      {ECommandType::Copy,          D3D12_COMMAND_LIST_TYPE_COPY          },
      {ECommandType::VideoDecode,   D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE  },
      {ECommandType::VideoProcess,  D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS },
      {ECommandType::VideoEncode,   D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE  },
      {ECommandType::None,          D3D12_COMMAND_LIST_TYPE_NONE          },
    };

    return map[commandType];
  }

  static inline D3D12_COMMAND_QUEUE_FLAGS
  ConvertECommandQueueFlags(ECommandQueueFlags flag)
  {
    static std::unordered_map<ECommandQueueFlags, D3D12_COMMAND_QUEUE_FLAGS> map =
    {
      {ECommandQueueFlags::None,              D3D12_COMMAND_QUEUE_FLAG_NONE               },
      {ECommandQueueFlags::DisableGPUTimeout, D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT},
    };

    D3D12_COMMAND_QUEUE_FLAGS ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, flag))
        ret |= map[iter.first];

    return ret;
  }

  static inline D3D12_FENCE_FLAGS
  ConvertEFenceFlags(EFenceFlag flag)
  {
    static std::unordered_map<EFenceFlag, D3D12_FENCE_FLAGS> map =
    {
      {EFenceFlag::None,                D3D12_FENCE_FLAG_NONE},
      {EFenceFlag::Shared,              D3D12_FENCE_FLAG_SHARED},
      {EFenceFlag::NonMonitored,        D3D12_FENCE_FLAG_NON_MONITORED},
      {EFenceFlag::SharedCrossAdapter,  D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER},
    };

    D3D12_FENCE_FLAGS ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, flag))
        ret |= map[iter.first];

    return ret;
  }

  static inline DXGI_USAGE
  ConvertEResourceUsageMap(EResourceUsageF flag)
  {
    static std::unordered_map<EResourceUsageF, DXGI_USAGE> map =
    {
      {EResourceUsageF::SHARED, DXGI_USAGE_SHARED},
      {EResourceUsageF::READ_ONLY, DXGI_USAGE_READ_ONLY},
      {EResourceUsageF::SHADER_INPUT, DXGI_USAGE_SHADER_INPUT},
      {EResourceUsageF::BACK_BUFFER, DXGI_USAGE_BACK_BUFFER},
      {EResourceUsageF::UNORDERED_ACCESS, DXGI_USAGE_UNORDERED_ACCESS},
      {EResourceUsageF::RENDER_TARGET_OUTPUT, DXGI_USAGE_RENDER_TARGET_OUTPUT},
      {EResourceUsageF::DISCARD_ON_PRESENT, DXGI_USAGE_DISCARD_ON_PRESENT},

      {EResourceUsageF::CPU_ACCESS_NONE, DXGI_CPU_ACCESS_NONE},
      {EResourceUsageF::CPU_ACCESS_FIELD, DXGI_CPU_ACCESS_FIELD},
      {EResourceUsageF::CPU_ACCESS_DYNAMIC, DXGI_CPU_ACCESS_DYNAMIC},
      {EResourceUsageF::CPU_ACCESS_SCRATCH, DXGI_CPU_ACCESS_SCRATCH},
      {EResourceUsageF::CPU_ACCESS_READ_WRITE, DXGI_CPU_ACCESS_READ_WRITE},
    };

    DXGI_USAGE ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, flag))
        ret |= map[iter.first];

    return ret;
  }

  static inline DXGI_FORMAT
  ConvertEResourceFormat(EResourceFormat format)
  {
    static std::unordered_map<EResourceFormat, DXGI_FORMAT> map =
    {
      { EResourceFormat::UNKNOWN, DXGI_FORMAT_UNKNOWN },
      { EResourceFormat::R32G32B32A32_TYPELESS, DXGI_FORMAT_R32G32B32A32_TYPELESS },
      { EResourceFormat::R32G32B32A32_FLOAT, DXGI_FORMAT_R32G32B32A32_FLOAT },
      { EResourceFormat::R32G32B32A32_UINT, DXGI_FORMAT_R32G32B32A32_UINT },
      { EResourceFormat::R32G32B32A32_SINT, DXGI_FORMAT_R32G32B32A32_SINT },
      { EResourceFormat::R32G32B32_TYPELESS, DXGI_FORMAT_R32G32B32_TYPELESS },
      { EResourceFormat::R32G32B32_FLOAT, DXGI_FORMAT_R32G32B32_FLOAT },
      { EResourceFormat::R32G32B32_UINT, DXGI_FORMAT_R32G32B32_UINT },
      { EResourceFormat::R32G32B32_SINT, DXGI_FORMAT_R32G32B32_SINT },
      { EResourceFormat::R16G16B16A16_TYPELESS, DXGI_FORMAT_R16G16B16A16_TYPELESS },
      { EResourceFormat::R16G16B16A16_FLOAT, DXGI_FORMAT_R16G16B16A16_FLOAT },
      { EResourceFormat::R16G16B16A16_UNORM, DXGI_FORMAT_R16G16B16A16_UNORM },
      { EResourceFormat::R16G16B16A16_UINT, DXGI_FORMAT_R16G16B16A16_UINT },
      { EResourceFormat::R16G16B16A16_SNORM, DXGI_FORMAT_R16G16B16A16_SNORM },
      { EResourceFormat::R16G16B16A16_SINT, DXGI_FORMAT_R16G16B16A16_SINT },
      { EResourceFormat::R32G32_TYPELESS, DXGI_FORMAT_R32G32_TYPELESS },
      { EResourceFormat::R32G32_FLOAT, DXGI_FORMAT_R32G32_FLOAT },
      { EResourceFormat::R32G32_UINT, DXGI_FORMAT_R32G32_UINT },
      { EResourceFormat::R32G32_SINT, DXGI_FORMAT_R32G32_SINT },
      { EResourceFormat::R32G8X24_TYPELESS, DXGI_FORMAT_R32G8X24_TYPELESS },
      { EResourceFormat::D32_FLOAT_S8X24_UINT, DXGI_FORMAT_D32_FLOAT_S8X24_UINT },
      { EResourceFormat::R32_FLOAT_X8X24_TYPELESS, DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS },
      { EResourceFormat::X32_TYPELESS_G8X24_UINT, DXGI_FORMAT_X32_TYPELESS_G8X24_UINT },
      { EResourceFormat::R10G10B10A2_TYPELESS, DXGI_FORMAT_R10G10B10A2_TYPELESS },
      { EResourceFormat::R10G10B10A2_UNORM, DXGI_FORMAT_R10G10B10A2_UNORM },
      { EResourceFormat::R10G10B10A2_UINT, DXGI_FORMAT_R10G10B10A2_UINT },
      { EResourceFormat::R11G11B10_FLOAT, DXGI_FORMAT_R11G11B10_FLOAT },
      { EResourceFormat::R8G8B8A8_TYPELESS, DXGI_FORMAT_R8G8B8A8_TYPELESS },
      { EResourceFormat::R8G8B8A8_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM },
      { EResourceFormat::R8G8B8A8_UNORM_SRGB, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB },
      { EResourceFormat::R8G8B8A8_UINT, DXGI_FORMAT_R8G8B8A8_UINT },
      { EResourceFormat::R8G8B8A8_SNORM, DXGI_FORMAT_R8G8B8A8_SNORM },
      { EResourceFormat::R8G8B8A8_SINT, DXGI_FORMAT_R8G8B8A8_SINT },
      { EResourceFormat::R16G16_TYPELESS, DXGI_FORMAT_R16G16_TYPELESS },
      { EResourceFormat::R16G16_FLOAT, DXGI_FORMAT_R16G16_FLOAT },
      { EResourceFormat::R16G16_UNORM, DXGI_FORMAT_R16G16_UNORM },
      { EResourceFormat::R16G16_UINT, DXGI_FORMAT_R16G16_UINT },
      { EResourceFormat::R16G16_SNORM, DXGI_FORMAT_R16G16_SNORM },
      { EResourceFormat::R16G16_SINT, DXGI_FORMAT_R16G16_SINT },
      { EResourceFormat::R32_TYPELESS, DXGI_FORMAT_R32_TYPELESS },
      { EResourceFormat::D32_FLOAT, DXGI_FORMAT_D32_FLOAT },
      { EResourceFormat::R32_FLOAT, DXGI_FORMAT_R32_FLOAT },
      { EResourceFormat::R32_UINT, DXGI_FORMAT_R32_UINT },
      { EResourceFormat::R32_SINT, DXGI_FORMAT_R32_SINT },
      { EResourceFormat::R24G8_TYPELESS, DXGI_FORMAT_R24G8_TYPELESS },
      { EResourceFormat::D24_UNORM_S8_UINT, DXGI_FORMAT_D24_UNORM_S8_UINT },
      { EResourceFormat::R24_UNORM_X8_TYPELESS, DXGI_FORMAT_R24_UNORM_X8_TYPELESS },
      { EResourceFormat::X24_TYPELESS_G8_UINT, DXGI_FORMAT_X24_TYPELESS_G8_UINT },
      { EResourceFormat::R8G8_TYPELESS, DXGI_FORMAT_R8G8_TYPELESS },
      { EResourceFormat::R8G8_UNORM, DXGI_FORMAT_R8G8_UNORM },
      { EResourceFormat::R8G8_UINT, DXGI_FORMAT_R8G8_UINT },
      { EResourceFormat::R8G8_SNORM, DXGI_FORMAT_R8G8_SNORM },
      { EResourceFormat::R8G8_SINT, DXGI_FORMAT_R8G8_SINT },
      { EResourceFormat::R16_TYPELESS, DXGI_FORMAT_R16_TYPELESS },
      { EResourceFormat::R16_FLOAT, DXGI_FORMAT_R16_FLOAT },
      { EResourceFormat::D16_UNORM, DXGI_FORMAT_D16_UNORM },
      { EResourceFormat::R16_UNORM, DXGI_FORMAT_R16_UNORM },
      { EResourceFormat::R16_UINT, DXGI_FORMAT_R16_UINT },
      { EResourceFormat::R16_SNORM, DXGI_FORMAT_R16_SNORM },
      { EResourceFormat::R16_SINT, DXGI_FORMAT_R16_SINT },
      { EResourceFormat::R8_TYPELESS, DXGI_FORMAT_R8_TYPELESS },
      { EResourceFormat::R8_UNORM, DXGI_FORMAT_R8_UNORM },
      { EResourceFormat::R8_UINT, DXGI_FORMAT_R8_UINT },
      { EResourceFormat::R8_SNORM, DXGI_FORMAT_R8_SNORM },
      { EResourceFormat::R8_SINT, DXGI_FORMAT_R8_SINT },
      { EResourceFormat::A8_UNORM, DXGI_FORMAT_A8_UNORM },
      { EResourceFormat::R1_UNORM, DXGI_FORMAT_R1_UNORM },
      { EResourceFormat::R9G9B9E5_SHAREDEXP, DXGI_FORMAT_R9G9B9E5_SHAREDEXP },
      { EResourceFormat::R8G8_B8G8_UNORM, DXGI_FORMAT_R8G8_B8G8_UNORM },
      { EResourceFormat::G8R8_G8B8_UNORM, DXGI_FORMAT_G8R8_G8B8_UNORM },
      { EResourceFormat::BC1_TYPELESS, DXGI_FORMAT_BC1_TYPELESS },
      { EResourceFormat::BC1_UNORM, DXGI_FORMAT_BC1_UNORM },
      { EResourceFormat::BC1_UNORM_SRGB, DXGI_FORMAT_BC1_UNORM_SRGB },
      { EResourceFormat::BC2_TYPELESS, DXGI_FORMAT_BC2_TYPELESS },
      { EResourceFormat::BC2_UNORM, DXGI_FORMAT_BC2_UNORM },
      { EResourceFormat::BC2_UNORM_SRGB, DXGI_FORMAT_BC2_UNORM_SRGB },
      { EResourceFormat::BC3_TYPELESS, DXGI_FORMAT_BC3_TYPELESS },
      { EResourceFormat::BC3_UNORM, DXGI_FORMAT_BC3_UNORM },
      { EResourceFormat::BC3_UNORM_SRGB, DXGI_FORMAT_BC3_UNORM_SRGB },
      { EResourceFormat::BC4_TYPELESS, DXGI_FORMAT_BC4_TYPELESS },
      { EResourceFormat::BC4_UNORM, DXGI_FORMAT_BC4_UNORM },
      { EResourceFormat::BC4_SNORM, DXGI_FORMAT_BC4_SNORM },
      { EResourceFormat::BC5_TYPELESS, DXGI_FORMAT_BC5_TYPELESS },
      { EResourceFormat::BC5_UNORM, DXGI_FORMAT_BC5_UNORM },
      { EResourceFormat::BC5_SNORM, DXGI_FORMAT_BC5_SNORM },
      { EResourceFormat::B5G6R5_UNORM, DXGI_FORMAT_B5G6R5_UNORM },
      { EResourceFormat::B5G5R5A1_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM },
      { EResourceFormat::B8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM },
      { EResourceFormat::B8G8R8X8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM },
      { EResourceFormat::R10G10B10_XR_BIAS_A2_UNORM, DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM },
      { EResourceFormat::B8G8R8A8_TYPELESS, DXGI_FORMAT_B8G8R8A8_TYPELESS },
      { EResourceFormat::B8G8R8A8_UNORM_SRGB, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB },
      { EResourceFormat::B8G8R8X8_TYPELESS, DXGI_FORMAT_B8G8R8X8_TYPELESS },
      { EResourceFormat::B8G8R8X8_UNORM_SRGB, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB },
      { EResourceFormat::BC6H_TYPELESS, DXGI_FORMAT_BC6H_TYPELESS },
      { EResourceFormat::BC6H_UF16, DXGI_FORMAT_BC6H_UF16 },
      { EResourceFormat::BC6H_SF16, DXGI_FORMAT_BC6H_SF16 },
      { EResourceFormat::BC7_TYPELESS, DXGI_FORMAT_BC7_TYPELESS },
      { EResourceFormat::BC7_UNORM, DXGI_FORMAT_BC7_UNORM },
      { EResourceFormat::BC7_UNORM_SRGB, DXGI_FORMAT_BC7_UNORM_SRGB },
      { EResourceFormat::AYUV, DXGI_FORMAT_AYUV },
      { EResourceFormat::Y410, DXGI_FORMAT_Y410 },
      { EResourceFormat::Y416, DXGI_FORMAT_Y416 },
      { EResourceFormat::NV12, DXGI_FORMAT_NV12 },
      { EResourceFormat::P010, DXGI_FORMAT_P010 },
      { EResourceFormat::P016, DXGI_FORMAT_P016 },
      { EResourceFormat::YUY2, DXGI_FORMAT_YUY2 },
      { EResourceFormat::Y210, DXGI_FORMAT_Y210 },
      { EResourceFormat::Y216, DXGI_FORMAT_Y216 },
      { EResourceFormat::NV11, DXGI_FORMAT_NV11 },
      { EResourceFormat::AI44, DXGI_FORMAT_AI44 },
      { EResourceFormat::IA44, DXGI_FORMAT_IA44 },
      { EResourceFormat::P8, DXGI_FORMAT_P8 },
      { EResourceFormat::A8P8, DXGI_FORMAT_A8P8 },
      { EResourceFormat::B4G4R4A4_UNORM, DXGI_FORMAT_B4G4R4A4_UNORM },
      { EResourceFormat::P208, DXGI_FORMAT_P208 },
      { EResourceFormat::V208, DXGI_FORMAT_V208 },
      { EResourceFormat::V408, DXGI_FORMAT_V408 },
      { EResourceFormat::SAMPLER_FEEDBACK_MIN_MIP_OPAQUE, DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE },
      { EResourceFormat::SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE, DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE },
      { EResourceFormat::FORCE_UINT, DXGI_FORMAT_FORCE_UINT },
    };

    return map[format];
  }

  static inline DXGI_MODE_SCALING
  ConvertEScaling(EScaling scaling)
  {
    static std::unordered_map<EScaling, DXGI_MODE_SCALING> map =
    {
      { EScaling::Centered, DXGI_MODE_SCALING_CENTERED },
      { EScaling::Stretched, DXGI_MODE_SCALING_STRETCHED },
      { EScaling::Unspecified, DXGI_MODE_SCALING_UNSPECIFIED },
    };

    return map[scaling];
  }

  static inline DXGI_MODE_SCANLINE_ORDER
  ConvertEScanlineOrder(EScanlineOrder scanlineOrder)
  {
    static std::unordered_map<EScanlineOrder, DXGI_MODE_SCANLINE_ORDER> map =
    {
      { EScanlineOrder::Unspecified, DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED },
      { EScanlineOrder::Progressive, DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE },
      { EScanlineOrder::LowerFieldFirst, DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST },
      { EScanlineOrder::UpperFieldFirst, DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST },
    };

    return map[scanlineOrder];
  }

  static inline DXGI_SWAP_EFFECT
  ConvertESwapChainEffect(ESwapChainEffect swapChainEffect)
  {
    static std::unordered_map<ESwapChainEffect, DXGI_SWAP_EFFECT> map =
    {
      { ESwapChainEffect::Discard, DXGI_SWAP_EFFECT_DISCARD },
      { ESwapChainEffect::Sequential, DXGI_SWAP_EFFECT_SEQUENTIAL },
      { ESwapChainEffect::FlipDiscard, DXGI_SWAP_EFFECT_FLIP_DISCARD },
      { ESwapChainEffect::FlipSequential, DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL },
    };

    return map[swapChainEffect];
  }

  static inline D3D12_DESCRIPTOR_HEAP_TYPE
  ConvertEDescriptorHeapType(EDescriptorHeapType descriptorHeapType)
  {
    static std::unordered_map<EDescriptorHeapType, D3D12_DESCRIPTOR_HEAP_TYPE> map =
    {
      { EDescriptorHeapType::DSV, D3D12_DESCRIPTOR_HEAP_TYPE_DSV },
      { EDescriptorHeapType::RTV, D3D12_DESCRIPTOR_HEAP_TYPE_RTV },
      { EDescriptorHeapType::Sampler, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER },
      { EDescriptorHeapType::CBV_SRV_UAV, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV },
      { EDescriptorHeapType::NumTypes, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES },
    };

    return map[descriptorHeapType];
  }

  static inline D3D12_DESCRIPTOR_HEAP_FLAGS
  ConvertEDescriptorHeapFlag(EDescriptorHeapFlags descriptorHeapFlag)
  {
    static std::unordered_map<EDescriptorHeapFlags, D3D12_DESCRIPTOR_HEAP_FLAGS> map =
    {
      { EDescriptorHeapFlags::None, D3D12_DESCRIPTOR_HEAP_FLAG_NONE },
      { EDescriptorHeapFlags::ShaderVisable, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE },
    };

    D3D12_DESCRIPTOR_HEAP_FLAGS ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, descriptorHeapFlag))
        ret |= map[iter.first];

    return ret;
  }

  static inline DXGI_SAMPLE_DESC
  ConvertFSampleDesc(FSample& desc)
  {
    DXGI_SAMPLE_DESC ret = {};

    ret.Count = desc.count;
    ret.Quality = desc.quality;

    return ret;
  }

  static inline D3D12_RESOURCE_STATES
  ConvertEResourceState(EResourceStateF resourceState)
  {
    static std::unordered_map<EResourceStateF, D3D12_RESOURCE_STATES> map =
    {
      { EResourceStateF::Common                          , D3D12_RESOURCE_STATE_COMMON },
      { EResourceStateF::VertexAndConstantBuffer         , D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER },
      { EResourceStateF::IndexBuffer                     , D3D12_RESOURCE_STATE_INDEX_BUFFER },
      { EResourceStateF::RenderTarget                    , D3D12_RESOURCE_STATE_RENDER_TARGET },
      { EResourceStateF::UnorederedAccess                , D3D12_RESOURCE_STATE_UNORDERED_ACCESS },
      { EResourceStateF::DepthWrite                      , D3D12_RESOURCE_STATE_DEPTH_WRITE },
      { EResourceStateF::DepthRead                       , D3D12_RESOURCE_STATE_DEPTH_READ },
      { EResourceStateF::NonPixelShaderResource          , D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE },
      { EResourceStateF::PixelShaderResource             , D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE },
      { EResourceStateF::StreamOut                       , D3D12_RESOURCE_STATE_STREAM_OUT },
      { EResourceStateF::IndirectArgument                , D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT },
      { EResourceStateF::CopyDest                        , D3D12_RESOURCE_STATE_COPY_DEST },
      { EResourceStateF::CopySource                      , D3D12_RESOURCE_STATE_COPY_SOURCE },
      { EResourceStateF::ResolveDest                     , D3D12_RESOURCE_STATE_RESOLVE_DEST },
      { EResourceStateF::ResolveSource                   , D3D12_RESOURCE_STATE_RESOLVE_SOURCE },
      { EResourceStateF::RaytracingAccelerationStructure , D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE },
      { EResourceStateF::ShadingRateSource               , D3D12_RESOURCE_STATE_SHADING_RATE_SOURCE },
      { EResourceStateF::ReservedInternal8000            , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_8000 },
      { EResourceStateF::ReservedInternal4000            , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_4000 },
      { EResourceStateF::ReservedInternal100000          , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_100000 },
      { EResourceStateF::ReservedInternal40000000        , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_40000000 },
      { EResourceStateF::ReservedInternal80000000        , D3D12_RESOURCE_STATE_RESERVED_INTERNAL_80000000 },
      { EResourceStateF::GenericRead                     , D3D12_RESOURCE_STATE_GENERIC_READ },
      { EResourceStateF::AllShaderResource               , D3D12_RESOURCE_STATE_ALL_SHADER_RESOURCE },
      { EResourceStateF::Present                         , D3D12_RESOURCE_STATE_PRESENT },
      { EResourceStateF::Predication                     , D3D12_RESOURCE_STATE_PREDICATION },
      { EResourceStateF::VideoDecodeRead                 , D3D12_RESOURCE_STATE_VIDEO_DECODE_READ },
      { EResourceStateF::VideoDecodeWrite                , D3D12_RESOURCE_STATE_VIDEO_DECODE_WRITE },
      { EResourceStateF::VideoProcessRead                , D3D12_RESOURCE_STATE_VIDEO_PROCESS_READ },
      { EResourceStateF::VideoProcessWrite               , D3D12_RESOURCE_STATE_VIDEO_PROCESS_WRITE },
      { EResourceStateF::VideoEncodeRead                 , D3D12_RESOURCE_STATE_VIDEO_ENCODE_READ },
      { EResourceStateF::VideoEncodeWrite                , D3D12_RESOURCE_STATE_VIDEO_ENCODE_WRITE },
    };

    D3D12_RESOURCE_STATES ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, resourceState))
        ret |= map[iter.first];


    return map[resourceState];
  }

  static inline mem::TScope<D3D12_CLEAR_VALUE>
  ConvertFClearValue(FClearValue* clearValue)
  {
    if(clearValue == nullptr) return nullptr;

    D3D12_CLEAR_VALUE* ret = new D3D12_CLEAR_VALUE();

    ret->Format = ConvertEResourceFormat(clearValue->format);
    ret->DepthStencil.Depth = clearValue->depthStencil.depth;
    ret->DepthStencil.Stencil = clearValue->depthStencil.stencil;

    return ret;
  }

  static inline D3D12_RESOURCE_DIMENSION
  ConvertEResourceDimension(EResourceDimension resourceDimension)
  {
    static std::unordered_map<EResourceDimension, D3D12_RESOURCE_DIMENSION> map =
    {
      { EResourceDimension::Unknown   , D3D12_RESOURCE_DIMENSION_UNKNOWN },
      { EResourceDimension::Buffer    , D3D12_RESOURCE_DIMENSION_BUFFER },
      { EResourceDimension::Texture1D , D3D12_RESOURCE_DIMENSION_TEXTURE1D },
      { EResourceDimension::Texture2D , D3D12_RESOURCE_DIMENSION_TEXTURE2D },
      { EResourceDimension::Texture3D , D3D12_RESOURCE_DIMENSION_TEXTURE3D },
    };

    return map[resourceDimension];
  }

  static inline D3D12_TEXTURE_LAYOUT
  ConvertEResourceLayout(EResourceLayout resourceLayout)
  {
    static std::unordered_map<EResourceLayout, D3D12_TEXTURE_LAYOUT> map =
    {
      { EResourceLayout::Unknown              , D3D12_TEXTURE_LAYOUT_UNKNOWN },
      { EResourceLayout::RowMajor             , D3D12_TEXTURE_LAYOUT_ROW_MAJOR },
      { EResourceLayout::StandardSwizzle64KB  , D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE },
      { EResourceLayout::UndefinedSwizzle64KB , D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE  },
    };

    return map[resourceLayout];
  }

  static inline D3D12_RESOURCE_FLAGS
  ConvertEResourceF(EResourceF resourceFlag)
  {
    static std::unordered_map<EResourceF, D3D12_RESOURCE_FLAGS> map =
    {
      { EResourceF::None, D3D12_RESOURCE_FLAG_NONE },
      { EResourceF::AllowCrossAdapter, D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER },
      { EResourceF::AllowDepthStencil, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL },
      { EResourceF::AllowRenderTarget, D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET },
      { EResourceF::DenyShaderResource, D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE },
      { EResourceF::AllowUnorderedAccess, D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS },
      { EResourceF::AllowSimultaneousAccess, D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS },
      { EResourceF::VideoDecodeReferenceOnly, D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY },
      { EResourceF::VideoEncodeReferenceOnly, D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY },
      { EResourceF::RaytracingAccelerationStructure, D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE },
    };

    D3D12_RESOURCE_FLAGS ret = {};

    for(auto iter : map)
      if(HAS_FLAG(iter.first, resourceFlag))
        ret |= map[iter.first];

    return ret;
  }

  static inline mem::TScope<D3D12_RESOURCE_DESC>
  ConvertFResource(FResource& desc)
  {
    D3D12_RESOURCE_DESC* ret = new D3D12_RESOURCE_DESC();

    ret->Dimension = ConvertEResourceDimension(desc.dimension);
    ret->Alignment = desc.alignment;
    ret->Width = desc.width;
    ret->Height = desc.height;
    ret->DepthOrArraySize = desc.depthOrArraySize;
    ret->MipLevels = desc.mipLevels;
    ret->Format = ConvertEResourceFormat(desc.format);
    ret->SampleDesc = ConvertFSampleDesc(desc.sample);
    ret->Layout = ConvertEResourceLayout(desc.layout);
    ret->Flags = ConvertEResourceF(desc.flag);

    return ret;
  }

  static inline D3D12_HEAP_TYPE
  ConvertEHeapType(EHeapType heapType)
  {
    static std::unordered_map<EHeapType, D3D12_HEAP_TYPE> map =
    {
      { EHeapType::Default, D3D12_HEAP_TYPE_DEFAULT },
      { EHeapType::Custom, D3D12_HEAP_TYPE_CUSTOM },
      { EHeapType::Upload, D3D12_HEAP_TYPE_UPLOAD },
      { EHeapType::Readback, D3D12_HEAP_TYPE_READBACK },
      { EHeapType::GPUUpload, D3D12_HEAP_TYPE_GPU_UPLOAD },
    };

    return map[heapType];
  }

  static inline D3D12_CPU_PAGE_PROPERTY
  ConvertECPUPageProperty(ECPUPageProperty cpuPageProperty)
  {
    static std::unordered_map<ECPUPageProperty, D3D12_CPU_PAGE_PROPERTY> map =
    {
      { ECPUPageProperty::Unknown, D3D12_CPU_PAGE_PROPERTY_UNKNOWN },
      { ECPUPageProperty::WriteBack, D3D12_CPU_PAGE_PROPERTY_WRITE_BACK },
      { ECPUPageProperty::WriteCombine, D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE },
      { ECPUPageProperty::NotAvailable, D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE },
    };

    return map[cpuPageProperty];
  }

  static inline D3D12_MEMORY_POOL
  ConvertEMemoryPool(EMemoryPool memoryPool)
  {
    static std::unordered_map<EMemoryPool, D3D12_MEMORY_POOL> map =
    {
      { EMemoryPool::Unknown, D3D12_MEMORY_POOL_UNKNOWN },
      { EMemoryPool::L0, D3D12_MEMORY_POOL_L0 },
      { EMemoryPool::L1, D3D12_MEMORY_POOL_L1 },
    };

    return map[memoryPool];
  }

  static inline D3D12_HEAP_FLAGS
  ConvertEHeapF(EHeapF heapFlag)
  {
    static std::unordered_map<EHeapF, D3D12_HEAP_FLAGS> map =
    {
      { EHeapF::None, D3D12_HEAP_FLAG_NONE },
      { EHeapF::Shared, D3D12_HEAP_FLAG_SHARED },
      { EHeapF::DenyBuffers, D3D12_HEAP_FLAG_DENY_BUFFERS },
      { EHeapF::AllowDisplay, D3D12_HEAP_FLAG_ALLOW_DISPLAY },
      { EHeapF::AllowWriteWatch, D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH },
      { EHeapF::CreateNotZeroed, D3D12_HEAP_FLAG_CREATE_NOT_ZEROED },
      { EHeapF::AllowOnlyBuffers, D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS },
      { EHeapF::CreateNotResident, D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT },
      { EHeapF::HardwareProtected, D3D12_HEAP_FLAG_HARDWARE_PROTECTED },
      { EHeapF::AllowShaderAtomics, D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS },
      { EHeapF::DenyRT_DS_Textures, D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES },
      { EHeapF::SharedCrossAdapter, D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER },
      { EHeapF::DenyNonRT_DS_Textures, D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES },
      { EHeapF::AllowOnlyRT_DS_Textures, D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES },
      { EHeapF::AllowOnlyNonRT_DS_Textures, D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES },
      { EHeapF::AllowAllBuffersAndTextures, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES },
      { EHeapF::ToolsUseManualWriteTracking, D3D12_HEAP_FLAG_TOOLS_USE_MANUAL_WRITE_TRACKING },
    };

    D3D12_HEAP_FLAGS ret = {};

    for ( auto iter : map )
      if ( HAS_FLAG(iter.first, heapFlag) )
        ret |= map[iter.first];

    return ret;
  }

  static inline mem::TScope<D3D12_HEAP_PROPERTIES>
  ConvertFHeapDesc(FHeapDesc& desc)
  {
    D3D12_HEAP_PROPERTIES* ret = new D3D12_HEAP_PROPERTIES();

    ret->Type = ConvertEHeapType(desc.m_type);
    ret->CPUPageProperty = ConvertECPUPageProperty(desc.m_cpuPageProperty);
    ret->MemoryPoolPreference = ConvertEMemoryPool(desc.m_memoryPool);

    return ret;
  }
}
