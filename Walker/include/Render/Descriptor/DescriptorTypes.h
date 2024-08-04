#pragma once

namespace wkr::render
{
  enum class EDescriptorHeapFlags
  {
    None = 0,
    ShaderVisable = 0x1,
  };

  enum class EDescriptorHeapType
  {
    CBV_SRV_UAV = 0,
    Sampler,
    RTV,
    DSV,
    NumTypes,
  };

}
