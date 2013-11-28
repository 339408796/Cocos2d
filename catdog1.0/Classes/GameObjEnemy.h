//
//  GameObjEnemy.h
//  example11-1
//
//  Created by shuoquan man on 12-10-14.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameObjEnemy_h
#define example15_1_GameObjEnemy_h
#include "cocos2d.h"
using namespace cocos2d;

class GameObjEnemy : public CCNode
{
public:
    CCSprite *boom;
    CCSprite *mainbody;
	short type;
    bool islife;

    GameObjEnemy(void);
    virtual ~GameObjEnemy(void);
	virtual void onEnter();
    virtual void onExit();

    void releasebullet(float interval);
    void movestart();
    void restart(CCNode *pSender);
    void setdie();
    void setType(short var);
};


#endif
