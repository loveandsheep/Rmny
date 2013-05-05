//
//  RmnyScriptPanelWindow.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#include "RmnyScriptPanelWindow.h"

void RmnyScriptPanelWindow::setup(int x, int y, int w, int h){
	window.set(x, y, w, h);

	buffer.allocate(w, h);
	viewer.setup(ofPoint(w,h),ofPoint(w,50));

}

void RmnyScriptPanelWindow::update(){

}

void RmnyScriptPanelWindow::draw(){
	buffer.begin();
	ofClear(254, 266, 212);
	viewer.draw();
	ofSetColor(220,220,220);
	for (int i = 0;i < window.height;i+=viewer.glidSize.y){
		ofLine(0, i, window.width, i);
	}
	buffer.end();

	ofSetColor(255);
	buffer.draw(window.x,window.y);
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
		scr->font = helvetica;
		viewer.scriptBoxes.push_back(scr);
	}
}