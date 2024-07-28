#pragma once

#include <Render/Resource/Resource.h>

namespace wkr
{
  enum class EScanlineOrder
  {
    Unspecified         = 0,
    Progressive         = 1,
    UpperFieldFirst     = 2,
    LowerFieldFirst     = 3
  };

  enum class EScaling
  {
    Unspecified  = 0,
    Centered     = 1,
    Stretched    = 2
  };

  struct FRational
  {
    uint32_t m_numerator;
    uint32_t m_denominator;
  };

  struct FModeDesc
  {
    uint32_t      m_width;
    uint32_t      m_height;
    FRational      m_refreshRate;
    render::rsc::EResourceFormat m_format;
    EScanlineOrder m_scanlineOrdering;
    EScaling       m_scaling;
  };

  class UDisplay
  {
  };
}
