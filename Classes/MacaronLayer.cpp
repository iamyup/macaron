#include "MacaronLayer.h"

bool MacaronLayer::init()
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

Scene* MacaronLayer::createScene()
{
    Scene* pScene = Scene::create();
    MacaronLayer* pLayer = MacaronLayer::create();

    pScene->addChild(pLayer);
    
    return pScene;
}


void MacaronLayer::menuWhoCallback(Ref* pSender)
{
    
}

void MacaronLayer::menuWhatCallback(Ref* pSender)
{
    
}

void MacaronLayer::menuDoCallback(Ref* pSender)
{
    
}
#define MENU_X 100.0f
#define ANIM_OFFSET 50.0f
#define RAP_OFFSET 50.0f
void MacaronLayer::createMenu()
{
    Size winSize = Director::getInstance()->getWinSize();
    
    MenuItem* menuWho = MenuItemImage::create("btn_who_nor.png", "btn_who_sel.png", CC_CALLBACK_1(MacaronLayer::menuWhoCallback, this));
    MenuItem* menuWhat = MenuItemImage::create("btn_what_nor.png", "btn_what_sel.png", CC_CALLBACK_1(MacaronLayer::menuWhatCallback, this));
    MenuItem* menuDo = MenuItemImage::create("btn_do_nor.png", "btn_do_sel.png", CC_CALLBACK_1(MacaronLayer::menuDoCallback, this));
    
    menuSize = menuWho->getContentSize();

    Menu* pMenu = Menu::create(menuWho, menuWhat, menuDo, NULL);
    pMenu->alignItemsVerticallyWithPadding(100.0f);
    pMenu->setPosition(Point(MENU_X, winSize.height/2));
    addChild(pMenu, 1);
}

void MacaronLayer::createMacaronAnim()
{
    Size winSize = Director::getInstance()->getWinSize();
    SpriteBatchNode* spritebatch = SpriteBatchNode::create("anim/macaron.png");
    
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("anim/macaron.plist");
    
    Sprite* macaron = Sprite::createWithSpriteFrameName("macaron1-1.png");
    macaron->setScale(0.5f, 0.5f);
    animSize = macaron->getBoundingBox().size;
    macaron->setAnchorPoint(Point(0.0f, 0.5f));
    macaron->setPosition(MENU_X+menuSize.width/2+ANIM_OFFSET, winSize.height/2);
    spritebatch->addChild(macaron);
    addChild(spritebatch);
    
    
    Vector<SpriteFrame*> animFrames(3);
    for (int i = 1; i <= 3; i++)
    {
        SpriteFrame* frame = cache->getSpriteFrameByName(StringUtils::format("macaron1-%d.png", i));
        animFrames.pushBack(frame);
    }
    
    Animation* anim = Animation::createWithSpriteFrames(animFrames, 0.2f);
    macaron->runAction(RepeatForever::create(Animate::create(anim)));
}

void MacaronLayer::createRapboard()
{
    float bg_x = MENU_X+menuSize.width/2+ANIM_OFFSET+animSize.width+RAP_OFFSET;
    Size winSize = Director::getInstance()->getWinSize();
    Sprite* img = Sprite::create("img_speack_bubble.png");
    img->setAnchorPoint(Point(0.0f, 0.5f));
    img->setPosition(bg_x, winSize.height/2);
    addChild(img);

    Vector<Sprite*> btns;
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            Sprite* img = Sprite::create(StringUtils::format("btn_who_%02d", i*3+j));
//            img->setPosition(winSize.width/2, winSize.height/2+20
//            addChild(img);
        }
    }
}

void MacaronLayer::debugLine()
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

//
//    auto menuNode = DrawNode::create();
//    Vec2 menuRect[] =
//    {
//        Vec2(0,
//    }
}
