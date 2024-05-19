#pragma once

namespace wkr::render
{
  struct FColor32
  {
    FColor32() : m_r(0), m_g(0), m_b(0), m_a(0) {}
    FColor32(
        u8 r,
        u8 g,
        u8 b,
        u8 a)
      : m_r(r),
        m_g(g),
        m_b(b),
        m_a(a) {}

    u8 m_r;
    u8 m_g;
    u8 m_b;
    u8 m_a;
  };

  struct FSample
  {
    u32 count;
    u32 quality;

    FSample()
    {
      count = 1;
      quality = 0;
    }

    FSample(u32 count, u32 quality)
    {
      this->count = count;
      this->quality = quality;
    }
  };

  struct FLuid
  {
    u64 lowPart;
    i64 highPart;
  };
}
