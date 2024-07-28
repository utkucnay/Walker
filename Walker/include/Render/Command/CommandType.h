#pragma once

namespace wkr::render
{
  enum class ECommandType
  {
    Direct        = 0,
    Bundle        = 1,
    Compute       = 2,
    Copy          = 3,
    VideoDecode   = 4,
    VideoProcess  = 5,
    VideoEncode   = 6,
    None          = 7
  };

  enum class ECommandQueueFlags
  {
    None              = 0,
    DisableGPUTimeout = 0x1
  };

  enum class ECommandQueuePriority
  {
    Normal   = 0,
    High     = 100,
    Realtime = 10000
  };
}
