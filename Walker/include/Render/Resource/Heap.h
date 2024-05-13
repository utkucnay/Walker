#pragma once

namespace wkr::render::rsc
{
  class IHeap
  {
  public:
    enum class Type
    {
      Default     = 1,
      Upload      = 2,
      Readback    = 3,
      Custom      = 4,
      GPUUpload   = 5,
    };

    enum class CPUPageProperty
    {
      Unknown       = 0,
      NotAvailable  = 1,
      WriteCombine  = 2,
      WriteBack     = 3,
    };

    enum class MemoryPool
    {
      Unknown = 0,
      L0      = 1,
      L1      = 2,
    };

    enum class Alignment : u64
    {
      Default     = 64 KB,
      DefaultMSAA = 4 MB,
    };

    enum class Flag
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

  public:
    virtual ~IHeap() {}

  public:
    virtual NativeHandle GetNativeHandle() = 0;

    virtual u64 GetSize()       = 0;
    virtual u64 GetAlignment()  = 0;
    virtual IHeap::Type GetType() = 0;
    virtual IHeap::Flag GetFlag() = 0;
    virtual IHeap::MemoryPool       GetMemoryPool()       = 0;
    virtual IHeap::CPUPageProperty  GetCPUPageProperty()  = 0;
  };

  class HeapBuilder : IBuilder<IHeap>
  {
  public:
    HeapBuilder& SetSize(u64 size);
    HeapBuilder& SetAlignment(u64 alignment);
    HeapBuilder& SetType(IHeap::Type type);
    HeapBuilder& SetFlag(IHeap::Flag flag);
    HeapBuilder& SetMemoryPool(IHeap::MemoryPool memoryPool);
    HeapBuilder& SetCPUPageProperty(IHeap::CPUPageProperty cpuPageProperty);

  public:
    [[nodiscard]] IHeap*            BuildRaw()    override;
    [[nodiscard]] mem::Ref<IHeap>   BuildRef()    override;
    [[nodiscard]] mem::Scope<IHeap> BuildScope()  override;

  public:
    u64 m_size;
    u64 m_alignment;
    IHeap::Type m_type;
    IHeap::Flag m_flag;
    IHeap::MemoryPool       m_memoryPool;
    IHeap::CPUPageProperty  m_cpuPageProperty;
  };
}
