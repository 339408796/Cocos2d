#ifndef example16_1_GameMainScene_h
#define example16_1_GameMainScene_h

#include "cocos2d.h"
#include "GameObjMap.h"
using namespace cocos2d;
class GameMain:public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene *scene();
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	bool isover;
	GameObjMap *map;
	CCSprite *gameover;

	void menuBackCallback(CCObject *pSender);
	void onEnterTransitionDidFinish();
	void onExitTransitionDidStart();
	void update(float time);

	CREATE_FUNC(GameMain);
};







#endif