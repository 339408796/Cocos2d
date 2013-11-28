#include "GameScene.h"
#include "GameAboutScene.h"
#include "GameMenuScene.h"
#include "GameObjHero.h"
#include "GameObjEnemy.h"

using namespace cocos2d;

CCScene *GameMain::scene()
{
	CCScene *scene=CCScene::create();
	GameMain *layer=GameMain::create();
	scene->addChild(layer);
	return scene;
}
bool GameMain::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	//创建背景
	bg1 = CCSprite::create("bg.png");
	bg1->setScale(0.5);
	bg2 = CCSprite::create("bg.png");
	bg2->setScale(0.5);
	bg1->setAnchorPoint(ccp(0,0));
	bg2->setAnchorPoint(ccp(0,0));
	bg1->setPosition( ccp(0,0) );
	bg2->setPosition( ccp(0,size.height) );
	this->addChild(bg1, 0);
	this->addChild(bg2, 0);
	//创建主角
	hero = new GameObjHero();
	hero->setPosition(ccp(size.width/2,-50));
	hero->setScale(0.5);
	addChild(hero,2,1);
	hero->runAction(CCMoveBy::create(0.5,ccp(0,150)));
	//创建敌人
	enemys = CCArray::createWithCapacity(3);
	for(int i = 0;i < 3;i ++){
	int type = i + 1;
	GameObjEnemy* enemy = new GameObjEnemy();
	enemy->setPosition(ccp(size.width/4 * type,size.height + 50));
	enemy->setScale(0.5);
	enemy->setType(type);
	enemys->addObject(enemy);
	addChild(enemy,1);
	enemy->movestart();
	}
	enemys->retain();
	return true;
}
void releaseenemyBullet(int x,int y)
{
}
