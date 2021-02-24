#ifndef DALI_WEB_ENGINE_IMPL_H
#define DALI_WEB_ENGINE_IMPL_H

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
#include <dali/public-api/object/base-object.h>

// INTERNAL INCLUDES
#include <dali/devel-api/adaptor-framework/web-engine-plugin.h>
#include <dali/devel-api/adaptor-framework/web-engine.h>

namespace Dali
{
// forward declaration
class WebEngineBackForwardList;
class WebEngineContext;
class WebEngineCookieManager;
class WebEngineSettings;

namespace Internal
{
namespace Adaptor
{
class WebEngine;

typedef IntrusivePtr<WebEngine> WebEnginePtr;

/**
 * @brief WebEngine class is used for Web.
 */
class WebEngine : public Dali::BaseObject
{
public:
  /**
   * @brief Creates a new WebEngine handle
   *
   * @return WebEngine pointer
   */
  static WebEnginePtr New();

  /**
   * @copydoc Dali::WebEngine::Create()
   */
  void Create(int width, int height, const std::string& locale, const std::string& timezoneId);

  /**
   * @copydoc Dali::WebEngine::Create()
   */
  void Create(int width, int height, int argc, char** argv);

  /**
   * @copydoc Dali::WebEngine::Destroy()
   */
  void Destroy();

  /**
   * @copydoc Dali::WebEngine::GetNativeImageSource()
   */
  Dali::NativeImageInterfacePtr GetNativeImageSource();

  /**
   * @copydoc Dali::WebEngine::GetSettings()
   */
  Dali::WebEngineSettings& GetSettings() const;

  /**
   * @copydoc Dali::WebEngine::GetContext()
   */
  Dali::WebEngineContext& GetContext() const;

  /**
   * @copydoc Dali::WebEngine::GetCookieManager()
   */
  Dali::WebEngineCookieManager& GetCookieManager() const;

  /**
   * @copydoc Dali::WebEngine::GetBackForwardList()
   */
  Dali::WebEngineBackForwardList& GetBackForwardList() const;

  /**
   * @copydoc Dali::WebEngine::LoadUrl()
   */
  void LoadUrl(const std::string& url);

  /**
   * @copydoc Dali::WebEngine::GetTitle()
   */
  std::string GetTitle() const;

  /**
   * @copydoc Dali::WebEngine::GetFavicon()
   */
  Dali::PixelData GetFavicon() const;

  /**
   * @copydoc Dali::WebEngine::GetUrl()
   */
  const std::string& GetUrl();

  /**
   * @copydoc Dali::WebEngine::GetUserAgent()
   */
  const std::string& GetUserAgent() const;

  /**
   * @copydoc Dali::WebEngine::SetUserAgent()
   */
  void SetUserAgent(const std::string& userAgent);

  /**
   * @copydoc Dali::WebEngine::LoadHtmlString()
   */
  void LoadHtmlString(const std::string& htmlString);

  /**
   * @copydoc Dali::WebEngine::Reload()
   */
  void Reload();

  /**
   * @copydoc Dali::WebEngine::StopLoading()
   */
  void StopLoading();

  /**
   * @copydoc Dali::WebEngine::Suspend()
   */
  void Suspend();

  /**
   * @copydoc Dali::WebEngine::Resume()
   */
  void Resume();

  /**
   * @copydoc Dali::WebEngine::ScrollBy()
   */
  void ScrollBy(int deltaX, int deltaY);

  /**
   * @copydoc Dali::WebEngine::SetScrollPosition()
   */
  void SetScrollPosition(int x, int y);

  /**
   * @copydoc Dali::WebEngine::GetScrollPosition()
   */
  Dali::Vector2 GetScrollPosition() const;

  /**
   * @copydoc Dali::WebEngine::GetScrollSize()
   */
  Dali::Vector2 GetScrollSize() const;

  /**
   * @copydoc Dali::WebEngine::GetContentSize()
   */
  Dali::Vector2 GetContentSize() const;

  /**
	* @copydoc Dali::WebEngine::RegisterJavaScriptAlertCallback()
	*/
  void RegisterJavaScriptAlertCallback(Dali::WebEnginePlugin::JavaScriptAlertCallback callback);

  /**
   * @copydoc Dali::WebEngine::JavaScriptAlertReply()
   */
  void JavaScriptAlertReply();

  /**
   * @copydoc Dali::WebEngine::RegisterJavaScriptConfirmCallback()
   */
  void RegisterJavaScriptConfirmCallback(Dali::WebEnginePlugin::JavaScriptConfirmCallback callback);

  /**
   * @copydoc Dali::WebEngine::JavaScriptConfirmReply()
   */
  void JavaScriptConfirmReply(bool confirmed);

  /**
   * @copydoc Dali::WebEngine::RegisterJavaScriptPromptCallback()
   */
  void RegisterJavaScriptPromptCallback(Dali::WebEnginePlugin::JavaScriptPromptCallback callback);

  /**
   * @copydoc Dali::WebEngine::JavaScriptPromptReply()
   */
  void JavaScriptPromptReply(const std::string& result);

  /**
   * @copydoc Dali::WebEngine::CanGoForward()
   */
  bool CanGoForward();

  /**
   * @copydoc Dali::WebEngine::GoForward()
   */
  void GoForward();

  /**
   * @copydoc Dali::WebEngine::CanGoBack()
   */
  bool CanGoBack();

  /**
   * @copydoc Dali::WebEngine::GoBack()
   */
  void GoBack();

  /**
   * @copydoc Dali::WebEngine::EvaluateJavaScript()
   */
  void EvaluateJavaScript(const std::string& script, std::function<void(const std::string&)> resultHandler);

  /**
   * @copydoc Dali::WebEngine::AddJavaScriptMessageHandler()
   */
  void AddJavaScriptMessageHandler(const std::string& exposedObjectName, std::function<void(const std::string&)> handler);

  /**
   * @copydoc Dali::WebEngine::ClearAllTilesResources()
   */
  void ClearAllTilesResources();

  /**
   * @copydoc Dali::WebEngine::ClearHistory()
   */
  void ClearHistory();

  /**
   * @copydoc Dali::WebEngine::SetSize()
   */
  void SetSize(int width, int height);

  /**
   * @copydoc Dali::WebEngine::EnableMouseEvents()
   */
  void EnableMouseEvents(bool enabled);

  /**
   * @copydoc Dali::WebEngine::EnableKeyEvents()
   */
  void EnableKeyEvents(bool enabled);

  /**
   * @copydoc Dali::WebEngine::SetDocumentBackgroundColor()
   */
  void SetDocumentBackgroundColor(Dali::Vector4 color);

  /**
   * @copydoc Dali::WebEngine::ClearTilesWhenHidden()
   */
  void ClearTilesWhenHidden(bool cleared);

  /**
   * @copydoc Dali::WebEngine::SetTileCoverAreaMultiplier()
   */
  void SetTileCoverAreaMultiplier(float multiplier);

  /**
   * @copydoc Dali::WebEngine::EnableCursorByClient()
   */
  void EnableCursorByClient(bool enabled);

  /**
   * @copydoc Dali::WebEngine::GetSelectedText()
   */
  std::string GetSelectedText() const;

  /**
   * @copydoc Dali::WebEngine::SendTouchEvent()
   */
  bool SendTouchEvent(const Dali::TouchEvent& touch);

  /**
   * @copydoc Dali::WebEngine::SendKeyEvent()
   */
  bool SendKeyEvent(const Dali::KeyEvent& event);

  /**
   * @copydoc Dali::WebEngine::SetFocus()
   */
  void SetFocus(bool focused);

  /**
   * @copydoc Dali::WebEngine::UpdateDisplayArea()
   */
  void UpdateDisplayArea(Dali::Rect<int> displayArea);

  /**
   * @copydoc Dali::WebEngine::EnableVideoHole()
   */
  void EnableVideoHole(bool enabled);

  /**
   * @copydoc Dali::WebEngine::SendHoverEvent()
   */
  bool SendHoverEvent(const Dali::HoverEvent& event);

  /**
   * @copydoc Dali::WebEngine::SendWheelEvent()
   */
  bool SendWheelEvent(const Dali::WheelEvent& event);

  /**
   * @copydoc Dali::WebEngine::PageLoadStartedSignal()
   */
  Dali::WebEnginePlugin::WebEnginePageLoadSignalType& PageLoadStartedSignal();

  /**
   * @copydoc Dali::WebEngine::PageLoadProgressSignal()
   */
  Dali::WebEnginePlugin::WebEnginePageLoadSignalType& PageLoadInProgressSignal();

  /**
   * @copydoc Dali::WebEngine::PageLoadFinishedSignal()
   */
  Dali::WebEnginePlugin::WebEnginePageLoadSignalType& PageLoadFinishedSignal();

  /**
   * @copydoc Dali::WebEngine::PageLoadErrorSignal()
   */
  Dali::WebEnginePlugin::WebEnginePageLoadErrorSignalType& PageLoadErrorSignal();

  /**
   * @copydoc Dali::WebEngine::ScrollEdgeReachedSignal()
   */
  Dali::WebEnginePlugin::WebEngineScrollEdgeReachedSignalType& ScrollEdgeReachedSignal();

  /**
   * @copydoc Dali::WebEngine::UrlChangedSignal()
   */
  Dali::WebEnginePlugin::WebEngineUrlChangedSignalType& UrlChangedSignal();

  /**
   * @copydoc Dali::WebEngine::FormRepostDecisionSignal()
   */
  Dali::WebEnginePlugin::WebEngineFormRepostDecisionSignalType& FormRepostDecisionSignal();

  /**
   * @copydoc Dali::WebEngine::FrameRenderedSignal()
   */
  Dali::WebEnginePlugin::WebEngineFrameRenderedSignalType& FrameRenderedSignal();

private:
  /**
   * @brief Constructor.
   */
  WebEngine();

  /**
   * @brief Destructor.
   */
  virtual ~WebEngine();

  // Undefined copy constructor
  WebEngine(const WebEngine& WebEngine);

  // Undefined assignment operator
  WebEngine& operator=(const WebEngine& WebEngine);

  /**
   * @brief Initializes member data.
   *
   * @return Whether the initialization succeed or not.
   */
  bool Initialize();

  /**
   * @brief Initializes library handle by loading web engine plugin.
   *
   * @return Whether the initialization succeed or not.
   */
  bool InitializePluginHandle();

private:
  typedef Dali::WebEnginePlugin* (*CreateWebEngineFunction)();
  typedef void (*DestroyWebEngineFunction)(Dali::WebEnginePlugin* plugin);

  Dali::WebEnginePlugin*   mPlugin;              ///< WebEnginePlugin instance
  void*                    mHandle;              ///< Handle for the loaded library
  CreateWebEngineFunction  mCreateWebEnginePtr;  ///< Function to create plugin instance
  DestroyWebEngineFunction mDestroyWebEnginePtr; ///< Function to destroy plugin instance
};

} // namespace Adaptor
} // namespace Internal

inline static Internal::Adaptor::WebEngine& GetImplementation(Dali::WebEngine& webEngine)
{
  DALI_ASSERT_ALWAYS(webEngine && "WebEngine handle is empty.");

  BaseObject& handle = webEngine.GetBaseObject();

  return static_cast<Internal::Adaptor::WebEngine&>(handle);
}

inline static const Internal::Adaptor::WebEngine& GetImplementation(const Dali::WebEngine& webEngine)
{
  DALI_ASSERT_ALWAYS(webEngine && "WebEngine handle is empty.");

  const BaseObject& handle = webEngine.GetBaseObject();

  return static_cast<const Internal::Adaptor::WebEngine&>(handle);
}

} // namespace Dali

#endif
