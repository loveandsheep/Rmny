//
//  RmnyApplicationWindow.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/05.
//
//

#include "RmnyApplicationWindow.h"

void RmnyApplicationWindow::setup(int x, int y, int w, int h, ofTrueTypeFont *font_, string winTitle){

	setupBasis(x, y, w, h, font_, winTitle);

}

void RmnyApplicationWindow::setApp(RmnyProjectData* project){
	App = project;
	App->setup.doRoutine();
}

void RmnyApplicationWindow::update(){
	App->update.doRoutine();
}

void RmnyApplicationWindow::draw(){
	win.begin();
	ofClear(200,200,200,255);
	App->draw.doRoutine();
	win.end();

	drawUIBasis();
}