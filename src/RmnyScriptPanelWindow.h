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

/*サブルーチンを編集するためのウィンドウ*/
class RmnyScriptPanelWindow{
public:

	RmnyScriptCellViewer	viewer;
	RmnySubRoutine*			script;


	ofRectangle				window;
	ofFbo					buffer;

	ofTrueTypeFont *helvetica;
	
	void setup(int x,int y,int w,int h);
	void reflesh();
	void update();
	void draw();
};

#endif /* defined(__Rmny__RmnyScriptPanelWindow__) */
