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