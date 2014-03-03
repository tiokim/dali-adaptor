//
// Copyright (c) 2014 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <dali/public-api/dali-core.h>

#include <public-api/adaptor-framework/livebox-plugin.h>
#include <dali/public-api/adaptor-framework/common/adaptor.h>
#include <dali/public-api/adaptor-framework/common/render-surface.h>
#include <dali/public-api/adaptor-framework/common/orientation.h>
#include <dali/public-api/adaptor-framework/common/timer.h>

using namespace Dali;

/*****************************************************************************
 * Test to see if the dali-adaptor is linking correctly.
 */

class LinkerApp : public ConnectionTracker
{
public:
  LinkerApp(LiveboxPlugin &app)
  {
    app.InitializedSignal().Connect(this, &LinkerApp::Create);
  }

public:

  void Create(LiveboxPlugin& app)
  {
  }
};

/*****************************************************************************/

int
main(int argc, char **argv)
{
  LiveboxPlugin *liveboxPlugin = new LiveboxPlugin(&argc, &argv);
  LinkerApp linkerApp (*liveboxPlugin);

  liveboxPlugin->Run();

  return 0;
}
