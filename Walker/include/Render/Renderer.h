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

  class RendererFactory : Factory<Renderer, mem::Ref<Window>>
  {
    Renderer*             CreateFactoryRaw  (mem::Ref<Window> window);
    mem::Ref<Renderer>    CreateFactoryRef  (mem::Ref<Window> window);
    mem::Scope<Renderer>  CreateFactoryScope(mem::Ref<Window> window);
  };
}
