//
//  RmnyScriptBox.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#include "RmnyScriptBox.h"

void RmnyScriptBoxBase::drawBase(int x, int y, int w, int h){
	ofPolyline l;
	l.addVertex(x  , y);
	l.addVertex(x+w, y);
	/*insert Inlet*/
	l.addVertex(x+w, y+h);
	l.addVertex(x  , y+h);
	/*insert Outlet*/

	ofSetColor(currentColor);
	l.draw();
}

void RmnyScriptBoxFunction::draw(int x, int y, int space_w, int space_h){

}

void RmnyScriptBoxVariable::draw(int x, int y, int space_w, int space_h){
	
}