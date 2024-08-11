#include <Render/Core/RendererAPI.h>
#include <Render/Resource/Texture2D.h>

namespace wkr::render
{
  UTexture2D::UTexture2D(FTexture2DDesc& desc)
  {
    auto resourceFactory = URendererAPI::GetAbstractFactory().GetIResource();

    FResourceDesc resourceDesc = {};

    resourceDesc.descType = EResourceDescType::Committed;
    resourceDesc.heapDesc.m_type = desc.heapType;
    resourceDesc.heapDesc.m_flag = EHeapF::None;
    resourceDesc.heapDesc.m_memoryPool = EMemoryPool::Unknown;
    resourceDesc.heapDesc.m_cpuPageProperty = ECPUPageProperty::Unknown;

    resourceDesc.initialState = desc.initialState;

    resourceDesc.resource.dimension = EResourceDimension::Texture2D;
    resourceDesc.resource.width = desc.width;
    resourceDesc.resource.height = desc.height;
    resourceDesc.resource.alignment = 0;
    resourceDesc.resource.depthOrArraySize = 1;
    resourceDesc.resource.mipLevels = 1;
    resourceDesc.resource.format = desc.resourceFormat;
    resourceDesc.resource.sample.count = desc.sample.count;
    resourceDesc.resource.sample.quality = desc.sample.quality;
    resourceDesc.resource.layout = desc.resourceLayout;
    resourceDesc.resource.flag = desc.resourceFlag;

    resourceDesc.clearValue = desc.clearValue;

    m_resource = resourceFactory->Create(resourceDesc);
  }
}
