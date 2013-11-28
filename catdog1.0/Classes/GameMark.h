//
//  GameMark.h
//  example11-1
//
//  Created by shuoquan man on 12-10-20.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameMark_h
#define example15_1_GameMark_h

#include "cocos2d.h"
using namespace cocos2d;

class GameMark : public CCNode
{
public:
	CCArray *bits;
    int mark;
	CCTexture2D* ui;

    GameMark(void);
    virtual ~GameMark(void);
    virtual void onEnter();
    virtual void onExit();
    
    void addnumber(int var);
    
};

#endif
