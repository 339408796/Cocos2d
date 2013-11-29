#ifndef example16_1_GameObjStar_h
#define example16_1_GameObjStar_h
#include "cocos2d.h"
using namespace cocos2d;
class GameObjStar:public CCNode
{
public:
	GameObjStar(void);
	virtual ~GameObjStar(void);
	virtual void onEnter();
	virtual void onExit();
	
	void set_visable(bool var);
	bool get_visable();

	short state;
	bool _visable;
	
};


#endif