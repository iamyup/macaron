#include "RapLayer.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

#define WORD_X 76
#define WORD_Y 120
#define WORD_WIDTH 150
#define WORD_HEIGHT 120


// on "init" you need to initialize your instance
bool RapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
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
    Sprite* img = Sprite::create("speach/img_speack_bubble.png");
    img->setAnchorPoint(Point(0.0f, 0.5f));
    img->setPosition(0, size.height/2);
    addChild(img);
}

void RapLayer::wordMa()
{
    Vector<Sprite*> btns;
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            MenuItem* word = MenuItemImage::create(StringUtils::format("speach/word_ma%02d_nor.png", i*3+(j+1)), StringUtils::format("speach/word_ma%02d_pre.png", i*3+(j+1)), CC_CALLBACK_1(RapLayer::wordMaCallback, this));
            //            img->setPosition(winSize.width/2, winSize.height/2+20
            word->setAnchorPoint(Point(0.0f, 0.0f));
            word->setPosition(WORD_X + WORD_WIDTH * j, WORD_Y + WORD_HEIGHT * i);
            addChild(word);
        }
    }
}

void RapLayer::wordKa()
{


}

void RapLayer::wordRon()
{

}

void RapLayer::wordMaCallback(cocos2d::Ref *pSender)
{
    CCLOG("=====================wordMaCallback======================");
}

void RapLayer::whoEffect(Ref *sender){
    MenuItem* item = (MenuItem*)sender;
    int tag = item->getTag();
    CCLOG("=====================whoEffect======================%d", tag);
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(StringUtils::format("Sounds/%02d.mp3", tag).c_str());
}