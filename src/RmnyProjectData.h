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

class RmnyProjectData{
public:

	ofFbo		buffer;			/*Virtual window*/
	string		projectName;



	void load(string file);
	void save(string file);
};


#endif /* defined(__Rmny__RmnyProjectData__) */
