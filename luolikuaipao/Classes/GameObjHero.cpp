#include "GameObjHero.h"
#include "GameScene.h"
using namespace cocos2d;

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
	CCDirector *pDirector=CCDirector::sharedDirector();
	pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);

	CCSprite *obj=CCSprite::create("s_hurt.png");
	hurt=obj->getTexture();
	obj=CCSprite::create("s_jump.png");
	jump=obj->getTexture();
	mainsprite=CCSprite::create("s_1.png");

	//¶¯»­
	CCAnimation *animation=CCAnimation::create();
	animation->addSpriteFrameWithFileName("s_1.png");
	animation->addSpriteFrameWithFileName("s_2.png");
	animation->addSpriteFrameWithFileName("s_3.png");
	animation->addSpriteFrameWithFileName("s_4.png");
	animation->addSpriteFrameWithFileName("s_5.png");
	animation->addSpriteFrameWithFileName("s_6.png");
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
	state=0;
	addChild(mainsprite);

}
void GameObjHero::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCNode::onExit();
}
void GameObjHero::setState(short var)
{
	if(state==var)
		return;
	state=var;
	switch(state)
	{
	case 1://ÌøÔ¾
		this->stopAllActions();
		mainsprite->stopAllActions();
		mainsprite->setTexture(jump);
		this->runAction(CCSequence::create(CCJumpBy::create(2.5,ccp(0,0),100,1),CCCallFuncN::create(this,callfuncN_selector(GameObjHero::jumpend)),NULL));
		break;
	case 2:
		this->stopAllActions();
		mainsprite->stopAllActions();
		mainsprite->setTexture(hurt);
		this->runAction(CCSequence::create(CCBlink::create(3,10),CCCallFuncN::create(this,callfuncN_selector(GameObjHero::hurtend)),NULL));
		((GameMain *)this->getParent())->setover();
		break;
	case 0:
		this->stopAllActions();
		mainsprite->stopAllActions();
		CCAnimation * animation = CCAnimation::create();
		animation->addSpriteFrameWithFileName("s_1.png");
		animation->addSpriteFrameWithFileName("s_2.png");
		animation->addSpriteFrameWithFileName("s_3.png");
		animation->addSpriteFrameWithFileName("s_4.png");
		animation->addSpriteFrameWithFileName("s_5.png");
		animation->addSpriteFrameWithFileName("s_6.png");
		animation->setDelayPerUnit(0.1f);
		animation->setRestoreOriginalFrame(true);
		mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
		break;

	}
}
bool GameObjHero::ccTouchBegan(CCTouch *touch,CCEvent *event)
{
	if(((GameMain *)this->getParent())->isover)
		return false;
	setState(1);
	return true;
}
void GameObjHero::ccTouchMoved(CCTouch *touch,CCEvent *event)
{
}
void GameObjHero::ccTouchEnded(CCTouch *touch,CCEvent *event)
{
}

void GameObjHero::touchDelegateRetain()
{
	this->retain();
}
void GameObjHero::touchDelegateRelease()
{
	this->release();
}
CCRect GameObjHero::rect()
{
	CCSize s=CCSizeMake(100,125);
	return CCRectMake(-s.width/2,-s.height/2,s.width,s.height);
}
bool GameObjHero::containsTouchLocation(CCTouch *touch)
{
	return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}
void GameObjHero::jumpend(CCNode *sender)
{
	setState(0);
}
void GameObjHero::hurtend(CCNode *sender)
{
	setState(0);
}