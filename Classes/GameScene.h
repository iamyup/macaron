#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include "KamCordInt.h"
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
    void createYo();
    void debugLine();
	CREATE_FUNC(GameScene);

	//back key
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	bool checkonemore = false;

private:
    Size menuSize;
    Size animSize;
    KamCordInt m_kamcord;
};

#endif
