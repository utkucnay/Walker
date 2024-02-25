#pragma once

#include <Core/Factory.h>
#include <Core/Window.h>

namespace wkr::render
{
  class Renderer
  {
  public:
    virtual ~Renderer() = 0;

  public:
    virtual void Render() = 0;
    virtual void SwapChain() = 0;
  };

  class RendererFactory : Factory<Renderer, Window*>
  {
    Renderer*             CreateFactoryRaw  (Window* window);
    mem::Ref<Renderer>    CreateFactoryRef  (Window* window);
    mem::Scope<Renderer>  CreateFactoryScope(Window* window);
  };
}
