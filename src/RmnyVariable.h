//
//  RmnyVariable.h
//  Rmny
//
//  Created by Ovis aries on 2013/04/30.
//
//

#ifndef __Rmny__RmnyVariable__
#define __Rmny__RmnyVariable__

#include "ofMain.h"

enum RmnyArgType{
	RMNY_ARG_BOOL,
	RMNY_ARG_INT,
	RMNY_ARG_FLOAT,
	RMNY_ARG_DOUBLE,
	RMNY_ARG_CHAR,
	RMNY_ARG_STRING,
	RMNY_ARG_OFPOINT,
	RMNY_ARG_OFVEC2F,
	RMNY_ARG_OFVEC3F,
	RMNY_ARG_OFRECTANGLE
};

class RmnyVariable {

public:
	RmnyArgType type;
};

class RmnyVariableInt : public RmnyVariable{
public:
	RmnyVariableInt(){
		type = RMNY_ARG_INT;
	}
	int value;
};

class RmnyVariableFloat : public RmnyVariable{
public:
	RmnyVariableFloat(){
		type = RMNY_ARG_FLOAT;
	}
	float value;
};

class RmnyVariableBool : public RmnyVariable{
public:
	RmnyVariableBool(){
		type = RMNY_ARG_BOOL;
	}
	bool value;
};

class RmnyVariableString : public RmnyVariable{
public:
	RmnyVariableString(){
		type = RMNY_ARG_STRING;
	}
	string value;
};

#endif /* defined(__Rmny__RmnyVariable__) */
