#include "Graphics/Resource/UTexture2D.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

UTexture2D::UTexture2D(const FTexture2DDesc& desc) {
  auto& factory = UGraphicsAPI::GetAbstractFactory();

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
              .Alignment = desc.Alignment,
              .Width = desc.Width,
              .Height = desc.Height,
              .DepthOrArraySize = desc.ArraySize,
              .MipLevels = desc.MipLevels,
              .Sample = desc.Sample,
              .Format = desc.ResourceFormat,
              .Flag = desc.ResourceFlag,
              .Layout = desc.ResourceLayout,
              .Dimension = EResourceDimension::kTexture2D,
          },
      .InitialState = desc.InitialState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = rhi::IResourceHandle(factory.GetResource(resourceDesc));
}

UTexture2D::UTexture2D(rhi::IResourceHandle resourceHandle) {
  WKR_CORE_ERROR_COND(resourceHandle->GetResourceDesc().Dimension !=
                          EResourceDimension::kTexture2D,
                      "Not Match Dimension");

  m_Resource = std::move(resourceHandle);
}

FTexture2DDesc UTexture2D::GetDesc() {
  FResource resourceDesc = m_Resource->GetResourceDesc();
  FHeapProperties heapProp = m_Resource->GetHeapProperties();

  FTexture2DDesc retDesc = {
      .HeapType = heapProp.Type,
      .ResourceFormat = resourceDesc.Format,
      .Width = resourceDesc.Width,
      .Height = resourceDesc.Height,
      .Alignment = resourceDesc.Alignment,
      .MipLevels = resourceDesc.MipLevels,
      .ResourceFlag = resourceDesc.Flag,
      .ResourceLayout = resourceDesc.Layout,
      .InitialState = {},
      .ClearValue = {},
  };

  return retDesc;
}

b64 UTexture2D::HasMSAA() {
  FResource resource = m_Resource->GetResourceDesc();
  return resource.Sample.Count != 1 && resource.Sample.Quality != 0;
}

b64 UTexture2D::IsArray() {
  FResource resource = m_Resource->GetResourceDesc();
  return resource.DepthOrArraySize > 1;
}

}  // namespace wkr::graphics
