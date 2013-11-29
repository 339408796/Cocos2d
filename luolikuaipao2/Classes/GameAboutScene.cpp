#include "GameAboutScene.h"
#include "GameMenuScene.h"

using namespace cocos2d;

CCScene *GameAbout::scene()
{
	CCScene *scene=CCScene::create();
	GameAbout *layer=GameAbout::create();
	scene->addChild(layer);
	return scene;
}
bool GameAbout::init()
{
	if(!CCLayer::init())
		return false;

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	//初始化背景
	CCSprite *bg=CCSprite::create("back_1.png");
	bg->setScaleX(0.469);
	bg->setScaleY(0.62);
	bg->setAnchorPoint(ccp(0,0));
	bg->setPosition(ccp(0,0));
	this->addChild(bg,0,0);
	//初始化关于框
	CCSprite *kuang=CCSprite::create("tb.png");
	kuang->setScaleX(0.7);
	kuang->setScaleY(0.35);
	kuang->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(kuang,2,2);
	char inf[256];
    sprintf(inf,"name:meow war\n\nprogram:shuoquan man\n\nart design:peng xu\n\ncompany:hz books\n\n    powered by cocos2D-x");
	CCLabelTTF * myjineng = CCLabelTTF::create(inf,"Marker Felt",40,CCSizeMake(400,400),kCCTextAlignmentLeft);
	myjineng->setAnchorPoint(ccp(0,1));
	myjineng->setColor(ccc3(200,200,200));
	myjineng->setPosition(ccp(50,600));
	kuang->addChild(myjineng);
	//初始化关于标题
	CCSprite *abouttitle=CCSprite::create("about.png");
	abouttitle->setScale(0.5);
	abouttitle->setPosition(ccp(size.width/2, size.height - 45));
	this->addChild(abouttitle,3,3);
	//初始化返回按钮
	CCMenuItemImage *back=CCMenuItemImage::create("backA.png","backB.png",this,menu_selector(GameAbout::menuBackCallback));
	back->setScale(0.5);
	back->setPosition(ccp(size.width-20,size.height-45));
	back->setEnabled(false);
	CCMenu *mainmenu=CCMenu::create(back,NULL);
	mainmenu->setPosition(ccp(0,0));
	this->addChild(mainmenu,3,4);
	return true;

}

void GameAbout::onEnter()
{
	CCLayer::onEnter();
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCNode *mainmenu=this->getChildByTag(4);
	mainmenu->runAction(CCCallFuncN::create(this,callfuncN_selector(GameAbout::menuEnter)));
}

void GameAbout::onExit()
{
	CCLayer::onExit();
}

void GameAbout::menuBackCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
}

void GameAbout::menuEnter(CCNode *pSender)
{
	CCNode* mainmenu = this->getChildByTag(4);
    CCArray* temp = mainmenu->getChildren();
    ((CCMenuItemImage *)temp->objectAtIndex(0))->setEnabled(true);
}