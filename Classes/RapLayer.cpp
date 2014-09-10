#include "RapLayer.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
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
	removeAllChildren();
	initBG();
	MenuItem* item[12];
	Menu* menu[3];

	for (int i = 0; i < 12; i++){
		item[i] = MenuItemImage::create(StringUtils::format("speach/word_ma%02d_nor.png", i + 1), StringUtils::format("speach/word_ma%02d_pre.png", i + 1), CC_CALLBACK_1(RapLayer::wordMaCallback, this));
		item[i]->setTag(100 + i + 1);
	}
	for (int i = 0; i < 3; i++){
		menu[i] = Menu::create(item[0 + i], item[3 + i], item[6 + i], item[9 + i], NULL);
		menu[i]->alignItemsVertically();
		menu[i]->setPosition(WORD_X + WORD_WIDTH * (i + 0.5), WORD_Y + WORD_HEIGHT * 2);

		this->addChild(menu[i]);
	}
 /* Vector<Sprite*> btns;
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
    }*/
}

void RapLayer::wordCa()
{

	removeAllChildren();
	initBG();
	MenuItem* item[12];
	Menu* menu[3];

	for (int i = 0; i < 12; i++){
		item[i] = MenuItemImage::create(StringUtils::format("speach/word_ca%02d_nor.png", i + 1), StringUtils::format("speach/word_ca%02d_pre.png", i + 1), CC_CALLBACK_1(RapLayer::wordCaCallback, this));
		item[i]->setTag(200 + i + 1);
	}
	for (int i = 0; i < 3; i++){
		menu[i] = Menu::create(item[0 + i], item[3 + i], item[6 + i], item[9 + i], NULL);
		menu[i]->alignItemsVertically();
		menu[i]->setPosition(WORD_X + WORD_WIDTH * (i + 0.5), WORD_Y + WORD_HEIGHT * 2);

		this->addChild(menu[i]);
	}
}

void RapLayer::wordRon()
{
	removeAllChildren();
	initBG();
	MenuItem* item[12];
	Menu* menu[3];

	for (int i = 0; i < 12; i++){
		item[i] = MenuItemImage::create(StringUtils::format("speach/word_ron%02d_nor.png", i + 1), StringUtils::format("speach/word_ron%02d_pre.png", i + 1), CC_CALLBACK_1(RapLayer::wordRonCallback, this));
		item[i]->setTag(300 + i + 1);
	}
	for (int i = 0; i < 3; i++){
		menu[i] = Menu::create(item[0 + i], item[3 + i], item[6 + i], item[9 + i], NULL);
		menu[i]->alignItemsVertically();
		menu[i]->setPosition(WORD_X + WORD_WIDTH * (i + 0.5), WORD_Y + WORD_HEIGHT * 2);

		this->addChild(menu[i]);
	}

}

void RapLayer::wordMaCallback(cocos2d::Ref *pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	int tag = item->getTag() % 100;
	notiGame(StringUtils::format("%d", item->getTag()));
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(StringUtils::format("Sounds/ma_%02d.m4a", tag).c_str());
}


void RapLayer::wordCaCallback(cocos2d::Ref *pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	int tag = item->getTag() % 100;
	notiGame(StringUtils::format("%d", item->getTag()));
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(StringUtils::format("Sounds/ca_%02d.m4a", tag).c_str());
}

void RapLayer::wordRonCallback(cocos2d::Ref *pSender)
{
	MenuItem* item = (MenuItem*)pSender;
	int tag = item->getTag() % 100;
	notiGame(StringUtils::format("%d", item->getTag()));
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(StringUtils::format("Sounds/ron_%02d.m4a", tag).c_str());
}

void RapLayer::notiGame(std::string noti){

	GameScene::ck = false;
	String* notiStr = String::create(noti.c_str());
	NotificationCenter::getInstance()->postNotification("notigame", notiStr);

}