#pragma once

namespace wkr::render
{
  struct FShaderDesc
  {
    //EShaderType type;
    std::string sourceCode;
  };

  class IShader
  {
  public:
    virtual ~IShader() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;
  };

  using IShaderHandle = mem::TRef<IShader>;
}
