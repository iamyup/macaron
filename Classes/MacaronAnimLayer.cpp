#include "MacaronLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;



	// on "init" you need to initialize your instance
bool MacaronLayer::init()
	{
		//////////////////////////////
		// 1. super init first
		if (!Layer::init())
		{
			return false;
		}
		visibleSize = Director::getInstance()->getVisibleSize();
		origin = Director::getInstance()->getVisibleOrigin();

		

		//change background music, macaron, light
		auto listener = EventListenerTouchOneByOne::create();
		listener->onTouchBegan = CC_CALLBACK_2(MacaronLayer::onTouchBegan, this);
		listener->onTouchEnded = CC_CALLBACK_2(MacaronLayer::onTouchEnded, this);
		Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

		
		MacaronLayer::basicMacaron();


		return true;
	}
void MacaronLayer::basicMacaron(){
	MacaronLayer::removeAllChildren();
	if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);

	basicMa = Sprite::create("Images/macaron2-1.png");
	basicMa->setScale(visibleSize.width / 3.5 / basicMa->getContentSize().width, visibleSize.width / 3.5 / basicMa->getContentSize().width);

	this->addChild(basicMa);
	basicMa->setPosition(visibleSize.width / 2.85, visibleSize.height / 2);
			
	auto animMa = CCAnimation::create();
	animMa->setDelayPerUnit(0.3);
	animMa->addSpriteFrameWithFileName("Images/macaron2-1.png");
	animMa->addSpriteFrameWithFileName("Images/macaron2-2.png");
	animMa->addSpriteFrameWithFileName("Images/macaron2-3.png");
	
	auto anim = CCAnimate::create(animMa);
	auto animfor = CCRepeatForever::create(anim);
	basicMa->runAction(animfor);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/Akashic_Records_-_Gangsta_Hip_Hop_Loop.mp3");

}

void MacaronLayer::rainbowMacaron(){
	MacaronLayer::removeAllChildren();
	if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);


	rainbow = Sprite::create("Images/macaron1-1.png");
	rainbow->setScale(visibleSize.width / 3.5 / rainbow->getContentSize().width, visibleSize.width / 3.5 / rainbow->getContentSize().width);

	this->addChild(rainbow);
	rainbow->setPosition(visibleSize.width / 2.85, visibleSize.height / 2);

	auto animMa = CCAnimation::create();
	animMa->setDelayPerUnit(0.3);
	animMa->addSpriteFrameWithFileName("Images/macaron1-1.png");
	animMa->addSpriteFrameWithFileName("Images/macaron1-2.png");
	animMa->addSpriteFrameWithFileName("Images/macaron1-3.png");

	auto anim = CCAnimate::create(animMa);
	auto animfor = CCRepeatForever::create(anim);
	
	rainbow->runAction(animfor);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/Akashic_Records_-_Optimistic.mp3");
}
bool MacaronLayer::onTouchBegan(Touch *touch, Event *unused_event){
	Point location = touch->getLocation();
	touchst = location.x;
	if (touchst > (visibleSize.width / 3 - basicMa->getContentSize().width / 2) && touchst < (visibleSize.width / 3 + basicMa->getContentSize().width / 2))
		return true;
	else
		return false;
}

void MacaronLayer::onTouchEnded(Touch *touch, Event *unused_event){
	Point location = touch->getLocation();
	touchen = location.x;
	float t = touchst - touchen;
	float s = visibleSize.width / 4;
	int i = rand()%2;
	if ((t < -s) || (t>s))
		switch (i){

		case 0 : 
			MacaronLayer::basicMacaron();
			break;
		case 1 : 
			MacaronLayer::rainbowMacaron();
			break;

	}


}