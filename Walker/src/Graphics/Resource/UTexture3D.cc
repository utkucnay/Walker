#include "Graphics/Resource/UTexture3D.h"
#include "Graphics/Core/UGraphicsAPI.h"
#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics {

UTexture3D::UTexture3D(const FTexture3DDesc& desc) {
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
              .DepthOrArraySize = desc.DepthSize,
              .MipLevels = desc.MipLevels,
              .Sample =
                  {
                      .Count = 1,
                      .Quality = 0,
                  },
              .Format = desc.ResourceFormat,
              .Flag = desc.ResourceFlag,
              .Layout = desc.ResourceLayout,
              .Dimension = EResourceDimension::kTexture3D,
          },
      .InitialState = desc.InitialState,
      .ClearValue = desc.ClearValue,
  };

  m_Resource = rhi::IResourceHandle(factory.GetResource(resourceDesc));
}

UTexture3D::UTexture3D(rhi::IResourceHandle resource) {
  WKR_CORE_ERROR_COND(
      resource->GetResourceDesc().Dimension != EResourceDimension::kTexture3D,
      "Not Match Dimension");

  m_Resource = std::move(resource);
}

FTexture3DDesc UTexture3D::GetDesc() {
  FResource resourceDesc = m_Resource->GetResourceDesc();
  FHeapProperties heapProp = m_Resource->GetHeapProperties();

  FTexture3DDesc retDesc = {
      .HeapType = heapProp.Type,
      .ResourceFormat = resourceDesc.Format,
      .Width = resourceDesc.Width,
      .Height = resourceDesc.Height,
      .Alignment = resourceDesc.Alignment,
      .MipLevels = resourceDesc.MipLevels,
      .DepthSize = resourceDesc.DepthOrArraySize,
      .ResourceFlag = resourceDesc.Flag,
      .ResourceLayout = resourceDesc.Layout,
      .InitialState = {},
      .ClearValue = {},
  };

  return retDesc;
}

}  // namespace wkr::graphics
