//
//  RmnyBaseFunction.h
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#ifndef __Rmny__RmnyBaseFunction__
#define __Rmny__RmnyBaseFunction__

#include "ofMain.h"
#include "RmnyVariable.h"

class RmnyBaseFunction{
public:

	vector<RmnyVariable*> variables;
	virtual void doFunction();

};

class Rmny_ofSetFrameRate : RmnyBaseFunction{
public:
	Rmny_ofSetFrameRate(){
		variables.push_back(&targetRate);
	}

	RmnyVariableInt targetRate;

	virtual void doFunction(){
		ofSetFrameRate(targetRate.value);
	}
};

class Rmny_ofSetFullscreen : RmnyBaseFunction{
public:
	Rmny_ofSetFullscreen(){
		variables.push_back(&fullscreen);
	}

	RmnyVariableBool fullscreen;

	virtual void doFunction(){
		ofSetFullscreen(fullscreen.value);
	}
};

#endif /* defined(__Rmny__RmnyBaseFunction__) */
