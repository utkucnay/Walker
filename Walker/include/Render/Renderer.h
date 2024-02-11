#pragma once

#include <Core/Window.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    virtual void Render() = 0;
    virtual void SwapChain() = 0;

  public:
    static Ref<Renderer> Create(Window* window);
  };
}
