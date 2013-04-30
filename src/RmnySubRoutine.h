//
//  RmnySubRoutine.h
//  Rmny
//
//  Created by Ovis aries on 2013/04/29.
//
//

#ifndef __Rmny__RmnySubRoutine__
#define __Rmny__RmnySubRoutine__

#include "RmnyBaseFunction.h"

class RmnySubRoutine{
public:

	deque<RmnyBaseFunction*> functions;
	void doRoutine();

};

#endif /* defined(__Rmny__RmnySubRoutine__) */
