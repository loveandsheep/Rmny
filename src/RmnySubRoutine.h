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


/*サブルーチン*/
class RmnySubRoutine : RmnyBaseFunction{
public:

	deque<RmnyVariableBase*> localValues;/*ローカル変数の配列*/
	deque<RmnyBaseFunction*> functions;/*命令の配列*/

	void addArgument(RmnyVariableBase* value);

	void addFunction(RmnyBaseFunction* func);
	void addLocalValues(RmnyVariableBase* value);
	
	void insertFunction(RmnyBaseFunction* func,int index);
	void insertLocalValues(RmnyVariableBase* value,int index);

	template <class S>
	bool setArgument(RmnyVariable<S>* val,int funcNum, int argNum){
		if (funcNum > functions.size()){
			cout << "too big func Index" << endl;
			return false;
		}

		return functions[funcNum]->setArgument(val, argNum);
	}

	void doRoutine();
	
};

#endif /* defined(__Rmny__RmnySubRoutine__) */
