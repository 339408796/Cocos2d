#include "cocos2d.h"
#include "GameObjHero.h"
using namespace cocos2d;
class GameMain:public CCLayer
{
public:
	CCSprite *blood1;
	CCSprite *blood2;
	CCSprite *blood3;
	CCSprite *bg1;
	CCSprite *bg2;
	CCSprite *gameover;
	//gamemark *gamemark;
	short blood;
	CCArray *bullets;
	CCArray *enemybullets;
	CCArray *enemys;
	bool isreduce;
	bool isover;
	GameObjHero *hero;

	static cocos2d::CCScene *scene();
	virtual bool init();
	//virtual void update(float time);

	void menuBackCallback(CCObject *pSender);
	void releaseenemyBullet(int x,int y);
	void releaseheroBullet(int x,int y);
	bool isCollion(CCPoint p1,CCPoint p2,int w1,int h1,int w2,int h2);
	void setherohurt();
	void resetreduce(float time);

	CREATE_FUNC(GameMain);
};