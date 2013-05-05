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

	glPushMatrix();
	glTranslatef(0.0, space_h*0.1, 0.0);

	drawBase(x, y, function->Label.length()*space_h*0.45, space_h);

	ofSetColor(shadeColor);
	glTranslatef(x+5, y+space_h*0.75, 0);
	glScalef(space_h/48.0*0.5, space_h/48.0*0.5, 1.0);
	font->drawString(function->Label, 0, 0);

	glPopMatrix();
}

void RmnyScriptBoxVariable::draw(int x, int y, int space_w, int space_h){
	
}