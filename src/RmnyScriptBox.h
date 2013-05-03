//
//  RmnyScriptBox.h
//  Rmny
//
//  Created by Ovis aries on 2013/05/02.
//
//

#ifndef __Rmny__RmnyScriptBox__
#define __Rmny__RmnyScriptBox__

#include "ofMain.h"
#include "RmnyBaseFunction.h"
#include "RmnyScriptBox.h"

enum RmnyInLetType{
	RMNY_INLET_VARIABLE,
	RMNY_INLET_METHOD,
	RMNY_INLET_VOID
};

enum RmnyOutLetType{
	RMNY_OUTLET_VARIABLE,
	RMNY_OUTLET_METHOD,
	RMNY_OUTLET_VOID
};

class RmnyScriptBoxBase{
public:
	virtual void draw(int x,int y,int space_w,int space_h);
	void drawBase(int x,int y,int w,int h);


	void setColor(int r,int g,int b);
	void setColor(ofColor color);

	ofColor baseColor;
	ofColor currentColor;
};

/*関数を表現するスクリプトボックス*/
class RmnyScriptBoxFunction : public RmnyScriptBoxBase{
public:
	RmnyScriptBoxFunction(){
		baseColor.set(227,140,140);
		currentColor.set(227,140,140);
	}
	
	RmnyBaseFunction* function;

	void draw(int x,int y,int space_w,int space_h);
};

/*変数を表現するスクリプトボックス*/
class RmnyScriptBoxVariable : public RmnyScriptBoxBase{
public:
	RmnyScriptBoxVariable(){
		baseColor.set(227,140,140);
		currentColor.set(227,140,140);
	}

	RmnyVariableBase* variable;
	void draw(int x,int y,int space_w,int space_h);
};

/*数式を表現するスクリプトボックス*/
class RmnyScriptBoxFormula : public RmnyScriptBoxBase{
public:

	void draw(int x,int y,int space_w,int space_h);

};

#endif /* defined(__Rmny__RmnyScriptBox__) */
