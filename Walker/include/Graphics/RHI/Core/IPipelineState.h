#pragma once

namespace wkr::graphics::rhi {

struct WALKER_API FPipelineStateDesc {};

class WALKER_API IPipelineState {
 public:
  virtual ~IPipelineState() = default;

 public:
  virtual NativeObject GetNativeObject() const = 0;
};

using IPipelineStateHandle = mem::TRef<IPipelineState>;

}  // namespace wkr::graphics::rhi
