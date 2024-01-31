#pragma once

namespace wkr
{
  class Graphics
  {
  public:
    virtual void Render() = 0;
    virtual void SwapChain() = 0;
  };
}
