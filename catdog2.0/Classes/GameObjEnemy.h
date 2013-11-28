#ifndef example15_1_GameObjEnemy_h
#define example15_1_GameObjEnemy_h
#include "cocos2d.h"
using namespace cocos2d;

class GameObjEnemy : public CCNode
{
public:
    CCSprite *boom;
    CCSprite *mainbody;
	short type;
    bool islife;

    GameObjEnemy(void);
    virtual ~GameObjEnemy(void);
    virtual void onEnter();
    virtual void onExit();

	void releasebullet(float interval);
    void movestart();
    void restart(CCNode *pSender);
    void setdie();
    void setType(short var);
};


#endif