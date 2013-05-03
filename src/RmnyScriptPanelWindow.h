//
//  RmnyScriptPanelWindow.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#ifndef __Rmny__RmnyScriptPanelWindow__
#define __Rmny__RmnyScriptPanelWindow__

#include "ofMain.h"
#include "Rmny.h"
#include "RmnyScriptCellViewer.h"

class RmnyScriptPanelWindow{
public:
	RmnySubRoutine* script;
	RmnyScriptCellViewer viewer;

	void setup();
	void update();
	void draw();
};

#endif /* defined(__Rmny__RmnyScriptPanelWindow__) */
