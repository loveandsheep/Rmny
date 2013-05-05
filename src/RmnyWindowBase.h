//
//  RmnyWindowBase.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/05.
//
//

#ifndef __Rmny__RmnyWindowBase__
#define __Rmny__RmnyWindowBase__

#include "ofMain.h"
#include "RmnyDefines.h"

class RmnyWindowBase{
public:
	ofTrueTypeFont* font;
	ofRectangle		rect;
	string			window_title;
	ofFbo			win;
	bool			catchWindow;
	bool			catchSizeWindow;
	bool			isMinimum;
	int				minimumHeight;

	virtual void setup(int x,int y,int w,int h,
					   ofTrueTypeFont* font_,string winTitle);
	virtual void update(){};
	virtual void draw(){
		win.begin();
		ofColor col = RMNY_PALETTE_CREAM_SHADE;
		col.a = 100;
		ofClear(col);
		win.end();
		drawUIBasis();
	};

	virtual void mouseMoved(ofMouseEventArgs &arg){mouseMovedBasis(arg);};
	virtual void mousePressed(ofMouseEventArgs &arg){mousePressedBasis(arg);};
	virtual void mouseDragged(ofMouseEventArgs &arg){mouseDraggedBasis(arg);};
	virtual void mouseReleased(ofMouseEventArgs &arg){mouseReleasedBasis(arg);};

	void mouseMovedBasis(ofMouseEventArgs &arg);
	void mousePressedBasis(ofMouseEventArgs &arg);
	void mouseDraggedBasis(ofMouseEventArgs &arg);
	void mouseReleasedBasis(ofMouseEventArgs &arg);

	bool scrollX,scrollY;
	ofPoint scrollSize;
	ofPoint scrollPos;
	ofPoint targetPos;
protected:
	virtual void setupBasis(int x,int y,int w,int h,
						    ofTrueTypeFont* font_,string winTitle);
	void drawUIBasis();
};

#endif /* defined(__Rmny__RmnyWindowBase__) */
