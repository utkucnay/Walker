#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Core/UGraphicsAPI.h"

namespace wkr::graphics {

UBuffer::UBuffer(const FBufferDesc& desc) {
  auto resourceFactory = UGraphicsAPI::GetAbstractFactory().GetIResource();

  rhi::FResourceDesc resourceDesc = {
      .DescType = EResourceDescType::kCommitted,
      .HeapDesc =
          {
              .Type = desc.HeapType,
              .MemoryPool = EMemoryPool::kUnknown,
              .CpuPageProperty = ECPUPageProperty::kUnknown,
              .Flag = EHeapF::kNone,
          },
      .Resource =
          {
              .Alignment = 0,
              .Width = desc.BufferSize,
              .Height = 1,
              .DepthOrArraySize = 1,
              .MipLevels = 1,
              .Sample = {.Count = 1, .Quality = 0},
              .Format = EResourceFormat::kUNKNOWN,
              .Flag = desc.ResourceFlag,
              .Layout = EResourceLayout::kUnknown,
              .Dimension = EResourceDimension::kBuffer,
          },
      .InitialState = desc.InitState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = resourceFactory->Create(resourceDesc);
}

UBuffer::UBuffer(rhi::IResourceHandle resource) {
  rhi::FResourceDesc resourceDesc = resource->GetDesc();
  WKR_CORE_ERROR_COND(
      resourceDesc.Resource.Dimension != EResourceDimension::kBuffer,
      "Resource isn't a Buffer");

  m_Resource = resource;
}

UBuffer::~UBuffer() {}

FBufferDesc UBuffer::GetDesc() const {
  rhi::FResourceDesc resourceDesc = m_Resource->GetDesc();

  FBufferDesc bufferDesc = {.HeapType = resourceDesc.HeapDesc.Type,
                            .BufferSize = resourceDesc.Resource.Width,
                            .InitState = resourceDesc.InitialState,
                            .ClearValue = resourceDesc.ClearValue,
                            .ResourceFlag = resourceDesc.Resource.Flag};

  return bufferDesc;
}

}  // namespace wkr::graphics
