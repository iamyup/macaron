#include "GameScene.h"
#include "MacaronAnimLayer.h"
#include "RapLayer.h"

bool GameScene::ck;

bool GameScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }
	//back key
	this->setKeypadEnabled(true);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    createMenu();
    createMacaronAnim();
    createRapboard();
    createYo();

	this->setKeypadEnabled(true);
	this->setAccelerometerEnabled(true);
	
	//get sign
	NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(GameScene::doNotification), "notigame", NULL);

//    debugLine();
    return true;
}


Scene* GameScene::createScene()
{
    Scene* pScene = Scene::create();
    GameScene* pLayer = GameScene::create();

    pScene->addChild(pLayer);
    
    return pScene;
}

void GameScene::menuMaCallback(Ref* pSender)
{
	RapLayer * raplayer = (RapLayer*)getChildByTag(2);
	raplayer->wordMa();

}

void GameScene::menuKaCallback(Ref* pSender)
{
	RapLayer * raplayer = (RapLayer*)getChildByTag(2);
	raplayer->wordCa();
}

void GameScene::menuRonCallback(Ref* pSender)
{
	RapLayer * raplayer = (RapLayer*)getChildByTag(2);
	raplayer->wordRon();


}
void GameScene::doNotification(CCObject *obj)
{

	CCString *noti = (CCString*)obj;
	Director::getInstance()->resume();
	int tag = noti->intValue();
	if (tag > 0 && (tag < 1000))
		if (!GameScene::ck)
		{
		GameScene::ck = true;
		MacaronAnimLayer* mac = (MacaronAnimLayer*)getChildByTag(1);
		mac->wordMacaronAnim(noti->intValue());
		}


}

#define MENU_X 100.0f
#define ANIM_X 220.5f
#define RAP_X 564.5f
#define YO_X 1120.0f
#define YO_Y 580.0f

void GameScene::createMenu()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    MenuItem* menuMa = MenuItemImage::create("btn_ma_nor.png", "btn_ma_pre.png", CC_CALLBACK_1(GameScene::menuMaCallback, this));
    MenuItem* menuKa = MenuItemImage::create("btn_ca_nor.png", "btn_ca_pre.png", CC_CALLBACK_1(GameScene::menuKaCallback, this));
    MenuItem* menuRon = MenuItemImage::create("btn_ron_nor.png", "btn_ron_pre.png", CC_CALLBACK_1(GameScene::menuRonCallback, this));
    
    menuSize = menuMa->getContentSize();

    Menu* pMenu = Menu::create(menuMa, menuKa, menuRon, NULL);
    pMenu->alignItemsVerticallyWithPadding(100.0f);
    pMenu->setPosition(Point(MENU_X, winSize.height/2));
    addChild(pMenu, 1);
}

void GameScene::createMacaronAnim()
{
    auto anim = MacaronAnimLayer::create(MacaronAnimLayer::GREEN_MACARON);
    anim->setPosition(ANIM_X, 0.0f);
    animSize = anim->getBoundingBox().size;
    addChild(anim);
	anim->setTag(1);
}

void GameScene::createRapboard()
{
    auto rap = RapLayer::create();
    rap->setPosition(RAP_X, 0.0f);
    addChild(rap);
	rap->setTag(2);
}

void GameScene::createYo()
{
    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            auto sprite = Sprite::create(StringUtils::format("img_yo_%d.png", (i*2)+j));
            sprite->setAnchorPoint(Point(0.0f, 0.0f));
            sprite->setPosition((YO_X*j), (YO_Y*i));
            addChild(sprite);
        }
    }
}

void GameScene::debugLine()
{
    Size winSize = Director::getInstance()->getWinSize();
    auto winRectNode = DrawNode::create();
    Vec2 winRect[] =
    {
        Vec2(0, winSize.height),
        Vec2(winSize.width, winSize.height),
        Vec2(winSize.width, 0),
        Vec2(0, 0)
    };
    winRectNode->drawPolygon(winRect, 4, Color4F(0,0,0, 0), 3, Color4F(0.2f, 0.2f, 0.2f, 1));
    addChild(winRectNode);

    auto menuStartRectNode = DrawNode::create();
    Vec2 menuStartRect[] =
    {
        Vec2(0, winSize.height),
        Vec2(MENU_X, winSize.height),
        Vec2(MENU_X, 0),
        Vec2(0, 0)
    };
    menuStartRectNode->drawPolygon(menuStartRect, 4, Color4F(0,0,0,0), 3, Color4F(0.2f,0.2f,0.2f,1));
    addChild(menuStartRectNode);

    auto menuRectNode = DrawNode::create();
    Vec2 menuRect[] =
    {
        Vec2(0, winSize.height),
        Vec2(MENU_X+(menuSize.width/2), winSize.height),
        Vec2(MENU_X+(menuSize.width/2), 0),
        Vec2(0, 0)
    };
    menuRectNode->drawPolygon(menuRect, 4, Color4F(0,0,0,0), 3, Color4F(0.2f,0.2f,0.2f,1));
    addChild(menuRectNode);
}

void GameScene::onAcceleration(cocos2d::Acceleration *acc, cocos2d::Event *event)
{
	CCDirector* pDir = CCDirector::sharedDirector();
	float x = acc->x * 9.81f;
	float y = acc->y * 9.81f;
	float z = acc->z * 9.81f;
	if (((x < 1.7) && (x>-1.7)) && (y <1.7) && (y>-1.7)){
		chu = false;
	}

	int s = 4;
	if (!chu ){//&& (z>1)){
		if ((x < -s) && (y > s)){
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/yo_1.m4a");
			yoPopup(1);
			chu = true;
		}if ((x > s) && (y > s)){
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/yo_2.m4a");
			yoPopup(2);
			chu = true;
		}
		if ((x < -s) && (y < -s)){
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/yo_3.m4a");
			yoPopup(3);
			chu = true;
		}
		if ((x > s) && (y < -s)){
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/yo_4.m4a");
			yoPopup(4);
			chu = true;
		}
		
	}
}

void GameScene::yoPopup(int num)
{
	
	switch (num){
	case 1:
		 pop = Sprite::create("popup_01_left_top.png");
		break;
	case 2:
		 pop = Sprite::create("popup_02_right_top.png");
		break;
	case 3:
		pop = Sprite::create("popup_03_left_bottom.png");
		break;
	case 4:
		pop = Sprite::create("popup_04_right_bottom.png");
		break;
	}
	if (pop != NULL)
	{
		Size winSize = Director::getInstance()->getWinSize();

		addChild(pop);
		pop->setAnchorPoint(Vec2(0.5, 0.5));
		pop->setPosition(winSize.width/2,winSize.height/2);
		pop->setScale(0.5, 0.5);
		pop->setTag(4);
		this->schedule(schedule_selector(GameScene::popSchedule), 0.5f);
	}
}
void GameScene::popSchedule(float delta)
{
	if (getChildByTag(4) != NULL)
		this->removeChildByTag(4);
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_BACK) {

		if (GameScene::checkonemore)
			Director::getInstance()->end();
		else
			GameScene::checkonemore = true;
	}
	else
		GameScene::checkonemore = false;
}
