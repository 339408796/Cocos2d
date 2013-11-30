//
// GameMenuScene.cpp
// example12-1
//
// Created by shuoquan man on 12-10-13.
// Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "GameMenuScene.h"
#include "GameScene.h"
#include "GameAboutScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameMenu::scene()
{
	CCScene *scene=CCScene::create();
	GameMenu *layer=GameMenu::create();
	scene->addChild(layer);
	return scene;
}
bool GameMenu::init()
{
	if(!CCLayer::init())
	{
		return false;
	}
	CCSize size=CCDirector::sharedDirector()->getWinSize();

	//初始化背景
	CCSprite *bg=CCSprite::create("MainMenu.png");
	bg->setScale(0.5);
	bg->setPosition(ccp(size.width/2,size.height/2));
	addChild(bg,0,0);
	//初始化按钮
	CCMenuItemImage *newGame=CCMenuItemImage::create("newgameA.png","newgameB.png",this,menu_selector(GameMenu::menuNewGameCallback));
	newGame->setScale(0.5);
	newGame->setPosition(ccp(size.width/2,size.height/2-20));
	newGame->setEnabled(false);
	CCMenuItemImage *continueGame=CCMenuItemImage::create("continueA.png","continueB.png",this,menu_selector(GameMenu::menuContinueCallback));
	continueGame->setScale(0.5);
	continueGame->setPosition(ccp(size.width/2,size.height/2-80));
	continueGame->setEnabled(false);
	CCMenuItemImage *about=CCMenuItemImage::create("aboutA.png","aboutB.png",this,menu_selector(GameMenu::menuAboutCallback));
	about->setScale(0.5);
	about->setPosition(ccp(size.width/2,size.height/2-140));
	about->setEnabled(false);
	soundItem=CCMenuItemImage::create("sound-on-A.png","sound-on-B.png",this,menu_selector(GameMenu::menuSoundCallback));
	soundItem->setScale(0.5);
	soundItem->setPosition(ccp(40,40));
	soundItem->setEnabled(false);
	//使用按钮创建菜单
	CCMenu *mainmenu=CCMenu::create(newGame,continueGame,about,soundItem,NULL);
	mainmenu->setPosition(ccp(0,0));
	this->addChild(mainmenu,1,3);
	//初始化声音
	issound=true;
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("background.mp3");
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3",true);
	return true;
}
void GameMenu::onEnter()
{
	CCLayer::onEnter();
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	//界面进入时，运行菜单项
	CCNode *mainmenu=this->getChildByTag(3);
	mainmenu->runAction(CCCallFuncN::create(this,callfuncN_selector(GameMenu::menuEnter)));
}
void GameMenu::onExit()
{
	CCLayer::onExit();
}

void GameMenu::menuNewGameCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMain::scene());
}
void GameMenu::menuContinueCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMain::scene());
}
void GameMenu::menuAboutCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameAbout::scene());
}
void GameMenu::menuSoundCallback(CCObject* pSender)
{
	if(!issound){
		soundItem->setNormalImage(CCSprite::create("sound-on-A.png"));
		soundItem->setDisabledImage(CCSprite::create("sound-on-B.png"));
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("background.mp3");
		issound = true;
	}else{
		soundItem->setNormalImage(CCSprite::create("sound-off-A.png"));
		soundItem->setDisabledImage(CCSprite::create("sound-off-B.png"));
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		issound = false;
	}

}
void GameMenu::onEnterTransitionDidFinish()
{
}
void GameMenu::onExitTransitionDidStart()
{
}
void GameMenu::menuEnter(CCNode *pSender)
{
	CCNode *mainmenu=this->getChildByTag(3);
	CCArray *temp=mainmenu->getChildren();
	for(int i=0;i<temp->count();++i)
	{
		((CCMenuItemImage *)temp->objectAtIndex(i))->setEnabled(true);
	}
}