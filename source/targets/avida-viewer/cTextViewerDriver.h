/*
 *  cTextViewerDriver.h
 *  Avida
 *
 *  Created by David on 12/11/05.
 *  Copyright 1999-2008 Michigan State University. All rights reserved.
 *
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; version 2
 *  of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef cTextViewerDriver_h
#define cTextViewerDriver_h

#ifndef cTextViewerDriver_Base_h
#include "cTextViewerDriver_Base.h"
#endif

class cTextViewerDriver : public cTextViewerDriver_Base
{
private:
  cTextViewerDriver();  // not implemented
  
public:
  cTextViewerDriver(cWorld* world);
  ~cTextViewerDriver();
  
  void Run();
  
  // Driver Actions
  void SignalBreakpoint();
  void SetDone() { m_done = true; }
  
  void RaiseException(const cString& in_string);
  void RaiseFatalException(int exit_code, const cString& in_string);
  
  // Notifications
  void NotifyComment(const cString& in_string);
  void NotifyWarning(const cString& in_string);
};


#ifdef ENABLE_UNIT_TESTS
namespace nTextViewerDriver {
  /**
   * Run unit tests
   *
   * @param full Run full test suite; if false, just the fast tests.
   **/
  void UnitTests(bool full = false);
}
#endif  

#endif
