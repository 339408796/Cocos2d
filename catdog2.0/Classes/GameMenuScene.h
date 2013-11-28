#ifndef example15_1_GameMenuScene_h
#define example15_1_GameManuScene_h
#include "cocos2d.h"
using namespace cocos2d;
class GameMenu:public cocos2d::CCLayer
{
public:
	bool issound;
	CCMenuItemImage *soundItem;

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

	static cocos2d::CCScene *scene();

	void menuEnter(CCNode *pSender);
	void menuNewGameCallback(CCObject *pSender);
	void menuContinueCallback(CCObject *pSender);
	void menuAboutCallback(CCObject *pSender);
	void menuSoundCallback(CCObject *pSender);

	CREATE_FUNC(GameMenu);

};


#endif