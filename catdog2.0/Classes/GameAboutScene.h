#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class GameAbout : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();

    virtual bool init();  
	virtual void onEnter();
	virtual void onExit();
    
    void menuEnter(CCNode* pSender);
    void menuBackCallback(CCObject* pSender);
    
    CREATE_FUNC(GameAbout);
};

#endif // __HELLOWORLD_SCENE_H__
