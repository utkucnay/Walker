#include "Graphics/Core/GraphicsType.h"
#include "Graphics/RHI/Command/CommandType.h"
#include "Graphics/RHI/Descriptor/DescriptorType.h"
#include "Graphics/RHI/Resource/Barrier/ResourceBarrierType.h"
#include "Graphics/RHI/Resource/ResourceType.h"

namespace wkr::graphics {

WALKER_ENUM_CLASS_BITWISE_DEFINATION(EResourceStateF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(EResourceF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(EResourceUsageF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(ERootSignatureF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(EHeapF)

namespace rhi {

WALKER_ENUM_CLASS_BITWISE_DEFINATION(EFenceF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(ESwapChainF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(ECommandQueueF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(EDescriptorHeapF)
WALKER_ENUM_CLASS_BITWISE_DEFINATION(EResourceBarrierF);

}  // namespace rhi

}  // namespace wkr::graphics
