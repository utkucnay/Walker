#include <Render/Core/RendererAPI.h>
#include <Render/Resource/Buffer.h>

namespace wkr::render
{
  UBuffer::UBuffer(FBufferDesc& desc)
  {
    auto resourceFactory = URendererAPI::GetAbstractFactory().GetIResource();

    FResourceDesc resourceDesc = {};

    resourceDesc.descType = EResourceDescType::Committed;
    resourceDesc.heapDesc.m_type = desc.heapType;
    resourceDesc.heapDesc.m_flag = EHeapF::None;
    resourceDesc.heapDesc.m_memoryPool = EMemoryPool::Unknown;
    resourceDesc.heapDesc.m_cpuPageProperty = ECPUPageProperty::Unknown;

    resourceDesc.initialState = desc.initState;

    resourceDesc.resource.dimension = EResourceDimension::Buffer;
    resourceDesc.resource.width = desc.bufferSize;
    resourceDesc.resource.height = 1;
    resourceDesc.resource.alignment = 0;
    resourceDesc.resource.depthOrArraySize = 1;
    resourceDesc.resource.mipLevels = 1;
    resourceDesc.resource.format = EResourceFormat::UNKNOWN;
    resourceDesc.resource.sample.count = 1;
    resourceDesc.resource.sample.quality = 0;
    resourceDesc.resource.layout = EResourceLayout::RowMajor;
    resourceDesc.resource.flag = desc.resourceFlag;

    resourceDesc.clearValue = desc.clearValue;

    m_resource = resourceFactory->Create(resourceDesc);
  }

  UBuffer::~UBuffer()
  {

  }

  FBufferDesc UBuffer::GetDesc() const
  {
    FBufferDesc ret;

    return ret;
  }
}
