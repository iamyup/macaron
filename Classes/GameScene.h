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
    void createYo();
    void debugLine();
	CREATE_FUNC(GameScene);

	//popup
	void yoPopup(int num);
	Sprite* pop = NULL;
	void popSchedule(float delta);
	int nNum = 0;

	//rap sign
	void doNotification(CCObject *obj);
	static bool ck;

	//back key
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	bool checkonemore = false;

	//acceleration
	virtual void onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event);
	bool chu = false;

private:
    Size menuSize;
    Size animSize;
 
};

#endif
