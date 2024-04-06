#pragma once

namespace wkr::render::rsc
{
  class Heap
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

    enum class Alignment : uint64_t
    {
      Default = 64 KB,
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
    virtual ~Heap() {}

  public:
    virtual void* GetNativeHandle() = 0;

    virtual uint64_t GetSize() = 0;
    virtual Heap::Type GetType() = 0;
    virtual Heap::CPUPageProperty GetCPUPageProperty() = 0;
    virtual Heap::MemoryPool GetMemoryPool() = 0;
    virtual uint64_t GetAlignment() = 0;
    virtual Heap::Flag GetFlag() = 0;
  };

  class HeapBuilder : Builder<Heap>
  {
  public:
    HeapBuilder& SetSize(uint64_t size);
    HeapBuilder& SetType(Heap::Type type);
    HeapBuilder& SetCPUPageProperty(Heap::CPUPageProperty cpuPageProperty);
    HeapBuilder& SetMemoryPool(Heap::MemoryPool memoryPool);
    HeapBuilder& SetAlignment(uint64_t alignment);
    HeapBuilder& SetFlag(Heap::Flag flag);

  public:
    Heap* BuildRaw() override;
    mem::Ref<Heap> BuildRef() override;
    mem::Scope<Heap> BuildScope() override;

  public:
    uint64_t m_size;
    Heap::Type m_type;
    Heap::CPUPageProperty m_cpuPageProperty;
    Heap::MemoryPool m_memoryPool;
    uint64_t m_alignment;
    Heap::Flag m_flag;
  };
}
