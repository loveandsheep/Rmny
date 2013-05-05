//
//  RmnyApplicationWindow.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/05.
//
//

#ifndef __Rmny__RmnyApplicationWindow__
#define __Rmny__RmnyApplicationWindow__

#include "RmnyWindowBase.h"
#include "RmnyProjectData.h"

class RmnyApplicationWindow : public RmnyWindowBase{
public:
	void setup(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle);
	void setApp(RmnyProjectData* project);
	void update();
	void draw();

	RmnyProjectData *App;
};

#endif /* defined(__Rmny__RmnyApplicationWindow__) */
