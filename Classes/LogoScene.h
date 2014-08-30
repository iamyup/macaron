#ifndef _LOG_SCENE_H_
#define _LOG_SCENE_H_

#include "cocos2d.h"

class LogoScene : public cocos2d::Layer
{
public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(LogoScene)
};

#endif
