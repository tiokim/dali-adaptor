/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd.
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

// CLASS HEADER
#include <dali/internal/input/common/virtual-keyboard-impl.h>

// EXTERNAL INCLUDES
#include <X11/Xlib.h>
#include <Ecore_X.h>
#include <algorithm>

#include <dali/integration-api/debug.h>

// INTERNAL INCLUDES
#include <dali/integration-api/adaptor.h>
#include <dali/internal/system/common/locale-utils.h>
#include <dali/internal/input/ubuntu-x11/imf-manager-impl-x.h>


namespace Dali
{

namespace Internal
{

namespace Adaptor
{

namespace VirtualKeyboard
{

Dali::InputMethod::ButtonAction::Type gButtonActionFunction = Dali::InputMethod::ButtonAction::DEFAULT;

Ecore_IMF_Input_Panel_Return_Key_Type buttonActionMapping(Dali::InputMethod::ButtonAction::Type buttonAction )
{
  switch( buttonAction )
  {
    case InputMethod::ButtonAction::DEFAULT:     return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
    case InputMethod::ButtonAction::DONE:        return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DONE;
    case InputMethod::ButtonAction::GO:          return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_GO;
    case InputMethod::ButtonAction::JOIN:        return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_JOIN;
    case InputMethod::ButtonAction::LOGIN:       return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_LOGIN;
    case InputMethod::ButtonAction::NEXT:        return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_NEXT;
    case InputMethod::ButtonAction::PREVIOUS:    return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
    case InputMethod::ButtonAction::SEARCH:      return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_SEARCH;
    case InputMethod::ButtonAction::SEND:        return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_SEND;
    case InputMethod::ButtonAction::SIGNIN:      return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
    case InputMethod::ButtonAction::UNSPECIFIED: return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
    case InputMethod::ButtonAction::NONE:        return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
    default:                                     return ECORE_IMF_INPUT_PANEL_RETURN_KEY_TYPE_DEFAULT;
  }
}

void RotateTo(int angle)
{
  // Get focus window used by Keyboard and rotate it
  Display* display = XOpenDisplay(0);
  if (display)
  {
    ::Window focusWindow;
    int revert;
    // Get Focus window
    XGetInputFocus(display, &focusWindow, &revert);

    ecore_x_window_prop_property_set( focusWindow,
                                      ECORE_X_ATOM_E_ILLUME_ROTATE_WINDOW_ANGLE,
                                      ECORE_X_ATOM_CARDINAL, 32, &angle, 1 );
    XCloseDisplay(display);
  }
}

void SetReturnKeyType( const InputMethod::ButtonAction::Type type )
{
  Dali::ImfManager imfManager = ImfManager::Get(); // Create ImfManager instance (if required) when setting values
  Ecore_IMF_Context* imfContext = reinterpret_cast<Ecore_IMF_Context*>(ImfManager::GetImplementation( imfManager ).GetContext());

  if( imfContext )
  {
    gButtonActionFunction = type;
    ecore_imf_context_input_panel_return_key_type_set( imfContext, buttonActionMapping( type ) );
  }
}

Dali::InputMethod::ButtonAction::Type GetReturnKeyType()
{
  return gButtonActionFunction;
}

} // namespace VirtualKeyboard

} // namespace Adaptor

} // namespace Internal

} // namespace Dali
