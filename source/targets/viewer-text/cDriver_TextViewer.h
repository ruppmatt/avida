/*
 *  cDriver_TextViewer.h
 *  Avida
 *
 *  Created by Charles on 7-1-07
 *  Copyright 1999-2007 Michigan State University. All rights reserved.
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

#ifndef cDriver_TextViewer_h
#define cDriver_TextViewer_h

#ifndef cAvidaDriver_h
#include "cAvidaDriver.h"
#endif

#ifndef cCoreView_Info_h
#include "cCoreView_Info.h"
#endif
 

#ifndef cWorldDriver_h
#include "cWorldDriver.h"
#endif

#ifndef ncurses_defs_h
#include "ncurses-defs.h"
#endif

#include <sstream>
#include <iostream>

class cWorld;


class cDriver_TextViewer : public cAvidaDriver, public cWorldDriver {
private:
  cWorld* m_world;
  cCoreView_Info m_info;

  bool m_done;                 // This is set to true when run should finish.

  cDriver_TextViewer();  // Intentionally not implemented
public:
  cDriver_TextViewer(cWorld* world);
  ~cDriver_TextViewer();
  
  void Run();
  
  // Driver Actions
  void SignalBreakpoint();
  void SetDone() { m_done = true; }

  // IO
  void Flush();
  int GetKeypress() { return getch(); }
  bool ProcessKeypress(int keypress);
  
  void RaiseException(const cString& in_string);
  void RaiseFatalException(int exit_code, const cString& in_string);

  // Screen manipulations...
  void Refresh();      // Update any changes to the screen...
  void Redraw();       // Clear the screen and redraw its contents.
  
  // Notifications
  void NotifyUpdate();
  void NotifyComment(const cString& in_string);
  void NotifyWarning(const cString& in_string);
  void NotifyError(const cString& in_string);
  void NotifyOutput(const cString& in_string);
  void Notify(const cString& in_string);

  int Confirm(const cString& in_string) { ; } // @CAO Do this...

  // Tests
  bool IsInteractive() { return true; }
};


void ExitTextViewer(int exit_code);

#endif
