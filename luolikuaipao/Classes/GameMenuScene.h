//
//  GameMenuScene.h
//  example12-1
//
//  Created by shuoquan man on 12-10-13.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example17_1_GameMenuScene_h
#define example17_1_GameMenuScene_h

#include "cocos2d.h"
using namespace cocos2d;
class GameMenu : public cocos2d::CCLayer
{
public:

    bool issound;
    CCMenuItemImage *soundItem;

    static cocos2d::CCScene* scene();
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

	void menuEnter(CCNode *pSender);
    void menuNewGameCallback(CCObject *pSender);
    void menuContinueCallback(CCObject *pSender);
    void menuAboutCallback(CCObject *pSender);
    void menuSoundCallback(CCObject *pSender);
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();

	CREATE_FUNC(GameMenu);
};

#endif
