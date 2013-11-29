#ifndef example16_1_GameAboutScene_h
#define example16_1_GameAboutScene_h
#include "cocos2d.h"
using namespace cocos2d;
class GameAbout:public CCLayer
{
public:
	static cocos2d::CCScene *scene();
	virtual bool init();
	virtual  void onEnter();
	virtual void onExit();

	void menuBackCallback(CCObject *pSender);
	void menuEnter(CCNode *pSender);

	CREATE_FUNC(GameAbout);
};

#endif