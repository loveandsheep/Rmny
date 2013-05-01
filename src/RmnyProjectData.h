//
//  RmnyProjectData.h
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#ifndef __Rmny__RmnyProjectData__
#define __Rmny__RmnyProjectData__

#include "ofMain.h"
#include "RmnySubRoutine.h"

class RmnyProjectData{
public:

	void Init();

	ofFbo		buffer;			/*Virtual window*/
	string		projectName;

	RmnySubRoutine setup;
	RmnySubRoutine update;
	RmnySubRoutine draw;

	RmnySubRoutine keyPressed;
	RmnySubRoutine keyReleased;

	RmnySubRoutine mouseMoved;
	RmnySubRoutine mousePressed;
	RmnySubRoutine mouseDragged;
	RmnySubRoutine mouseReleased;

	
	deque<RmnyVariableBase*>	variables;
	deque<RmnySubRoutine*>		subRoutines;

	void addVariable(RmnyVariableBase* val);

	void do_setup();
	void do_update();
	void do_draw();

	void load(string file);
	void save(string file);
};


#endif /* defined(__Rmny__RmnyProjectData__) */
