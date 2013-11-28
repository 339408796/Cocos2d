//
//  GameScene.h
//  example11-1
//
//  Created by shuoquan man on 12-10-14.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//

#ifndef example15_1_GameScene_h
#define example15_1_GameScene_h
#include "cocos2d.h"
#include "GameObjHero.h"
#include "GameObjEnemy.h"
#include "GameMark.h"
using namespace cocos2d;
class GameMain : public cocos2d::CCLayer
{
public:

	GameObjHero *hero;
	GameMark* gamemark;
    CCSprite *blood1;
    CCSprite *blood2;
    CCSprite *blood3;
    CCSprite *bg1;
    CCSprite *bg2;
	CCSprite* gameover;
    CCArray *enemys;
	CCArray *bullets;
    CCArray *enemybullets;
    short blood;
    bool isreduce;
    bool isover;

	static cocos2d::CCScene* scene();
    virtual bool init();
    virtual void update(float time);
   
    void releaseenemyBullet(int x,int y);
    void releaseheroBullet(int x,int y);
	void menuBackCallback(CCObject* pSender);
    bool isCollion(CCPoint p1,CCPoint p2,int w1,int h1,int w2,int h2);
    void setherohurt();
    void resetreduce(float interval);
	void setover();
    
    CREATE_FUNC(GameMain);
};


#endif
