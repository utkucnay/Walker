#pragma once

#include "Graphics/RHI/Core/IRHIAbstractFactory.h"

namespace wkr::graphics {

class UGraphicsAPI {
 public:
  enum class EType {
    None = 0,
    DirectX12 = 1,
  };

 public:
  static void Init(EType apiType);

  static inline EType GetAPIType() { return s_Api; }

  static inline void Destroy() { s_abstractFactory.Release(); }

  static rhi::IRHIAbstractFactory& GetAbstractFactory() {
    return s_abstractFactory.Get();
  }

  static void ChangeAPI(EType type);

 private:
  static inline EType s_Api;
  static inline mem::TScope<rhi::IRHIAbstractFactory> s_abstractFactory;
};

}  // namespace wkr::graphics
