#ifndef DALI_ADAPTOR_ATSPI_ACTION_H
#define DALI_ADAPTOR_ATSPI_ACTION_H

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
 */

// EXTERNAL INCLUDES
#include <string>

// INTERNAL INCLUDES
#include <dali/devel-api/atspi-interfaces/accessible.h>

namespace Dali::Accessibility
{
/**
 * @brief Interface enabling to perform provided actions.
 */
class DALI_ADAPTOR_API Action : public virtual Accessible
{
public:
  /**
   * @brief Gets name of action with given index.
   *
   * @param[in] index The index of action
   *
   * @return The string with name of action
   */
  virtual std::string GetActionName(size_t index) = 0;

  /**
   * @brief Gets translated name of action with given index.
   *
   * @param[in] index The index of action
   *
   * @return The string with name of action translated according to current translation domain
   *
   * @note The translation is not supported in this version
   */
  virtual std::string GetLocalizedActionName(size_t index) = 0;

  /**
   * @brief Gets description of action with given index.
   *
   * @param[in] index The index of action
   *
   * @return The string with description of action
   */
  virtual std::string GetActionDescription(size_t index) = 0;

  /**
   * @brief Gets key code binded to action with given index.
   *
   * @param[in] index The index of action
   *
   * @return The string with key name
   */
  virtual std::string GetActionKeyBinding(size_t index) = 0;

  /**
   * @brief Gets number of provided actions.
   *
   * @return The number of actions
   */
  virtual size_t GetActionCount() = 0;

  /**
   * @brief Performs an action with given index.
   *
   * @param index The index of action
   *
   * @return true on success, false otherwise
   */
  virtual bool DoAction(size_t index) = 0;

  /**
   * @brief Performs an action with given name.
   *
   * @param name The name of action
   *
   * @return true on success, false otherwise
   */
  virtual bool DoAction(const std::string& name) = 0;
};

} // namespace Dali::Accessibility

#endif // DALI_ADAPTOR_ATSPI_ACTION_H
