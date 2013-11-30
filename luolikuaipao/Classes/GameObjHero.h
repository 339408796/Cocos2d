#ifndef example16_1_GameObjHero_h
#define example16_1_GameObjHero_h
#include "cocos2d.h"

using namespace cocos2d;

class GameObjHero:public CCNode,public CCTargetedTouchDelegate
{
public:
	GameObjHero(void);
	virtual ~GameObjHero(void);
	virtual void onEnter();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch *touch,CCEvent *event);
	virtual void ccTouchMoved(CCTouch *touch,CCEvent *event);
	virtual void ccTouchEnded(CCTouch *touch,CCEvent *event);

	virtual void touchDelegateRetain();
	virtual void touchDelegateRelease();

	void setState(short var);
	void jumpend(CCNode *sender);
	void hurtend(CCNode *sender);
	CCRect rect();

	bool containsTouchLocation(CCTouch *touch);
	CCSprite *mainsprite;
	CCTexture2D *hurt;
	CCTexture2D *jump;
	CCPoint offset;
	short state;
	bool iscontrol;


};

#endif