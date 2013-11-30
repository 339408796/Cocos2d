#ifndef example16_1_GameMainScene_h
#define example16_1_GameMainScene_h

#include "cocos2d.h"
#include "GameObjMap.h"
#include "GameObjHero.h"
#include "GameMark.h"
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
	GameMark *gamemark;
	GameObjHero *hero;

	void menuBackCallback(CCObject *pSender);
	void onEnterTransitionDidFinish();
	void onExitTransitionDidStart();
	void update(float time);
	void isherodrop();
	void setover();
	bool iscollion(CCPoint p1,CCPoint p2,int w1,int h1,int w2,int h2);
	CREATE_FUNC(GameMain);
};







#endif