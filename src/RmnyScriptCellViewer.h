//
//  RmnyScriptCellViewer.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#ifndef __Rmny__RmnyScriptCellViewer__
#define __Rmny__RmnyScriptCellViewer__

#include "ofMain.h"
#include "RmnyScriptBox.h"

class RmnyScriptCellViewer{
public:

	void setup();
	void update();
	void draw();

	void mouseMoved(ofMouseEventArgs &arg);
	void mousePressed(ofMouseEventArgs &arg);
	void mouseDragged(ofMouseEventArgs &arg);
	void mouseReleased(ofMouseEventArgs &arg);

	
	deque<RmnyScriptBoxBase*> scriptBoxes;
	deque<int> indent;

	ofPoint windowSize;
	ofPoint glidSize;
};

#endif /* defined(__Rmny__RmnyScriptCellViewer__) */
