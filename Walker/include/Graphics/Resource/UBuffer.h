#pragma once

#include "Graphics/RHI/Resource/IResource.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics::rsc {

struct WALKER_API FBufferDesc {
  EHeapType HeapType = EHeapType::kDefault;
  u64 BufferSize = 0;
  EResourceStateF InitState = EResourceStateF::kCommon;
  FClearValue* ClearValue = nullptr;
  EResourceF ResourceFlag = EResourceF::kNone;
};

class WALKER_API UBuffer {
 public:
  UBuffer(const FBufferDesc& buffersDesc);
  ~UBuffer();

 public:
  FBufferDesc GetDesc() const;

 private:
  rhi::IResourceHandle m_resource;
};

}  // namespace wkr::graphics::rsc
