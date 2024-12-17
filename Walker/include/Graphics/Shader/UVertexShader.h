#pragma once

#include "Graphics/RHI/Shader/IShader.h"

namespace wkr::graphics {

struct WALKER_API FVertexShaderDesc{

};

class WALKER_API UVertexShader{


private:
  rhi::IShaderHandle m_Shader;
};

}  // namespace wkr::graphics
