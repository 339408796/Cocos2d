//
//  GameHeroBullet.h
//  example11-1
//
//  Created by shuoquan man on 12-10-14.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameHeroBullet_h
#define example15_1_GameHeroBullet_h
#include "cocos2d.h"
using namespace cocos2d;

class GameHeroBullet : public CCNode
{
public:
    bool isvisable;
	bool getIsvisble();

    GameHeroBullet(void);
    virtual ~GameHeroBullet(void);
	virtual void onEnter();
    virtual void onExit();

    void setIsVisable();
    void setIsNotVisable(CCNode *pSender);
    
        
};


#endif
