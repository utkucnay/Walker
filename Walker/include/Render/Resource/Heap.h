#pragma once

namespace wkr::render::rsc
{
  enum class EHeapType
  {
    Default     = 1,
    Upload      = 2,
    Readback    = 3,
    Custom      = 4,
    GPUUpload   = 5,
  };

  enum class ECPUPageProperty
  {
    Unknown       = 0,
    NotAvailable  = 1,
    WriteCombine  = 2,
    WriteBack     = 3,
  };

  enum class EMemoryPool
  {
    Unknown = 0,
    L0      = 1,
    L1      = 2,
  };

  enum class EAlignment : u64
  {
    Default     = 64 KB,
    DefaultMSAA = 4 MB,
  };

  enum class EHeapFlag
  {
    None = 0,
    Shared = 0x1,
    DenyBuffers = 0x4,
    AllowDisplay = 0x8,
    SharedCrossAdapter = 0x20,
    DenyRT_DS_Textures = 0x40,
    DenyNonRT_DS_Textures = 0x80,
    HardwareProtected = 0x100,
    AllowWriteWatch = 0x200,
    AllowShaderAtomics = 0x400,
    CreateNotResident = 0x800,
    CreateNotZeroed = 0x1000,
    ToolsUseManualWriteTracking,
    AllowAllBuffersAndTextures = 0,
    AllowOnlyBuffers = 0xc0,
    AllowOnlyNonRT_DS_Textures = 0x44,
    AllowOnlyRT_DS_Textures = 0x84
  };

  struct FHeapDesc
  {
    u64 m_size;
    u64 m_alignment;
    EHeapType m_type;
    EHeapFlag m_flag;
    EMemoryPool       m_memoryPool;
    ECPUPageProperty  m_cpuPageProperty;
  };

  class IHeap
  {
  public:
    virtual ~IHeap() = default;

  public:
    virtual NativeObject GetNativeObject() = 0;

    virtual u64 GetSize()       = 0;
    virtual u64 GetAlignment()  = 0;
    virtual EHeapType GetType() = 0;
    virtual EHeapFlag GetFlag() = 0;
    virtual EMemoryPool       GetMemoryPool()       = 0;
    virtual ECPUPageProperty  GetCPUPageProperty()  = 0;
  };
}
