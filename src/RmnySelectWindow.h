//
//  RmnySelectWindow.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#ifndef __Rmny__RmnySelectWindow__
#define __Rmny__RmnySelectWindow__

#include "RmnyWindowBase.h"

struct Rmny_Selector{
	Rmny_Selector* parent;
	deque<Rmny_Selector*> child;
	string label;
	bool isChild;
	bool isLayer;
	ofColor color;
	ofColor color_shade;
	ofColor color_bright;
};

class RmnySelectWindow : public RmnyWindowBase{
public:

	void setup(int x,int y,int w,int h,ofTrueTypeFont* font_,string winTitle);
	void update();
	void draw();
	void drawSelector(int x,int y,Rmny_Selector* sl);
	void registerSelector(ofColor col,ofColor shade,ofColor bright,string name,string parent = "Root");

	void mouseMoved(ofMouseEventArgs &arg);
	void mousePressed(ofMouseEventArgs &arg);
	void mouseDragged(ofMouseEventArgs &arg);
	void mouseReleased(ofMouseEventArgs &arg);

	Rmny_Selector* searchSelector(deque<Rmny_Selector*>* target, string name);

	bool			isTransform;
	float			trans_slider;
	int				focus;
	int				glid_h;
	
	Rmny_Selector*	transitionLayer;
	Rmny_Selector*	currentLayer;
	
	Rmny_Selector	selectors;

};



#endif /* defined(__Rmny__RmnySelectWindow__) */
