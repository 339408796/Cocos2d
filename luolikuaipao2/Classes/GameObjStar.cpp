#include "GameObjStar.h"
using namespace cocos2d;
GameObjStar::GameObjStar()
{
}

GameObjStar::~GameObjStar()
{
}

void GameObjStar::onEnter()
{
	CCNode::onEnter();
	this->setContentSize(CCSizeMake(36.5,35.5));
	CCSprite *star=CCSprite::create("star.png");
	star->setScale(0.5);
	_visable=true;
	addChild(star,1);
}
void GameObjStar::onExit()
{
	CCNode::onExit();
}

bool GameObjStar::get_visable()
{
	return _visable;
}

void GameObjStar::set_visable(bool var)
{
	_visable=var;
	this->setVisible(var);
}