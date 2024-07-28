#pragma once

namespace wkr::render
{
  enum class ERootSignatureType
  {
    DescriptorTable = 0,
    Constants,
    CBV,
    SRV,
    UAV
  };

  enum class ERootSignatureVisibilty
  {
    All             = 0,
    Vertex          = 1,
    Hull            = 2,
    Domain          = 3,
    Geometry        = 4,
    Pixel           = 5,
    Amplification   = 6,
    Mesh            = 7,
  };

  enum class ERootSignatureFlag
  {
    None                                = 0,
    AllowInputAssemblerInputLayout      = 0x1,
    DenyVertexShaderRootAccess          = 0x2,
    DenyHullShaderRootAccess            = 0x4,
    DenyDomainShaderRootAccess          = 0x8,
    DenyGeometryShaderRootAccess        = 0x10,
    DenyPixelShaderRootAccess           = 0x20,
    AllowStreamOutput                   = 0x40,
  };

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
