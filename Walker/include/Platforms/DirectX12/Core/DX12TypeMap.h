#pragma once

#include "Render/Descriptor/DescriptorTypes.h"
#include "d3d12.h"
#include "dxgiformat.h"
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

    if(HAS_FLAG(ECommandQueueFlags::None, flag))
      ret |= map[ECommandQueueFlags::None];

    if(HAS_FLAG(ECommandQueueFlags::DisableGPUTimeout, flag))
      ret |= map[ECommandQueueFlags::DisableGPUTimeout];

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

    if(HAS_FLAG(EFenceFlag::None, flag))
      ret |= map[EFenceFlag::None];

    if(HAS_FLAG(EFenceFlag::Shared, flag))
      ret |= map[EFenceFlag::Shared];

    if(HAS_FLAG(EFenceFlag::NonMonitored, flag))
      ret |= map[EFenceFlag::NonMonitored];

    if(HAS_FLAG(EFenceFlag::SharedCrossAdapter, flag))
      ret |= map[EFenceFlag::SharedCrossAdapter];

    return ret;
  }

  static inline DXGI_USAGE
  ConvertEResourceUsageMap(EResourceUsageFlag flag)
  {
    static std::unordered_map<EResourceUsageFlag, DXGI_USAGE> map =
    {
      {EResourceUsageFlag::SHARED, DXGI_USAGE_SHARED},
      {EResourceUsageFlag::READ_ONLY, DXGI_USAGE_READ_ONLY},
      {EResourceUsageFlag::SHADER_INPUT, DXGI_USAGE_SHADER_INPUT},
      {EResourceUsageFlag::BACK_BUFFER, DXGI_USAGE_BACK_BUFFER},
      {EResourceUsageFlag::UNORDERED_ACCESS, DXGI_USAGE_UNORDERED_ACCESS},
      {EResourceUsageFlag::RENDER_TARGET_OUTPUT, DXGI_USAGE_RENDER_TARGET_OUTPUT},
      {EResourceUsageFlag::DISCARD_ON_PRESENT, DXGI_USAGE_DISCARD_ON_PRESENT},

      {EResourceUsageFlag::CPU_ACCESS_NONE, DXGI_CPU_ACCESS_NONE},
      {EResourceUsageFlag::CPU_ACCESS_FIELD, DXGI_CPU_ACCESS_FIELD},
      {EResourceUsageFlag::CPU_ACCESS_DYNAMIC, DXGI_CPU_ACCESS_DYNAMIC},
      {EResourceUsageFlag::CPU_ACCESS_SCRATCH, DXGI_CPU_ACCESS_SCRATCH},
      {EResourceUsageFlag::CPU_ACCESS_READ_WRITE, DXGI_CPU_ACCESS_READ_WRITE},
    };

    DXGI_USAGE ret = {};

    if(HAS_FLAG(EResourceUsageFlag::SHARED, flag)) ret |= map[EResourceUsageFlag::SHARED];
    if(HAS_FLAG(EResourceUsageFlag::READ_ONLY, flag)) ret |= map[EResourceUsageFlag::READ_ONLY];
    if(HAS_FLAG(EResourceUsageFlag::SHADER_INPUT, flag)) ret |= map[EResourceUsageFlag::SHADER_INPUT];
    if(HAS_FLAG(EResourceUsageFlag::BACK_BUFFER, flag)) ret |= map[EResourceUsageFlag::BACK_BUFFER];
    if(HAS_FLAG(EResourceUsageFlag::UNORDERED_ACCESS, flag)) ret |= map[EResourceUsageFlag::UNORDERED_ACCESS];
    if(HAS_FLAG(EResourceUsageFlag::RENDER_TARGET_OUTPUT, flag)) ret |= map[EResourceUsageFlag::RENDER_TARGET_OUTPUT];
    if(HAS_FLAG(EResourceUsageFlag::DISCARD_ON_PRESENT, flag)) ret |= map[EResourceUsageFlag::DISCARD_ON_PRESENT];

    if(HAS_FLAG(EResourceUsageFlag::CPU_ACCESS_NONE, flag)) ret |= map[EResourceUsageFlag::CPU_ACCESS_NONE];
    if(HAS_FLAG(EResourceUsageFlag::CPU_ACCESS_READ_WRITE, flag)) ret |= map[EResourceUsageFlag::CPU_ACCESS_READ_WRITE];
    if(HAS_FLAG(EResourceUsageFlag::CPU_ACCESS_SCRATCH, flag)) ret |= map[EResourceUsageFlag::CPU_ACCESS_SCRATCH];
    if(HAS_FLAG(EResourceUsageFlag::CPU_ACCESS_FIELD, flag)) ret |= map[EResourceUsageFlag::CPU_ACCESS_FIELD];
    if(HAS_FLAG(EResourceUsageFlag::CPU_ACCESS_DYNAMIC, flag)) ret |= map[EResourceUsageFlag::CPU_ACCESS_DYNAMIC];

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

    if(HAS_FLAG(EDescriptorHeapFlags::None, descriptorHeapFlag))
      ret |= map[EDescriptorHeapFlags::None];

    if(HAS_FLAG(EDescriptorHeapFlags::ShaderVisable, descriptorHeapFlag))
      ret |= map[EDescriptorHeapFlags::ShaderVisable];

    return ret;
  }
}
