#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

struct WALKER_API FBufferDesc {
  EHeapType HeapType = EHeapType::kDefault;
  u64 BufferSize = 0;
  EResourceStateF InitState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
  EResourceF ResourceFlag = EResourceF::kNone;
};

class WALKER_API UBuffer {
 public:
  UBuffer() : m_Resource(nullptr) {}

  explicit UBuffer(const FBufferDesc& desc);
  UBuffer(rhi::IResourceHandle resource);

 public:
  FBufferDesc GetDesc() const;

  rhi::IResourceHandle GetResource() { return m_Resource; }

 private:
  rhi::IResourceHandle m_Resource = {};
};

}  // namespace wkr::graphics
