#pragma once

#include <Render/Resource/Resource.h>

namespace wkr
{
  class UDisplay
  {
  public:
    enum class ScanlineOrder
    {
      Unspecified         = 0,
      Progressive         = 1,
      UpperFieldFirst     = 2,
      LowerFieldFirst     = 3
    };

    enum class Scaling
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
      using Format = render::rsc::IResource::Format;

      uint32_t      m_width;
      uint32_t      m_height;
      FRational      m_refreshRate;
      Format        m_format;
      ScanlineOrder m_scanlineOrdering;
      Scaling       m_scaling;
    };
  };
}
