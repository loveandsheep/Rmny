//
//  RmnyScriptPanelWindow.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#include "RmnyScriptPanelWindow.h"

void RmnyScriptPanelWindow::setup(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle){
	setupBasis(x, y, w, h, font_, winTitle);

	viewer.setup(ofPoint(w,h),ofPoint(w,30));

}

void RmnyScriptPanelWindow::update(){

}

void RmnyScriptPanelWindow::draw(){
	win.begin();
	ofColor c = RMNY_PALETTE_CREAM_SHADE;
	c.a = 30;
	ofClear(c);
	viewer.draw();
	ofSetColor(220,220,220);
	for (int i = 0;i < win.getHeight();i+=viewer.glidSize.y){
		ofLine(0, i, win.getWidth(), i);
	}
	win.end();

	ofSetColor(255);

	drawUIBasis();
}

void RmnyScriptPanelWindow::reflesh(){
	/*スクリプトボックスを消去*/
	while (viewer.scriptBoxes.size() > 0) {
		delete viewer.scriptBoxes.back();
		viewer.scriptBoxes.pop_back();
	}

	/*スクリプトボックスを新しく更新*/
	for (int i = 0;i < script->functions.size();i++){
		RmnyScriptBoxFunction* scr = new RmnyScriptBoxFunction();
		scr->function = script->functions[i];
		scr->font = font;
		viewer.scriptBoxes.push_back(scr);
	}
}