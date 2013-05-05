//
//  RmnyScriptBox.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#include "RmnyScriptBox.h"

void RmnyScriptBoxBase::drawBase(int x, int y, int w, int h){
	ofSetColor(currentColor);
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(x		, y);
	glVertex2f(x+w		, y);
	glVertex2f(x		, y+h);
	glVertex2f(x+w		, y+h);
	glEnd();
	glPopMatrix();
}

void RmnyScriptBoxFunction::draw(int x, int y, int space_w, int space_h){
	space_h *= 0.8;
	int block_w = 0;


	glPushMatrix();
	glTranslatef(0.0, space_h*0.1, 0.0);

	currentColor.set(RMNY_PALETTE_RED_BASE);
	drawBase(x+block_w, y, function->Label.length()*space_h*0.45, space_h);
	glPushMatrix();
	ofSetColor(RMNY_PALETTE_RED_SHADE);
	glTranslatef(x+5, y+space_h*0.75, 0);
	glScalef(space_h/48.0*0.5, space_h/48.0*0.5, 1.0);
	font->drawString(function->Label, 0, 0);
	glPopMatrix();

	block_w = function->Label.length()*space_h*0.45;

	for (int i = 0;i < function->arguments.size();i++){
		if (function->arguments[i] == NULL){
			drawBase(x + block_w, y, 100, space_h);
			block_w += 100;
		}else{

			currentColor.set(RMNY_PALETTE_GREEN_BASE);
			drawBase(x + block_w, y, function->arguments[i]->name.length()*space_h*0.45, space_h);
			
			glPushMatrix();
			ofSetColor(RMNY_PALETTE_GREEN_SHADE);
			glTranslatef(x+5+block_w, y+space_h*0.75, 0);
			glScalef(space_h/48.0*0.5, space_h/48.0*0.5, 1.0);
			font->drawString(function->arguments[i]->name, 0, 0);
			glPopMatrix();

			block_w += function->arguments[i]->name.length()*space_h*0.45;

		}
	}

	/*文字列の描画*/



	glPopMatrix();
}

void RmnyScriptBoxVariable::draw(int x, int y, int space_w, int space_h){
	
}