#include <Platforms/DirectX12/DX12Renderer.h>
#include <Render/RendererAPI.h>

namespace wkr::render
{
  Ref<Renderer> Renderer::Create(Window* window)
  {
    switch (RendererAPI::GetAPI())
    {
      case RendererAPI::APIType::None:
        //TODO(utku): log
        return NULL;
        break;
      case RendererAPI::APIType::DirectX12:
        return CreateRef<DX12Renderer>(window);
        break;
      default:
        //TODO(utku): log
        return NULL;
        break;
    }
  }
}
