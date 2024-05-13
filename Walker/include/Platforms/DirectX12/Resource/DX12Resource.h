#pragma once

#define CREATE_RESOURCE(Builder, Resource, Device)                                  \
    D3D12_HEAP_PROPERTIES heapProperties{};                                         \
    D3D12_RESOURCE_DESC resourceDesc{};                                             \
                                                                                    \
    heapProperties.Type = static_cast<D3D12_HEAP_TYPE>(                             \
          Builder.m_heapBuilder.m_type);                                            \
    heapProperties.CPUPageProperty = static_cast<D3D12_CPU_PAGE_PROPERTY>(          \
        Builder.m_heapBuilder.m_cpuPageProperty);                                   \
    heapProperties.MemoryPoolPreference = static_cast<D3D12_MEMORY_POOL>(           \
        Builder.m_heapBuilder.m_memoryPool);                                        \
                                                                                    \
    resourceDesc.Dimension = static_cast<D3D12_RESOURCE_DIMENSION>(                 \
        Builder.GetDimension());                                                    \
    resourceDesc.Alignment = Builder.m_alignment;                                   \
    resourceDesc.Width = Builder.m_width;                                           \
    resourceDesc.Height = Builder.m_height;                                         \
    resourceDesc.DepthOrArraySize = Builder.m_depthOrArraySize;                     \
    resourceDesc.MipLevels = Builder.m_mipLevels;                                   \
    resourceDesc.Format = static_cast<DXGI_FORMAT>(Builder.m_format);               \
    resourceDesc.SampleDesc.Count = Builder.m_sample.count;                         \
    resourceDesc.SampleDesc.Quality = Builder.m_sample.quality;                     \
    resourceDesc.Layout = static_cast<D3D12_TEXTURE_LAYOUT>(Builder.m_layout);      \
    resourceDesc.Flags = static_cast<D3D12_RESOURCE_FLAGS>(Builder.m_flag);         \
                                                                                    \
    switch (Builder.m_type)                                                         \
    {                                                                               \
      case ResourceBuilderType::Committed:                                          \
        {                                                                           \
          Device->CreateCommittedResource(                                          \
              &heapProperties,                                                      \
              static_cast<D3D12_HEAP_FLAGS>(Builder.m_heapBuilder.m_flag),          \
              &resourceDesc,                                                        \
              static_cast<D3D12_RESOURCE_STATES>(Builder.m_state),                  \
              NULL,                                                                 \
              IID_PPV_ARGS(&Resource));                                             \
        } break;                                                                    \
      case ResourceBuilderType::Reserved:                                           \
        {                                                                           \
          Device->CreateReservedResource(                                           \
              &resourceDesc,                                                        \
              static_cast<D3D12_RESOURCE_STATES>(Builder.m_state),                  \
              NULL,                                                                 \
              IID_PPV_ARGS(&Resource));                                             \
        } break;                                                                    \
      case ResourceBuilderType::Placed:                                             \
        {                                                                           \
          Device->CreatePlacedResource(                                             \
              static_cast<ID3D12Heap*>(Builder.m_heap.Lock()->GetNativeHandle()),   \
              Builder.m_heapOffset,                                                 \
              &resourceDesc,                                                        \
              static_cast<D3D12_RESOURCE_STATES>(Builder.m_state),                  \
              NULL,                                                                 \
              IID_PPV_ARGS(&Resource));                                             \
        } break;                                                                    \
    }
