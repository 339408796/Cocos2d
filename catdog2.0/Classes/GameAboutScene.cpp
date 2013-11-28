#include "GameAboutScene.h"
#include "GameMenuScene.h"
#include "GameObjHero.h"
USING_NS_CC;
using namespace cocos2d;
CCScene* GameAbout::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameAbout *layer = GameAbout::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameAbout::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//��ʼ������
	CCSprite* bg = CCSprite::create("bg.png");
	bg->setScale(0.5);
	bg->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(bg,0,0);
	//��ʼ������
	CCSprite *bgstar=CCSprite::create("moon.png");
	bgstar->setAnchorPoint(ccp(0.5,0));
	bgstar->setScale(0.5);
	bgstar->setPosition(ccp((visibleSize.width/2+origin.x)/3*1,0));
	this->addChild(bgstar,1,1);
	//��ʼ��about��
	CCSprite *aboutKuang=CCSprite::create("tb.png");
	aboutKuang->setScale(0.5);
	aboutKuang->setPosition(ccp(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y));
	this->addChild(aboutKuang,2,2);
	//��ʼ����������
	char inf[256];
	sprintf(inf,"name:catdog war\n\nprogram:hyc man\n\nart design:hyc\n\ncompany:hyc books\n\n    powered by cocos2D-x");
	CCLabelTTF *content=CCLabelTTF::create(inf,"Marker Felt",40,CCSizeMake(400,400),kCCTextAlignmentLeft);
	content->setAnchorPoint(ccp(0,1));
	content->setColor(ccc3(200,200,200));
	content->setPosition(ccp(50,600));
	aboutKuang->addChild(content);
	//��ʼ������
	CCSprite *aboutTitle=CCSprite::create("about.png");
	aboutTitle->setScale(0.5);
	aboutTitle->setPosition(ccp(visibleSize.width/2+origin.x,visibleSize.height+origin.y-20));
	this->addChild(aboutTitle,3,3);
	//��ʼ�����ذ�ť
	CCMenuItemImage *back=CCMenuItemImage::create("backA.png","backB.png",this,menu_selector(GameAbout::menuBackCallback));
	back->setScale(0.5);
	back->setPosition(ccp(visibleSize.width+origin.x-20,visibleSize.height+origin.y-20));
	back->setEnabled(false);
	CCMenu *mainmenu=CCMenu::create(back,NULL);
	mainmenu->setPosition(ccp(0,0));
	this->addChild(mainmenu,3,4);
	return true;
}


void GameAbout::menuBackCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GameMenu::scene());
}
void GameAbout::onEnter()
{
	CCLayer::onEnter();
    //�������ʱ�����в˵�����붯��
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCNode* mainmenu = this->getChildByTag(4);
    mainmenu->setPositionX(-100);
    mainmenu->runAction(CCSequence::create(CCEaseElasticIn::create(CCMoveBy::create(0.5,ccp(100,0))),CCCallFuncN::create(this, callfuncN_selector(GameAbout::menuEnter)),NULL));
    //���ٶȶ���
    CCNode*title = this->getChildByTag(3);
    title->setPositionY(size.height + 20);
    title->runAction(CCEaseElasticIn::create(CCMoveBy::create(0.5,ccp(0,-40))));
    
    CCNode*bgstar = this->getChildByTag(1);
    bgstar->setPositionX(size.width/3 * 2);
    bgstar->runAction(CCMoveBy::create(0.5,ccp(-size.width/3,0)));
    
    CCNode*kuang = this->getChildByTag(2);
    kuang->setPositionX(-200);
    kuang->runAction(CCEaseElasticIn::create(CCMoveTo::create(0.5,ccp(size.width/2,size.height/2))));
    
}
void GameAbout::onExit()
{
	CCLayer::onExit();
} 
void GameAbout::menuEnter(CCNode* pSender){
    //�˵�����󣬲˵�������Ч
    CCNode* mainmenu = this->getChildByTag(4);
    CCArray* temp = mainmenu->getChildren();
    ((CCMenuItemImage *)temp->objectAtIndex(0))->setEnabled(true);
}