#pragma once

#include "Graphics/RHI/Resource/Barrier/IResourceBarrier.h"
#include "Graphics/RHI/Resource/IResource.h"

namespace wkr::graphics {

struct FUAVBarrierDesc {
  rhi::IResourceHandle Resource;
};

class UUAVBarrier {
 public:
  UUAVBarrier(FUAVBarrierDesc& desc);

 private:
  rhi::IResourceBarrierHandle m_ResourceBarrier;
};

}  // namespace wkr::graphics
