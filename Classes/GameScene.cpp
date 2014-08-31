#include "GameScene.h"
#include "MacaronAnimLayer.h"
#include "RapLayer.h"

bool GameScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    createMenu();
    createMacaronAnim();
    createRapboard();

    debugLine();
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
    
}

void GameScene::menuKaCallback(Ref* pSender)
{
    
}

void GameScene::menuRonCallback(Ref* pSender)
{
    
}

#define MENU_X 100.0f
#define ANIM_X 220.5f
#define RAP_X 564.5f
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
    auto anim = MacaronAnimLayer::create();
    anim->createMacaron(MacaronAnimLayer::GREEN_MACARON);
    anim->setPosition(ANIM_X, 0.0f);
    animSize = anim->getBoundingBox().size;
    addChild(anim);
}

void GameScene::createRapboard()
{
    auto rap = RapLayer::create();
    rap->setPosition(RAP_X, 0.0f);
    addChild(rap);
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
