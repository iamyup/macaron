#include "RapLayer.h"
#include "SimpleAudioEngine.h"

//USING_NS_CC;
//using namespace cocos2d;

using namespace cocos2d;


// on "init" you need to initialize your instance
bool RapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(0, 255, 0, 255)))
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    initBG();
    wordMa();
    
    return true;
}

void RapLayer::initBG()
{
    Size size = Director::getInstance()->getVisibleSize();
    Sprite* img = Sprite::create("img_speack_bubble.png");
    img->setAnchorPoint(Point(0.0f, 0.5f));
    img->setPosition(0, size.height/2);
    addChild(img);
}

void RapLayer::wordMa()
{
    Sprite* who[12];
    MenuItem* item[12]; 
    Menu* menu[3];

    for (int i = 0; i < 12; i++){
        who[i] = Sprite::create(StringUtils::format("Images/btn_who_%02d.png",i+1));
        who[i]->setScale(visibleSize.width /11 / who[i]->getContentSize().width, visibleSize.width /11 / who[i]->getContentSize().width);

        item[i] = MenuItemSprite::create(who[i], who[i],CC_CALLBACK_1(RapLayer::whoEffect,this));
        item[i]->setTag(i + 1);
    }
    for (int i = 0; i < 3; i++){
        menu[i] = Menu::create(item[0+i], item[3+i], item[6+i], item[9+i], NULL);

        menu[i]->alignItemsVertically();
        menu[i]->alignItemsVerticallyWithPadding(visibleSize.height / 9);

        menu[i]->setPosition(visibleSize.width / 40 * (25 + i * 5), visibleSize.height / 2);
        
        this->addChild(menu[i]);
    }
}

void RapLayer::wordKa()
{


}

void RapLayer::wordRon()
{

}

void RapLayer::whoEffect(Ref *sender){
    MenuItem* item = (MenuItem*)sender;
    int tag = item->getTag();
    CCLOG("=====================whoEffect======================%d", tag);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(StringUtils::format("Sounds/%02d.mp3", tag).c_str());
}