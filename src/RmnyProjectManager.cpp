//
//  RmnyProjectManager.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#include "RmnyProjectManager.h"

void RmnyProjectManager::setup(){
	ofSetWindowTitle("Rmny - v0.01");
	Helvetica.loadFont("assets/helveticaneue.ttf", 48);
	message = "Welcome to Rmny!";
	win.setup(50, 50, 300, 300, &Helvetica,"testWindow");
	win.registerSelector(RMNY_PALETTE_RED_BASE, "Test1");
	win.registerSelector(RMNY_PALETTE_GREEN_BASE, "Test2");
	win.registerSelector(RMNY_PALETTE_GREEN_BASE
						 , "Test3");
	win.registerSelector(RMNY_PALETTE_YELLOW_BASE, "Child1","Test1");
	win.registerSelector(RMNY_PALETTE_GREEN_BASE, "Child2","Test1");
	win.registerSelector(RMNY_PALETTE_BLUE_BASE, "Child3","Test1");

}

void RmnyProjectManager::update(){
	win.update();
}

void RmnyProjectManager::draw(){
	ofBackground(254, 246, 212);

	ofSetColor(141, 132, 99);
	ofRect(0, 0, ofGetWidth(), 18);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(message, 5, 12);

	win.draw();
}

