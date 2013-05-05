//
//  RmnyProjectManager.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#include "RmnyProjectManager.h"

void RmnyProjectManager::setup(){
	pjData.Init();

	ofSetWindowTitle("Rmny - v0.01");

	Helvetica.loadFont("assets/helveticaneue.ttf", 48);
	message = "Welcome to Rmny!";

	registerEditBox();

	panels.push_back(new RmnyScriptPanelWindow());
	panels.back()->setup(256, 50, 320, 240, &Helvetica, "Draw");
	panels.back()->script = &pjData.draw;
	panels.back()->reflesh();
}

void RmnyProjectManager::update(){
	newBoxWin.update();
	controlWindow.update();
	appWin.update();
	for (int i = 0;i < panels.size();i++){
		panels[i]->update();
	}
}

void RmnyProjectManager::draw(){
	ofBackground(254, 246, 212);

	ofSetColor(141, 132, 99);
	ofRect(0, 0, ofGetWidth(), 18);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(message, 5, 12);

	appWin.draw();
	newBoxWin.draw();
	controlWindow.draw();
	for (int i = 0;i < panels.size();i++){
		panels[i]->draw();
	}
}

void RmnyProjectManager::registerEditBox(){
	ofColor c,s,b;

	newBoxWin.setup(150, 50, 250, 200, &Helvetica, "Add Peace");

	c.set(RMNY_PALETTE_RED_BASE);
	s.set(RMNY_PALETTE_RED_SHADE);
	b.set(RMNY_PALETTE_RED_BRIGHT);

	newBoxWin.registerSelector(c, s, b, "Functions");
	newBoxWin.registerSelector(c, s, b, "Graphics","Functions");
	newBoxWin.registerSelector(c, s, b, "Utilities","Functions");
	newBoxWin.registerSelector(c, s, b, "Maths","Functions");
	newBoxWin.registerSelector(c, s, b, "ofRect","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofCircle","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofLine","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofTriangle","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "ofSetColor","Graphics");
	newBoxWin.registerSelector(c, s, b, "Last","Graphics");

	c.set(RMNY_PALETTE_GREEN_BASE);
	s.set(RMNY_PALETTE_GREEN_SHADE);
	b.set(RMNY_PALETTE_GREEN_BRIGHT);
	newBoxWin.registerSelector(c, s, b, "Variables");
	newBoxWin.registerSelector(c, s, b, "Integer","Variables");
	newBoxWin.registerSelector(c, s, b, "Float","Variables");
	newBoxWin.registerSelector(c, s, b, "Boolean","Variables");
	newBoxWin.registerSelector(c, s, b, "String","Variables");
	newBoxWin.registerSelector(c, s, b, "Character","Variables");

	c.set(RMNY_PALETTE_PURPLE_BASE);
	s.set(RMNY_PALETTE_PURPLE_SHADE);
	b.set(RMNY_PALETTE_PURPLE_BRIGHT);
	newBoxWin.registerSelector(c, s, b, "Objects");


	appWin.setup(512, 360, 640, 480, &Helvetica, "testApp");
	appWin.setApp(&pjData);

	controlWindow.setup(0, 50, 150, 400, &Helvetica, "ToolBox");
	c.set(220, 220, 220);
	s.set(60, 60, 60);
	b.set(240, 240, 240);
	controlWindow.registerSelector(c, s, b, "File");
	controlWindow.registerSelector(c, s, b, "Load","File");
	controlWindow.registerSelector(c, s, b, "Save","File");

	controlWindow.registerSelector(c, s, b, "View");
	controlWindow.registerSelector(c, s, b, "Setup"	,"View");
	controlWindow.registerSelector(c, s, b, "Update","View");
	controlWindow.registerSelector(c, s, b, "Draw"	,"View");

}