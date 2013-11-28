//
//  GameMenuScene.h
//  example11-1
//
//  Created by shuoquan man on 12-10-13.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameMenuScene_h
#define example15_1_GameMenuScene_h

#include "cocos2d.h"
using namespace cocos2d;
class GameMenu : public cocos2d::CCLayer
{
public:

    CCMenuItemImage *soundItem;
    bool issound;

    static cocos2d::CCScene* scene();
	virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    void menuEnter(CCNode* pSender);
    void menuNewGameCallback(CCObject* pSender);
    void menuContinueCallback(CCObject* pSender);
    void menuAboutCallback(CCObject* pSender);
    void menuSoundCallback(CCObject* pSender);
    
    CREATE_FUNC(GameMenu);
};

#endif
