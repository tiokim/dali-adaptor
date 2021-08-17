#ifndef DALI_INTERNAL_PICTURE_FACTORY_H
#define DALI_INTERNAL_PICTURE_FACTORY_H

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

// EXTERNAL INCLUDES
#include <dali/devel-api/adaptor-framework/canvas-renderer-picture.h>

namespace Dali
{
namespace Internal
{
namespace Adaptor
{
namespace PictureFactory
{
/**
 * @brief Creates new instance of Picture implementation
 * @return pointer to Picture implementation instance
 */
Dali::Internal::Adaptor::Picture* New();

} // namespace PictureFactory

} // namespace Adaptor

} // namespace Internal

} // namespace Dali

#endif // DALI_INTERNAL_PICTURE_FACTORY_H