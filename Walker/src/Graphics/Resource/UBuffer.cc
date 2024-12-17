#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Core/UGraphicsAPI.h"

namespace wkr::graphics {

UBuffer::UBuffer(const FBufferDesc& desc) {
  auto resourceFactory = UGraphicsAPI::GetAbstractFactory().GetIResource();

  rhi::FResourceDesc resourceDesc = {
      .DescType = EResourceDescType::kCommitted,
      .HeapProp =
          {
              .Type = desc.HeapType,
              .MemoryPool = EMemoryPool::kUnknown,
              .CpuPageProperty = ECPUPageProperty::kUnknown,
          },
      .HeapFlag = EHeapF::kNone,
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
              .Layout = EResourceLayout::kRowMajor,
              .Dimension = EResourceDimension::kBuffer,
          },
      .InitialState = desc.InitState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = resourceFactory->Create(resourceDesc);
}

UBuffer::UBuffer(rhi::IResourceHandle resource) {
  FResource resourceDesc = resource->GetDesc();
  WKR_CORE_ERROR_COND(
      resourceDesc.Dimension != EResourceDimension::kBuffer,
      "Resource isn't a Buffer");

  m_Resource = std::move(resource);
}

UBuffer::~UBuffer() {}

FBufferDesc UBuffer::GetDesc() const {
  FResource resourceDesc = m_Resource->GetDesc();

  //TODO(utku): Added Heap
  FBufferDesc bufferDesc = {};

  return bufferDesc;
}

}  // namespace wkr::graphics
