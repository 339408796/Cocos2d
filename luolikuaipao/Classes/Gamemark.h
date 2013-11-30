#ifndef example16_1_GameMark_h
#define example16_1_GameMark_h
#include "cocos2d.h"
using namespace cocos2d;

class GameMark:public CCNode
{
public:

	CCTexture2D *ui;
	CCArray *bits;
	int mark;

	GameMark(void);
	virtual ~GameMark(void);
	virtual void onEnter();
	virtual void onExit();
	void addnumber(int var);
	
};

#endif