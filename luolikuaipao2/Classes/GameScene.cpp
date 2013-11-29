#include "GameScene.h"
#include "GameMenuScene.h"
#include "GameObjStar.h"
#include "GameConst.h"

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
		return false;
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	map=new GameObjMap();
	map->setAnchorPoint(ccp(0,1));
	map->setPosition(ccp(0,size.height));
	addChild(map,0);
	return true;

}
void GameMain::onEnter()
{
	CCLayer::onEnter();

}

void GameMain::onExit()
{
	CCLayer::onExit();
}

void GameMain::onEnterTransitionDidFinish()
{
	CCLayer::onEnterTransitionDidFinish();
	CCDirector::sharedDirector()->setDepthTest(false);
}

void GameMain::onExitTransitionDidStart()
{
	CCLayer::onExitTransitionDidStart();
}
void GameMain::update(float time)
{
}