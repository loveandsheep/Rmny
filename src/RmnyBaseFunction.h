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

	vector<RmnyVariableBase*> arguments;
	vector<RmnyArgType*> Argtypes;

	RmnyVariableBase*	ret;
	RmnyArgType			getArgType(int argNum);
	string				format;
	string				Label;

	int					getArgNum();


	template <class U> bool	setArgument(RmnyVariable<U>* value,int index){

		if (index >= getArgNum()){
			cout << "too big argument Number." << endl;
			return false;
		}
		if (*Argtypes[index] == value->type){
			arguments[index] = value;
//			dynamic_cast<RmnyVariable<U>*>(arguments[index])->setValue(value->value);
			return true;

		}

		return false;
	}

	
	virtual void		doFunction(){};

	void				removeArgument(int index);

};




/************  Supported functions  ****************/

class Rmny_ofSetFrameRate : public RmnyBaseFunction{
public:
	Rmny_ofSetFrameRate(){
		arguments.clear();

		//Add arguments to arguments array.
		//arguments.push_back(new RmnyVariable<int>("targetRate"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_INT));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		//If function is not void, define return valuetype.

		Label = "ofSetFrameRate";
	}

	//Execute function.
	virtual void doFunction(){
		ofSetFrameRate((dynamic_cast<RmnyVariable<int>*>(arguments[0])->value));
	}
	
};

class Rmny_ofSetFullscreen : public RmnyBaseFunction{
public:
	Rmny_ofSetFullscreen(){
		arguments.clear();

		//Add arguments to arguments array.
		//arguments.push_back(new RmnyVariable<bool>("fullscreen"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_BOOL));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		Label = "ofSetFullscreen";
	}

	virtual void doFunction(){
		ofSetFullscreen((dynamic_cast<RmnyVariable<bool>*>(arguments[0])->value));
	}
	
};


class Rmny_ofSetColor : public RmnyBaseFunction{
public:
	Rmny_ofSetColor(){
		arguments.clear();

		//arguments.push_back(new RmnyVariable<int>("Red"));
		//arguments.push_back(new RmnyVariable<int>("Blue"));
		//arguments.push_back(new RmnyVariable<int>("Green"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_INT));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_INT));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_INT));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		Label = "ofSetColor";
	}

	virtual void doFunction(){
		ofSetColor((dynamic_cast<RmnyVariable<int>*>(arguments[0])->value),
				   (dynamic_cast<RmnyVariable<int>*>(arguments[1])->value),
				   (dynamic_cast<RmnyVariable<int>*>(arguments[2])->value));
	}
};


class Rmny_ofCircle : public RmnyBaseFunction{
public:
	Rmny_ofCircle(){
		arguments.clear();

		//arguments.push_back(new RmnyVariable<float>("x"));
		//arguments.push_back(new RmnyVariable<float>("y"));
		//arguments.push_back(new RmnyVariable<float>("radius"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_FLOAT));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_FLOAT));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_FLOAT));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		Label = "ofSetCircle";
	}
	virtual void doFunction(){
		ofCircle((dynamic_cast<RmnyVariable<float>*>(arguments[0])->value),
				 (dynamic_cast<RmnyVariable<float>*>(arguments[1])->value),
				 (dynamic_cast<RmnyVariable<float>*>(arguments[2])->value));
		;
	}
};

class Rmny_sin : public RmnyBaseFunction{
public:
	Rmny_sin(){
		arguments.clear();
		
		//arguments.push_back(new RmnyVariable<float>("value"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_FLOAT));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		Label = "sin";
	}
	virtual void doFunction(){
		sin((dynamic_cast<RmnyVariable<float>*>(arguments[0])->value));
		;
	}
};

class Rmny_cos : public RmnyBaseFunction{
public:
	Rmny_cos(){
		arguments.clear();

		//arguments.push_back(new RmnyVariable<float>("value"));
		Argtypes.push_back(new RmnyArgType(RMNY_ARG_FLOAT));
		RmnyVariableBase* base;
		arguments.assign(Argtypes.size(),base);

		Label = "cos";
	}
	virtual void doFunction(){
		cos((dynamic_cast<RmnyVariable<float>*>(arguments[0])->value));
		;
	}
};



#endif /* defined(__Rmny__RmnyBaseFunction__) */
