#include "AfterGameLayer.h"
#include "SimpleAudioEngine.h"

//USING_NS_CC;
//using namespace cocos2d;

using namespace cocos2d;


	// on "init" you need to initialize your instance
bool AfterGameLayer::init()
{
		//////////////////////////////
		// 1. super init first
		if (!Layer::init())
		{
			return false;
		}
		visibleSize = Director::getInstance()->getVisibleSize();
		origin = Director::getInstance()->getVisibleOrigin();
		AfterGameLayer::setCenterImage();
		AfterGameLayer::setMenuRight();

		

		return true;
}

void AfterGameLayer::setCenterImage(){

	auto light = Sprite::create("Images/img_light1_01.png");
	light->setScale(visibleSize.width / 6.2 / light->getContentSize().width, visibleSize.width / 6.2 / light->getContentSize().width);
	auto macaron = Sprite::create("Images/macaron2-1.png");
	macaron->setScale(visibleSize.width / 3.5 / macaron->getContentSize().width, visibleSize.width / 3.5 / macaron->getContentSize().width);
	auto play = Sprite::create("Images/btn_play_pre.png");
	play->setScale((visibleSize.width / 14) / play->getContentSize().width, (visibleSize.width / 14) / play->getContentSize().width);

	this->addChild(light);
	light->setPosition(visibleSize.width / 3, visibleSize.height - (visibleSize.width / 6.2 / 2));
	this->addChild(macaron);
	macaron->setPosition(visibleSize.width / 3, visibleSize.height / 2);

	auto item = MenuItemSprite::create(play, play, NULL);
	auto menu = Menu::create(item, NULL);
	this->addChild(menu);

	menu->setPosition(visibleSize.width / 3, visibleSize.height / 8);


}
void AfterGameLayer::setMenuRight(){
	auto bubble = Sprite::create("Images/img_speack_bubble.png");
	bubble->setScale(visibleSize.width / 2.2 / bubble->getContentSize().width, visibleSize.width / 2 / bubble->getContentSize().width);
	bubble->setPosition(visibleSize.width / 1.35, visibleSize.height / 2);

	auto retry_nor = Sprite::create("Images/btn_retry_nor.png");
	retry_nor->setScale(visibleSize.width / 7.5 / retry_nor->getContentSize().width, visibleSize.width / 7.5 / retry_nor->getContentSize().width);
	auto retry_pre = Sprite::create("Images/btn_retry_pre.png");
	retry_pre->setScale(visibleSize.width / 7.5 / retry_pre->getContentSize().width, visibleSize.width / 7.5 / retry_pre->getContentSize().width);
	auto save_nor = Sprite::create("Images/btn_save_nor.png");
	save_nor->setScale(visibleSize.width / 7.5 / save_nor->getContentSize().width, visibleSize.width / 7.5 / save_nor->getContentSize().width);
	auto save_pre = Sprite::create("Images/btn_save_pre.png");
	save_pre->setScale(visibleSize.width / 7.5 / save_pre->getContentSize().width, visibleSize.width / 7.5 / save_pre->getContentSize().width);
	auto share_nor = Sprite::create("Images/btn_share_nor.png");
	share_nor->setScale(visibleSize.width / 7.5 / share_nor->getContentSize().width, visibleSize.width / 7.5 / share_nor->getContentSize().width);
	auto share_pre = Sprite::create("Images/btn_share_pre.png");
	share_pre->setScale(visibleSize.width / 7.5 / share_pre->getContentSize().width, visibleSize.width / 7.5 / share_pre->getContentSize().width);
	
	auto item_retry = MenuItemSprite::create(retry_nor, retry_pre );
	auto item_save = MenuItemSprite::create(save_nor, save_pre, NULL);
	auto item_share = MenuItemSprite::create(share_nor, share_pre, NULL);

	auto menu = Menu::create(item_retry, item_save, item_share, NULL);
	menu->alignItemsVertically();
	menu->setPosition(visibleSize.width / 1.3, visibleSize.height / 2);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 8.5);

	this->addChild(bubble);
	this->addChild(menu);


}

