#pragma once

#include "Graphics/Core/UGraphics.h"
#include "Graphics/Core/IAdapter.h"
#include "Graphics/Core/IDevice.h"
#include "Graphics/Core/IFence.h"
#include "Graphics/Core/IPipelineState.h"
#include "Graphics/Core/IRootSignature.h"

#include "Graphics/Command/ICommandAllocator.h"
#include "Graphics/Command/ICommandList.h"
#include "Graphics/Command/ICommandQueue.h"

#include "Graphics/Descriptor/ADescriptorHeap.h"
#include "Graphics/Descriptor/IDescriptorTable.h"

#include "Graphics/Resource/IHeap.h"
#include "Graphics/Resource/IResource.h"
#include "Graphics/Resource/UBuffer.h"
#include "Graphics/Resource/UTexture2D.h"

#include "Graphics/ResourceView/IResourceView.h"
#include "Graphics/ResourceView/AVertexBufferView.h"
#include "Graphics/ResourceView/ARenderTargetView.h"

#include "Graphics/ResourceBarrier/ITransitionBarrier.h"
#include "Graphics/ResourceBarrier/IAliasingBarrier.h"
#include "Graphics/ResourceBarrier/IUAVBarrier.h"

#include "Graphics/Shader/IShader.h"
#include "Graphics/Shader/IVertexShader.h"
