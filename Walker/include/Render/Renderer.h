#pragma once

#include "Core/Factory.h"
#include <Core/Window.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    virtual void Render() = 0;
    virtual void SwapChain() = 0;
  };

  class RendererFactory : Factory<Renderer, Window*>
  {
    Renderer*        CreateFactoryRaw  (Window* window);
    Ref<Renderer>    CreateFactoryRef  (Window* window);
    Scope<Renderer>  CreateFactoryScope(Window* window);
  };
}
