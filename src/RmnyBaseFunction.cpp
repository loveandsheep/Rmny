//
//  RmnyBaseFunction.cpp
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#include "RmnyBaseFunction.h"

int RmnyBaseFunction::getArgNum(){
	return arguments.size();
}

RmnyArgType RmnyBaseFunction::getArgType(int argNum){
	if (argNum >= getArgNum()) {
		cout << "too big argument Number." << endl;
		return RMNY_ARG_VOID;
	}

	return arguments[argNum]->type;
}


void RmnyBaseFunction::removeArgument(int index){

	if (index >= getArgNum()){
		cout << "too big argument Number." << endl;
		return;
	}

	arguments[index]->value = NULL;
}