//
//  RmnyWindowBase.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/05.
//
//

#include "RmnyWindowBase.h"

void RmnyWindowBase::setupBasis(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle){
	window_title = winTitle;
	font = font_;
	rect.set(x, y, w, h);
	win.allocate(w,h);
	catchWindow = false;
	catchSizeWindow = false;
	isMinimum = false;
	minimumHeight = 255;

	ofAddListener(ofEvents().mouseMoved, this, &RmnyWindowBase::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &RmnyWindowBase::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &RmnyWindowBase::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &RmnyWindowBase::mouseReleased);

	scrollPos.set(0, 0);
	scrollX = false;
	scrollY = false;
}

void RmnyWindowBase::setup(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle){
	setupBasis(x, y, w, h, font_, winTitle);
}

void RmnyWindowBase::drawUIBasis(){
	if (!isMinimum) minimumHeight += (255			- minimumHeight)/4.0;
	if ( isMinimum) minimumHeight += (0.0			- minimumHeight)/4.0;
	if (abs(minimumHeight - 255) < 1.0) minimumHeight = 255;
	if (abs(minimumHeight - 000) < 1.0) minimumHeight = 0;

	ofSetColor(255, 255, 255,minimumHeight);
	win.draw(rect.x,rect.y);

	glPushMatrix();
	glTranslated(rect.x, rect.y-20, 0);
	ofSetColor(RMNY_PALETTE_CREAM_SHADE);
	ofFill();
	ofRect(0, 0, rect.width, 20);

	//最小化ボタン
	ofSetColor(RMNY_PALETTE_CREAM_BASE);
	glLineWidth(3.0);
	ofLine(rect.width-18, 10, rect.width-5, 10);
	glLineWidth(1.0);

	glPushMatrix();
	glTranslatef(rect.width - font->getStringBoundingBox(window_title, 0, 0).width*20.0/48.0*0.5 - 20,
				 16, 0);
	glScalef(20.0/48.0*0.5, 20.0/48.0*0.5, 1.0);
	font->drawString(window_title, 0, 0);
	glPopMatrix();


	//サイズ調整グリッド
	ofSetColor(RMNY_PALETTE_BLUE_SHADE,minimumHeight);
	glLineWidth(2.0);
	ofLine(rect.width,
		   rect.height-15+20,
		   rect.width -15,
		   rect.height+20);
	ofLine(rect.width,
		   rect.height-10+20,
		   rect.width -10,
		   rect.height+20);
	ofLine(rect.width,
		   rect.height-5+20,
		   rect.width -5,
		   rect.height+20);
	glLineWidth(1.0);

	glPopMatrix();

	ofSetColor(RMNY_PALETTE_CREAM_SHADE);
	if (catchSizeWindow){
		ofNoFill();
		ofRect(rect);
		ofFill();
	}
}


void RmnyWindowBase::mouseMovedBasis(ofMouseEventArgs &arg){
	targetPos.set(arg.x-rect.x, arg.y-rect.y);
	if (rect.inside(arg.x, arg.y) && scrollY){
		if (rect.height < scrollSize.y){
			targetPos.y = (arg.y - rect.y) / rect.height * scrollSize.y;
			scrollPos.y = MAX(0,MIN(scrollSize.y - rect.height,
									(targetPos.y - (arg.y - rect.y))));
		}
	}
}

void RmnyWindowBase::mousePressedBasis(ofMouseEventArgs &arg){
	if (ofRectangle(rect.x+rect.width-18,rect.y-20,13,20).inside(arg.x, arg.y)){
		isMinimum ^= true;
	}
	catchWindow = ofRectangle(rect.x,rect.y-20,rect.width,20).inside(arg.x, arg.y);

	/*最小化によるマウス操作の無効化*/
	if (minimumHeight < 250) return;

	catchSizeWindow = ofRectangle(rect.x+rect.width -20,
								  rect.y+rect.height-20,20,20).inside(arg.x,arg.y);

}

void RmnyWindowBase::mouseDraggedBasis(ofMouseEventArgs &arg){
	targetPos.set(arg.x-rect.x, arg.y-rect.y);
	if (catchWindow){
		rect.x += arg.x - ofGetPreviousMouseX();
		rect.y += arg.y - ofGetPreviousMouseY();
	}

	if (minimumHeight < 250) return;

	if (catchSizeWindow){
		rect.width += arg.x - ofGetPreviousMouseX();
		rect.height += arg.y - ofGetPreviousMouseY();
		rect.width = MAX(100,rect.width);
		rect.height = MAX(60,rect.height);
	}
}

void RmnyWindowBase::mouseReleasedBasis(ofMouseEventArgs &arg){
	catchWindow = false;

	if (catchSizeWindow){
		win.allocate(rect.width, rect.height);
		scrollPos.y = 0;
		catchSizeWindow = false;
	}
}