//
//  RmnySubRoutine.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#include "RmnySubRoutine.h"

void RmnySubRoutine::doRoutine(){

	for (int i = 0;i < functions.size();i++){

		functions[i]->doFunction();

	}
	
}

void RmnySubRoutine::addArgument(RmnyVariableBase *value){
	arguments.push_back(value);
}

void RmnySubRoutine::addFunction(RmnyBaseFunction *func){
	functions.push_back(func);
}

void RmnySubRoutine::addLocalValues(RmnyVariableBase *value){
	localValues.push_back(value);
}

void RmnySubRoutine::insertFunction(RmnyBaseFunction *func, int index){
	functions.insert(functions.begin()+index, func);
}

void RmnySubRoutine::insertLocalValues(RmnyVariableBase *value, int index){
	localValues.insert(localValues.begin()+index, value);
}