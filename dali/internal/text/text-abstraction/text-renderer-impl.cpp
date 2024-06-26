/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd.
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

// CLASS  HEADER
#include <dali/internal/text/text-abstraction/text-renderer-impl.h>

// EXTERNAL INCLUDES
#include <dali/devel-api/common/singleton-service.h>

// INTERNAL INCLUDES
#include <dali/internal/text/text-abstraction/cairo-renderer.h>

namespace Dali
{
namespace TextAbstraction
{
namespace Internal
{
TextRenderer::TextRenderer()
{
}

TextRenderer::~TextRenderer()
{
}

TextAbstraction::TextRenderer TextRenderer::Get()
{
  TextAbstraction::TextRenderer shapingHandle;

  SingletonService service(SingletonService::Get());
  if(service)
  {
    // Check whether the singleton is already created
    Dali::BaseHandle handle = service.GetSingleton(typeid(TextAbstraction::TextRenderer));
    if(handle)
    {
      // If so, downcast the handle
      TextRenderer* impl = dynamic_cast<Internal::TextRenderer*>(handle.GetObjectPtr());
      shapingHandle      = TextAbstraction::TextRenderer(impl);
    }
    else // create and register the object
    {
      shapingHandle = TextAbstraction::TextRenderer(new TextRenderer);
      service.Register(typeid(shapingHandle), shapingHandle);
    }
  }

  return shapingHandle;
}

Devel::PixelBuffer TextRenderer::Render(const TextAbstraction::TextRenderer::Parameters& parameters)
{
  Dali::Pixel::Format      pixelFormat = parameters.pixelFormat == Dali::TextAbstraction::TextRenderer::Parameters::A8 ? Dali::Pixel::A8 : Dali::Pixel::RGBA8888;
  Dali::Devel::PixelBuffer pixelBuffer = Dali::Devel::PixelBuffer::New(parameters.width,
                                                                       parameters.height,
                                                                       pixelFormat);
  return pixelBuffer;

  // This function allows you to render text using Cairo
  // NOTE : Due to cairo being deprecated, this section is currently inactive.
  // return RenderTextCairo(parameters);
}

} // namespace Internal

} // namespace TextAbstraction

} // namespace Dali
