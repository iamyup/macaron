#ifndef _MACARON_LAYER_H_
#define _MACARON_LAYER_H_

#include "cocos2d.h"
USING_NS_CC;

class MacaronLayer : public cocos2d::Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    void menuWhoCallback(Ref* pSender);
    void menuWhatCallback(Ref* pSender);
    void menuDoCallback(Ref* pSender);

    void createMacaronAnim();
    void createMenu();
    void createRapboard();
    void debugLine();
    CREATE_FUNC(MacaronLayer)
private:
    Size menuSize;
    Size animSize;
};

#endif
