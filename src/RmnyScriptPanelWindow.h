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
#include "RmnySubRoutine.h"
#include "RmnyScriptCellViewer.h"
#include "RmnyWindowBase.h"

/*サブルーチンを編集するためのウィンドウ*/
class RmnyScriptPanelWindow : public RmnyWindowBase{
public:

	RmnyScriptCellViewer	viewer;
	RmnySubRoutine*			script;
	
	void setup(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle);
	void reflesh();
	void update();
	void draw();
};

#endif /* defined(__Rmny__RmnyScriptPanelWindow__) */
