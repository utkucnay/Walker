#pragma once

namespace wkr::render
{
  class IRootParameter
  {
    public:
      enum class Type
      {
        DescriptorTable = 0,
        Constants,
        CBV,
        SRV,
        UAV
      };

      enum class Visibilty
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
  };

  class IRootSignature
  {
  public:
    enum class Flag
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

  public:
    virtual ~IRootSignature() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;
  };

  class RootSignatureBuilder : IBuilder<IRootSignature>
  {
  public:
    //RootSignatureBuilder& SetRootParameters(
        //std::vector<mem::Scope<IRootParameter>> rootParameters);
    //SetSampler

  public:
    [[nodiscard]] IRootSignature* BuildRaw() override final;
    [[nodiscard]] mem::Ref<IRootSignature> BuildRef() override final;
    [[nodiscard]] mem::Scope<IRootSignature> BuildScope() override final;
  };
}
