#pragma once

namespace wkr::render
{
  enum class CommandListType {
    Direct = 0,
    Bundle = 1,
    Compute = 2,
    Copy = 3,
    VideoDecode = 4,
    VideoProcess = 5,
    VideoEncode,
    None
  };

  class CommandList
  {
  public:
    virtual void* GetNativeHandle();
  };
}
