#include "GameObjHero.h"
#include "GameScene.h"
using namespace cocos2d;
GameObjHero::GameObjHero(void)
{
}
GameObjHero::~GameObjHero(void)
{
}
CCRect GameObjHero::rect()
{
	CCSize s=CCSizeMake(85,90);
	return CCRectMake(-s.width/2,-s.height/2,s.width,s.height);
}
void GameObjHero::onEnter()
{
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(85,90));
	CCDirector *pDirector=CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);
	CCSprite *mainsprite=CCSprite::create("catBody1.png");
	 //主体动画
    CCAnimation* animation = CCAnimation::create();
    animation->addSpriteFrameWithFileName("catBody1.png");
    animation->addSpriteFrameWithFileName("catBody2-4.png");
    animation->addSpriteFrameWithFileName("catBody3.png");
    animation->addSpriteFrameWithFileName("catBody2-4.png");
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    addChild(mainsprite);
	//尾巴
	CCSprite *tail = CCSprite::create("catTail.png");
    tail->setAnchorPoint(ccp(0.5,1));
    tail->setPosition(ccp(-5,-29));
    tail->setScale(0.5);
    tail->setRotation(20);
    tail->runAction(CCRepeatForever::create((CCActionInterval*)CCSequence::create(CCRotateBy::create(0.5,-40),CCRotateBy::create(0.5,40),NULL)));
    addChild(tail);
	//手
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
	CCNode::onExit();
}
void GameObjHero::releasebullet(float interval)
{
}