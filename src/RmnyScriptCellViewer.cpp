//
//  RmnyScriptCellViewer.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#include "RmnyScriptCellViewer.h"

void RmnyScriptCellViewer::setup(ofPoint winSize,ofPoint gliSize){

	ofAddListener(ofEvents().mouseMoved, this, &RmnyScriptCellViewer::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &RmnyScriptCellViewer::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &RmnyScriptCellViewer::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &RmnyScriptCellViewer::mouseReleased);

	windowSize = winSize;
	glidSize = gliSize;
	
}

void RmnyScriptCellViewer::update(){
	
}

void RmnyScriptCellViewer::draw(){
	for (int i = 0;i < scriptBoxes.size();i++){
		scriptBoxes[i]->draw(indent[i]*0+30, glidSize.y*i, glidSize.x, glidSize.y);
	}
}

void RmnyScriptCellViewer::mouseMoved(ofMouseEventArgs &arg){

}

void RmnyScriptCellViewer::mousePressed(ofMouseEventArgs &arg){

}

void RmnyScriptCellViewer::mouseDragged(ofMouseEventArgs &arg){

}

void RmnyScriptCellViewer::mouseReleased(ofMouseEventArgs &arg){

}