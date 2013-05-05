//
//  RmnySelectWindow.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/05/04.
//
//

#include "RmnySelectWindow.h"

void RmnySelectWindow::setup(int x, int y, int w, int h,ofTrueTypeFont* font_,string winTitle){
	window_title = winTitle;
	font = font_;
	rect.set(x, y, w, h);
	win.allocate(w,h);
	catchWindow = false;
	catchSizeWindow = false;

	selectors.label = "Root";
	selectors.isLayer = true;
	selectors.isChild = false;
	selectors.parent = NULL;
	currentLayer = &selectors;

	ofAddListener(ofEvents().mouseMoved, this, &RmnySelectWindow::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &RmnySelectWindow::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &RmnySelectWindow::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &RmnySelectWindow::mouseReleased);
	isTransform = false;
	glid_h = 20;
	focus = -1;

	isMinimum = false;
	minimumHeight = rect.height;
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

	win.begin();
	ofColor col = RMNY_PALETTE_CREAM_SHADE;
	col.a = 100;
	ofClear(col);

	if (isTransform)
		drawSelector(trans_slider-(trans_slider > 0 ? 1 : -1)*rect.width,20, transitionLayer);

	drawSelector(trans_slider, 20, currentLayer);

	if (focus > -1){
		ofSetColor(255, 60);
		ofRect(0,20+focus*glid_h, rect.width, glid_h);
	}

	win.end();

	if (!isMinimum) minimumHeight += (255			- minimumHeight)/4.0;
	if ( isMinimum) minimumHeight += (0.0			- minimumHeight)/4.0;
	if (abs(minimumHeight - 255) < 1.0) minimumHeight = 255;
	if (abs(minimumHeight - 000) < 1.0) minimumHeight = 0;

	ofSetColor(255, 255, 255,minimumHeight);
	win.draw(rect.x,rect.y);

	glPushMatrix();
	glTranslated(rect.x, rect.y, 0);
	ofSetColor(RMNY_PALETTE_CREAM_SHADE);
	ofFill();
	ofRect(0, 0, rect.width, 20);

	//バックボタン
	ofSetColor(RMNY_PALETTE_CREAM_BASE,(currentLayer->parent == NULL) ? 80 : 255);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f( 4, 10);
	glVertex2f(13,  4);
	glVertex2f(13, 16);
	glEnd();

	//最小化ボタン
	ofSetColor(RMNY_PALETTE_CREAM_BASE);
	glLineWidth(3.0);
	ofLine(rect.width-18, 10, rect.width-5, 10);
	glLineWidth(1.0);

	//Parent Label
	glPushMatrix();
	ofSetColor(RMNY_PALETTE_CREAM_BASE);
	glTranslatef(20+trans_slider, 16, 0);
	glScalef(20.0/48.0*0.5, 20.0/48.0*0.5, 1.0);
	font->drawString(currentLayer->label,0,0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(rect.width - window_title.length()*8 - 20, 16, 0);
	glScalef(20.0/48.0*0.5, 20.0/48.0*0.5, 1.0);
	font->drawString(window_title, 0, 0);
	glPopMatrix();


	//サイズ調整グリッド
	ofSetColor(RMNY_PALETTE_BLUE_SHADE,minimumHeight);
	glLineWidth(2.0);
	ofLine(rect.width,
			rect.height-15,
			rect.width -15,
			rect.height);
	ofLine(rect.width,
			rect.height-10,
			rect.width -10,
			rect.height);
	ofLine(rect.width,
			rect.height-5,
			rect.width -5,
			rect.height);
	glLineWidth(1.0);

	glPopMatrix();

	ofSetColor(RMNY_PALETTE_BLUE_SHADE);
	if (catchSizeWindow){
		ofNoFill();
		ofRect(rect);
		ofFill();
	}
}

void RmnySelectWindow::drawSelector(int x, int y, Rmny_Selector *sl){

	for (int i = 0;i < sl->child.size();i++){
		glPushMatrix();
		glTranslatef(x, y+i*glid_h, 0.0);
		ofSetColor(sl->child[i]->color);
		ofRect(0, 0, rect.width, glid_h);
		ofSetColor(0, 0, 0);
		glTranslatef(3, glid_h*0.9, 0.0);
		glScalef(glid_h/48.0*0.8, glid_h/48.0*0.8, 1.0);
		font->drawString(sl->child[i]->label,0,0);
		glPopMatrix();
	}
}

void RmnySelectWindow::registerSelector(ofColor col,string name,string parent){
	Rmny_Selector* sl = new Rmny_Selector;
	sl->color = col;
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
	if (!isTransform && rect.x < arg.x && arg.x < rect.x+rect.width){
		for (int i = 0;i < currentLayer->child.size();i++){
			if (rect.y+20+i*glid_h < arg.y && arg.y < rect.y+20+(i+1)*glid_h){
				focus = i;
			}
		}
	}else{
		focus = -1;
	}

}

void RmnySelectWindow::mousePressed(ofMouseEventArgs &arg){

	if (ofRectangle(rect.x+rect.width-18,rect.y,13,20).inside(arg.x, arg.y)){
		isMinimum ^= true;
	}
	catchWindow = ofRectangle(rect.x,rect.y,rect.width,20).inside(arg.x, arg.y);

	/*最小化によるマウス操作の無効化*/
	if (minimumHeight < 250) return;

	catchSizeWindow = ofRectangle(rect.x+rect.width -20,
								  rect.y+rect.height-20,20,20).inside(arg.x,arg.y);

	int catchSelector = -1;
	if (currentLayer->parent != NULL){
		if (ofRectangle(rect.x,rect.y,20,20).inside(arg.x, arg.y)){
			transitionLayer = currentLayer;
			Rmny_Selector* cu = currentLayer->parent;
			currentLayer = cu;
			trans_slider = -rect.width;
			isTransform = true;
		}
	}

	if (!isTransform && rect.x < arg.x && arg.x < rect.x+rect.width){
		for (int i = 0;i < currentLayer->child.size();i++){
			if (rect.y+20+i*glid_h < arg.y && arg.y < rect.y+20+(i+1)*glid_h){
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
			isTransform = true;
		}
	}
}

void RmnySelectWindow::mouseDragged(ofMouseEventArgs &arg){

	if (catchWindow){
		rect.x += arg.x - ofGetPreviousMouseX();
		rect.y += arg.y - ofGetPreviousMouseY();
	}
	
	if (minimumHeight < 250) return;

	if (catchSizeWindow){
		rect.width += arg.x - ofGetPreviousMouseX();
		rect.height += arg.y - ofGetPreviousMouseY();
		rect.width = MAX(100,rect.width);
		rect.height = MAX(glid_h+20,rect.height);
	}
}

void RmnySelectWindow::mouseReleased(ofMouseEventArgs &arg){
	catchWindow = false;

	if (catchSizeWindow){
		win.allocate(rect.width, rect.height);
		catchSizeWindow = false;
	}
}