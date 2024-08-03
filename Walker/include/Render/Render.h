#pragma once

#include <Render/Core/Renderer.h>
#include <Render/Core/Adapter.h>
#include <Render/Core/Device.h>
#include <Render/Core/Fence.h>
#include <Render/Core/PipelineState.h>
#include <Render/Core/RootSignature.h>

#include <Render/Command/CommandAllocator.h>
#include <Render/Command/CommandList.h>
#include <Render/Command/CommandQueue.h>

#include <Render/Descriptor/DescriptorHeap.h>
#include <Render/Descriptor/DescriptorTable.h>

#include <Render/Resource/Heap.h>
#include <Render/Resource/Texture.h>
#include <Render/Resource/Resource.h>
#include <Render/Resource/Buffers.h>
#include <Render/Resource/Texture1D.h>
#include <Render/Resource/Texture2D.h>
#include <Render/Resource/Texture3D.h>
#include <Render/Resource/Texture1DArray.h>
#include <Render/Resource/Texture2DArray.h>

#include <Render/ResourceView/IndexBufferView.h>
#include <Render/ResourceView/VertexBufferView.h>
#include <Render/ResourceView/ConstantBufferView.h>
#include <Render/ResourceView/ShaderResourceView.h>
#include <Render/ResourceView/UnorderedAccessView.h>
#include <Render/ResourceView/RenderTargetView.h>
#include <Render/ResourceView/DepthStencilView.h>
#include <Render/ResourceView/Samplers.h>

#include <Render/ResourceBarrier/TransitionBarrier.h>
#include <Render/ResourceBarrier/AliasingBarrier.h>
#include <Render/ResourceBarrier/UAVBarrier.h>

#include <Render/Shader/Shader.h>
#include <Render/Shader/VertexShader.h>
