//
//  RmnyProjectManager.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#ifndef __Rmny__RmnyProjectManager__
#define __Rmny__RmnyProjectManager__

#include "RmnyDefines.h"
#include "RmnyScriptPanelWindow.h"
#include "RmnySelectWindow.h"
#include "RmnyApplicationWindow.h"
#include "RmnyProjectData.h"

/* [RmnyProjectManager]
 
 プロジェクト全体を管理します。
 データ管理やUIとの受け渡し等。

 */
class RmnyProjectManager{
public:

	RmnyProjectData pjData;
	string message;

	RmnySelectWindow newBoxWin;
	RmnySelectWindow controlWindow;
	RmnySelectWindow variableBoxWin;
	deque<RmnyScriptPanelWindow*> panels;

	RmnyApplicationWindow appWin;

	ofTrueTypeFont Helvetica;

	void setup();
	void update();
	void draw();

	void createNewPjData(string file = "");

	void registerEditBox();
};

#endif /* defined(__Rmny__RmnyProjectManager__) */
