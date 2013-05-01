//
//  RmnyProjectData.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#include "RmnyProjectData.h"

void RmnyProjectData::Init(){
//	keyPressed.addArgument(new RmnyVariable<char>("key"));
//	keyReleased.addArgument(new RmnyVariable<char>("key"));

	addVariable(new RmnyVariable<int>("circle_red"));
	addVariable(new RmnyVariable<int>("circle_blue"));
	addVariable(new RmnyVariable<int>("circle_green"));
	addVariable(new RmnyVariable<float>("circle_x"));
	addVariable(new RmnyVariable<float>("circle_y"));
	addVariable(new RmnyVariable<float>("circle_radius"));

	dynamic_cast<RmnyVariable<int>*>(variables[0])->setValue(255);
	dynamic_cast<RmnyVariable<int>*>(variables[1])->setValue(0);
	dynamic_cast<RmnyVariable<int>*>(variables[2])->setValue(0);
	dynamic_cast<RmnyVariable<float>*>(variables[3])->setValue(255.0f);
	dynamic_cast<RmnyVariable<float>*>(variables[4])->setValue(255.0f);
	dynamic_cast<RmnyVariable<float>*>(variables[5])->setValue(100.0f);

	draw.addFunction(new Rmny_ofSetColor());
	draw.setArgument(dynamic_cast<RmnyVariable<int>*>(variables[0]), 0, 0);
	draw.setArgument(dynamic_cast<RmnyVariable<int>*>(variables[1]), 0, 1);
	draw.setArgument(dynamic_cast<RmnyVariable<int>*>(variables[2]), 0, 2);

	draw.addFunction(new Rmny_ofCircle());
	draw.setArgument(dynamic_cast<RmnyVariable<float>*>(variables[3]), 1, 0);
	draw.setArgument(dynamic_cast<RmnyVariable<float>*>(variables[4]), 1, 1);
	draw.setArgument(dynamic_cast<RmnyVariable<float>*>(variables[5]), 1, 2);
}

void RmnyProjectData::do_setup(){
	setup.doRoutine();
}

void RmnyProjectData::do_update(){
	update.doRoutine();
}

void RmnyProjectData::do_draw(){
	draw.doRoutine();
}

void RmnyProjectData::addVariable(RmnyVariableBase *val){
	variables.push_back(val);
}