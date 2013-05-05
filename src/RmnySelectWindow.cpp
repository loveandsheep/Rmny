//
//  RmnySelectWindow.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#include "RmnySelectWindow.h"

void RmnySelectWindow::setup(int x, int y, int w, int h,ofTrueTypeFont* font_,string winTitle){

	setupBasis(x, y, w, h, font_, winTitle);

	selectors.label = "Root";
	selectors.isLayer = true;
	selectors.isChild = false;
	selectors.parent = NULL;
	currentLayer = &selectors;

	glid_h = 20;
	focus = -1;

	isTransform = false;
	scrollY = true;
}

void RmnySelectWindow::update(){
	if (isTransform){
		trans_slider /= 1.3;
		if (abs(trans_slider) < 1.0){
			trans_slider = 0.0;
			isTransform = false;
		}
	}
}

void RmnySelectWindow::draw(){
	scrollSize.y = currentLayer->child.size()*glid_h;
	
	win.begin();
	ofColor col = RMNY_PALETTE_CREAM_SHADE;
	col.a = 100;
	ofClear(col);

	if (isTransform)
		drawSelector(trans_slider-(trans_slider > 0 ? 1 : -1)*rect.width,0-scrollPos.y, transitionLayer);

	drawSelector(trans_slider, 0-scrollPos.y, currentLayer);

	if (focus > -1){
		ofSetColor(255, 60);
		ofRect(0,focus*glid_h-scrollPos.y, rect.width, glid_h);
	}

	win.end();

	drawUIBasis();

	glPushMatrix();
	glTranslatef(rect.x, rect.y-20, 0.0);
	//バックボタン
	ofSetColor(RMNY_PALETTE_CREAM_BASE,(currentLayer->parent == NULL) ? 80 : 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f( 4, 10);
	glVertex2f(13,  4);
	glVertex2f(13, 16);
	glEnd();

	//Parent Label
	glPushMatrix();
	ofSetColor(RMNY_PALETTE_CREAM_BASE);
	glTranslatef(20+trans_slider, 16, 0);
	glScalef(20.0/48.0*0.5, 20.0/48.0*0.5, 1.0);
	font->drawString(currentLayer->label,0,0);
	glPopMatrix();

	glPopMatrix();
}

void RmnySelectWindow::drawSelector(int x, int y, Rmny_Selector *sl){

	for (int i = 0;i < sl->child.size();i++){
		glPushMatrix();
		glTranslatef(x, y+i*glid_h, 0.0);
		ofSetColor(sl->child[i]->color);
		ofRect(0, 0, rect.width, glid_h);
		ofSetColor(sl->child[i]->color_shade);
		glTranslatef(3, glid_h*0.9, 0.0);
		glScalef(glid_h/48.0*0.8, glid_h/48.0*0.8, 1.0);
		font->drawString(sl->child[i]->label,0,0);
		glPopMatrix();
	}
}

void RmnySelectWindow::registerSelector(ofColor col,ofColor shade,ofColor bright,string name,string parent){
	Rmny_Selector* sl = new Rmny_Selector;
	sl->color = col;
	sl->color_shade = shade;
	sl->color_bright = bright;
	sl->label = name;
	sl->isLayer = false;

	if (parent == "Root"){
		sl->isChild = false;
		sl->parent = &selectors;
		selectors.child.push_back(sl);
	}else{
		Rmny_Selector* pa = searchSelector(&selectors.child,parent);

		if (pa != NULL){
			sl->isChild = true;
			sl->parent = pa;
			pa->isLayer = true;
			pa->child.push_back(sl);
		}
	}
}

Rmny_Selector* RmnySelectWindow::searchSelector(deque<Rmny_Selector*>* target, string name){

	for (int i = 0;i < target->size();i++){
		if ((*target)[i]->label == name){
			return (*target)[i];
		}
		if ((*target)[i]->isLayer){
			Rmny_Selector* ck = searchSelector(&(*target)[i]->child, name);
			if (ck != NULL) return ck;
		}
	}

	return NULL;
}


void RmnySelectWindow::mouseMoved(ofMouseEventArgs &arg){
	mouseMovedBasis(arg);
	if (minimumHeight < 250) return;
	
	if (!isTransform && rect.x < arg.x && arg.x < rect.x+rect.width){
		for (int i = 0;i < currentLayer->child.size();i++){
			if (rect.y+i*glid_h < (arg.y+scrollPos.y) && (arg.y + scrollPos.y) < rect.y+(i+1)*glid_h){
				focus = i;
			}
		}
	}else{
		focus = -1;
	}

}

void RmnySelectWindow::mousePressed(ofMouseEventArgs &arg){
	mousePressedBasis(arg);
	if (minimumHeight < 250) return;
	
	int catchSelector = -1;
	if (currentLayer->parent != NULL){
		if (ofRectangle(0,-20,20,20).inside(targetPos)){
			transitionLayer = currentLayer;
			Rmny_Selector* cu = currentLayer->parent;
			currentLayer = cu;
			trans_slider = -rect.width;
			scrollPos.y = 0;
			isTransform = true;
		}
	}

	if (!isTransform && rect.x < arg.x && arg.x < rect.x+rect.width){
		for (int i = 0;i < currentLayer->child.size();i++){
			if (i*glid_h < targetPos.y && targetPos.y < (i+1)*glid_h){
				catchSelector = i;
				break;
			}
		}
	}
	if (catchSelector > -1){
		if (currentLayer->child[catchSelector]->isLayer){
			transitionLayer = currentLayer;
			currentLayer = currentLayer->child[catchSelector];
			trans_slider = rect.width;
			scrollPos.y = 0;
			isTransform = true;
		}
	}
}

void RmnySelectWindow::mouseDragged(ofMouseEventArgs &arg){
	mouseDraggedBasis(arg);
}

void RmnySelectWindow::mouseReleased(ofMouseEventArgs &arg){
	mouseReleasedBasis(arg);
}