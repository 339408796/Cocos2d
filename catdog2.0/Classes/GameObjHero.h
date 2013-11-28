#ifndef example15_1_GameObjHero_h
#define example15_1_GameObjHero_h
#include "cocos2d.h"
using namespace cocos2d;
class GameObjHero:public CCNode,public CCTargetedTouchDelegate
{
public:
	CCSprite *lefthand;
	CCSprite *righthand;
	CCPoint offset;
	bool iscontrol;
	
	GameObjHero(void);
	virtual ~GameObjHero(void);
	virtual void onEnter();
	virtual void onExit();
	
	//virtual bool ccTouchBegan(CCTouch *touch);
	//virtual void ccTouchMoved(CCTouch *touch,CCEvent *event);
	//virtual void ccTouchEnded(CCTouch *touch,CCEvent *event);

	bool containsTouchLocation(CCTouch *touch);
	void releasebullet(float interval);
	CCRect rect();
};
#endif