//
//  GameObjHero.cpp
//  example11-1
//
//  Created by shuoquan man on 12-10-14.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//
#include "GameObjHero.h"
#include "GameScene.h"

GameObjHero::GameObjHero(void)
{
}

GameObjHero::~GameObjHero(void)
{
}

void GameObjHero::onEnter()
{
    CCNode::onEnter();
    this->setContentSize(CCSizeMake(85,90));
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    CCSprite *mainsprite = CCSprite::create("catBody1.png");
    //���嶯��
    CCAnimation* animation = CCAnimation::create();
    animation->addSpriteFrameWithFileName("catBody1.png");
    animation->addSpriteFrameWithFileName("catBody2-4.png");
    animation->addSpriteFrameWithFileName("catBody3.png");
    animation->addSpriteFrameWithFileName("catBody2-4.png");
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(mainsprite);
    //β��
    CCSprite *tail = CCSprite::create("catTail.png");
    tail->setAnchorPoint(ccp(0.5,1));
    tail->setPosition(ccp(-5,-29));
    tail->setScale(0.5);
    tail->setRotation(20);
    tail->runAction(CCRepeatForever::create((CCActionInterval*)CCSequence::create(CCRotateBy::create(0.5,-40),CCRotateBy::create(0.5,40),NULL)));
    addChild(tail);
    //��
    lefthand = CCSprite::create("catHand1.png");
    lefthand->setAnchorPoint(ccp(1,0.5));
    lefthand->setPosition(ccp(-18,-20));
    addChild(lefthand);
    righthand = CCSprite::create("catHand2.png");
    righthand->setPosition(ccp(18,-20));
    righthand->setAnchorPoint(ccp(0,0.5));
    addChild(righthand);
    offset = ccp(0,0);
    iscontrol = false;
    schedule(schedule_selector(GameObjHero::releasebullet), 1.0f);
}

void GameObjHero::onExit()
{
	//�˳�ʱ���ͷ�ע��
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    CCNode::onExit();
}

CCRect GameObjHero::rect()
{
    CCSize s = CCSizeMake(85,90);
    return CCRectMake(-s.width / 2, -s.height / 2, s.width, s.height);
}

void GameObjHero::releasebullet(float interval){
    //�ͷ��ӵ�
    if(iscontrol){
       CCPoint pos = this->getPosition(); 
       GameMain *p = (GameMain *) this->getParent();
        p->releaseheroBullet(pos.x,pos.y + 30);
    }
}
    
bool GameObjHero::containsTouchLocation(CCTouch* touch)
{
	//�ж���ָ�Ƿ���è��
	return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool GameObjHero::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if(((GameMain *)this->getParent())->isover)
        return false;
    if(! containsTouchLocation(touch)){
        return false; 
    }else{
        //��ô���ƫ��λ��
        iscontrol = true;
        CCPoint touchPoint = touch->getLocationInView();
        touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
        offset.x = touchPoint.x - this->getPosition().x;
        offset.y = touchPoint.y - this->getPosition().y;
    }
    return true;   
}

void GameObjHero::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(iscontrol){
		CCPoint touchPoint = touch->getLocationInView();
      touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
      //��������������
      float x = touchPoint.x - offset.x; 
      float y = touchPoint.y - offset.y;
      if(x < this->getPosition().x){
          lefthand->setFlipY(true);
          righthand->setFlipY(false);
      }else{
          lefthand->setFlipY(false);
          righthand->setFlipY(true); 
      }
      this->setPosition(x,y);
    }
}

void GameObjHero::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if(iscontrol){
       iscontrol = false;
       lefthand->setFlipY(false);
       righthand->setFlipY(false);
    }
}