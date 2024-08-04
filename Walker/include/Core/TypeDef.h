#pragma once

#include <cstdint>

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using b8  = u8;
using b16 = u16;
using b32 = u32;
using b64 = u64;

using f32 = float;
using f64 = double;

struct NativeObject
{
  union
  {
    u64   adr;
    void* ptr;
  };

  NativeObject(u64 i) : adr(i) {}
  NativeObject(void* p) : ptr(p) { }

  template<typename T> operator T* () const { return static_cast<T*>(ptr); }
};

using CPUMemoryAddress = u64;
using GPUMemoryAddress = u64;
