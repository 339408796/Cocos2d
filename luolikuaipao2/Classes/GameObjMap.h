#ifndef example16_2_GameObjMap_h
#define example16_2_GameObjMap_h
#include "cocos2d.h"
using namespace cocos2d;
class GameObjMap :public CCNode
{
public:
	GameObjMap(void);
	virtual ~GameObjMap(void);
	virtual void onEnter();
	virtual void onExit();
	void bg1change(CCNode *pSender);
	void bg2change(CCNode *pSender);

	short state;
	CCArray *stars1;
	CCArray *stars2;
};
#endif