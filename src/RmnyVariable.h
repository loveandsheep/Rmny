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
	RMNY_ARG_OFRECTANGLE,
	RMNY_ARG_VOID
};

class RmnyVariableBase {
public:
	RmnyVariableBase(){
		type = RMNY_ARG_VOID;
		value = 128;
	}

	string name;
	RmnyArgType type;
	int value;

	virtual void setValue(int val){
		value = val;
	};
};

class RmnyVariableConst : public RmnyVariableBase{

};

class RmnyVariableInt : public RmnyVariableConst{
	RmnyVariableInt(){
		value = 0;
	}
	
	int value;
	void setValue(int val){
		value = val;
	}
};

class RmnyVariableFloat : public RmnyVariableConst{
	RmnyVariableFloat(){
		value = 0.0f;
	}
	float value;

	void setValue(float val){
		value = val;
	}
};

class RmnyVariableString : public RmnyVariableConst{
	RmnyVariableString(){
		value ="";
	}
	string value;

	void setValue(string val){
		value = val;
	}
};

class RmnyVariableBool : public RmnyVariableConst{
	RmnyVariableBool(){
		value = false;
	}
	bool value;
	void setValue(bool val){
		value = val;
	}
};

class RmnyVariableChar : public RmnyVariableConst{
	RmnyVariableChar(){
		value = 0x00;
	}
	char value;
	void setValue(char val){
		value = val;
	}
};

template <class T>
class RmnyVariable : public RmnyVariableBase{
	
public:
	RmnyVariable(string name_){
		name = name_;
		setValue(value);
	}

	T value;

	void setValue(int val){
		type = RMNY_ARG_INT;
		value = val;
	};
	void setValue(bool val){
		type = RMNY_ARG_BOOL;
		value = val;
	}
	void setValue(char val){
		type = RMNY_ARG_CHAR;
		value = val;
	}
	void setValue(float val){
		type = RMNY_ARG_FLOAT;
		value = val;
	}
	void setValue(string val){
		type = RMNY_ARG_STRING;
		value = val;
	}
	void setValue(double val){
		type = RMNY_ARG_DOUBLE;
		value = val;
	}
	void setValue(ofPoint val){
		type = RMNY_ARG_OFPOINT;
		value = val;
	}
	void setValue(ofVec2f val){
		type = RMNY_ARG_OFVEC2F;
		value = val;
	}
	void setValue(ofRectangle val){
		type = RMNY_ARG_OFRECTANGLE;
		value = val;
	}

};


#endif /* defined(__Rmny__RmnyVariable__) */
