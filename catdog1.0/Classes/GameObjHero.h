//
//  GameObjHero.h
//  example11-1
//
//  Created by shuoquan man on 12-10-14.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameObjHero_h
#define example15_1_GameObjHero_h
#include "cocos2d.h"
using namespace cocos2d;

class GameObjHero : public CCNode, public CCTargetedTouchDelegate
{
public:
    CCSprite*lefthand;
    CCSprite*righthand;
    CCPoint offset;
    bool iscontrol;

    GameObjHero(void);
    virtual ~GameObjHero(void);
	virtual void onEnter();
    virtual void onExit();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event); 

	CCRect rect();
    void releasebullet(float interval);
    bool containsTouchLocation(CCTouch* touch);
    
};


#endif
