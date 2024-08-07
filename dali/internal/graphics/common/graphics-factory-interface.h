#ifndef DALI_INTERNAL_BASE_GRAPHICS_FACTORY_INTERFACE_H
#define DALI_INTERNAL_BASE_GRAPHICS_FACTORY_INTERFACE_H

/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// INTERNAL INCLUDES
#include <dali/internal/graphics/common/graphics-interface.h>

namespace Dali
{
namespace Internal::Adaptor
{
/**
 * Factory interface for creating Graphics Factory implementation
 */
class GraphicsFactoryInterface
{
public:
  /**
   * Create a Graphics interface implementation
   * @return An implementation of the Graphics interface
   */
  virtual Graphics::GraphicsInterface& Create() = 0;

  /**
   * Destroy the Graphics Factory implementation
   */
  virtual void Destroy() = 0;

  /**
   * Virtual destructor - no deletion through this interface
   */
  virtual ~GraphicsFactoryInterface() = default;
};

} // namespace Internal::Adaptor
} // namespace Dali

#endif // DALI_INTERNAL_BASE_GRAPHICS_FACTORY_INTERFACE_H
