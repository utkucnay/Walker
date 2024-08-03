#pragma once

namespace wkr::render
{
  struct FRootSignatureDesc
  {

  };

  class IRootSignature
  {
  public:
    virtual ~IRootSignature() {}

  public:
    virtual NativeObject GetNativeObject() = 0;
  };
}
