#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    virtual bool init();
    static Scene* createScene();
    void menuMaCallback(Ref* pSender);
    void menuKaCallback(Ref* pSender);
    void menuRonCallback(Ref* pSender);

    void createMacaronAnim();
    void createMenu();
    void createRapboard();
    void debugLine();
    CREATE_FUNC(GameScene)
private:
    Size menuSize;
    Size animSize;
};

#endif
