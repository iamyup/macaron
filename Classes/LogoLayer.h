#ifndef _LOG_LAYER_H_
#define _LOG_LAYER_H_

#include "cocos2d.h"

class LogoLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(LogoLayer)
};

#endif
