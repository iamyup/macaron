#include "MacaronAnimLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

// on "init" you need to initialize your instance
bool MacaronAnimLayer::init(int index)
{
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) // for debug
    {
        return false;
    }

    //change background music, macaron, light
    auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(MacaronAnimLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(MacaronAnimLayer::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);


    m_spritebatch = SpriteBatchNode::create("character_anim/macaron.png");
    m_cache = SpriteFrameCache::getInstance();
    m_cache->addSpriteFramesWithFile("character_anim/macaron.plist");
    addChild(m_spritebatch);

    createMacaron(index);
    return true;
}

void MacaronAnimLayer::createMacaron(int macaronIndex)
{
	macaronNum = macaronIndex;
 /*   m_spritebatch->removeAllChildren();

    Size size = Director::getInstance()->getVisibleSize();
    Sprite* macaron = Sprite::createWithSpriteFrameName(StringUtils::format("macaron%d-1.png", macaronIndex));
     macaron->setScale(0.5f, 0.5f);
    macaron->setAnchorPoint(Point(0.0f, 0.5f));
    macaron->setPosition(0.0f, size.height/2);

    macaronSize = macaron->getBoundingBox().size;
    m_spritebatch->addChild(macaron);

	Vector<SpriteFrame*> animFrames(4);
    for (int i = 1; i <= 3; i++)
    {
        SpriteFrame* frame = m_cache->getSpriteFrameByName(StringUtils::format("macaron%d-%d.png", macaronIndex, i));
        animFrames.pushBack(frame);
    }
	if (macaronIndex == 3)
	{
		SpriteFrame* frame = m_cache->getSpriteFrameByName(StringUtils::format("macaron%d-4.png", macaronIndex));
		animFrames.pushBack(frame);
	}

    Animation* anim = Animation::createWithSpriteFrames(animFrames, 0.2f);
    macaron->runAction(RepeatForever::create(Animate::create(anim)));
	*/
	if (getChildByTag(2) != NULL)
		removeChildByTag(2);
	if (getChildByTag(1) != NULL){
		removeChildByTag(1);
		removeChildByTag(8);

	}

	//macaron
	Size size = Director::getInstance()->getVisibleSize();
	auto macaron = Sprite::create(StringUtils::format("character_anim/macaron%d_1.png", macaronIndex));
	macaron->setScale(0.5f, 0.5f);
	macaron->setAnchorPoint(Point(0.0f, 0.5f));
	macaron->setPosition(0.0f, size.height / 2);
	macaronSize = macaron->getBoundingBox().size;
	this->addChild(macaron);
	macaron->setTag(1);

	//basic animatioin
	auto animMa = CCAnimation::create();
	animMa->setDelayPerUnit(0.3);
	for (int i = 0; i < 3; i++)
		animMa->addSpriteFrameWithFileName(StringUtils::format("character_anim/macaron%d_%d.png", macaronIndex, i + 1));
	if (macaronIndex == 3)
		animMa->addSpriteFrameWithFileName(StringUtils::format("character_anim/macaron%d_4.png", macaronIndex));
	auto anim = CCAnimate::create(animMa);
	auto animfor = CCRepeatForever::create(anim);
	animfor->setTag(5);
	auto del = DelayTime::create(10.0);
	auto squ = Sequence::create(del, CCRepeatForever::create(anim), NULL);
	macaron->runAction(animfor);

	//light
	Sprite* light = Sprite::create(StringUtils::format("light_anim/img_light%d_01.png", macaronIndex));
	auto animLi = CCAnimation::create();
	animLi->setDelayPerUnit(0.4);
	animLi->addSpriteFrameWithFileName(StringUtils::format("light_anim/img_light%d_01.png", macaronIndex));
	animLi->addSpriteFrameWithFileName(StringUtils::format("light_anim/img_light%d_02.png", macaronIndex));
	auto animL = CCAnimate::create(animLi);
	auto animLfor = CCRepeatForever::create(animL);
	light->runAction(animLfor);
	light->setAnchorPoint(Point(-0.2f, 1.0f));
	light->setPosition(0.0f, size.height);
	this->addChild(light);
	light->setTag(8);

	//music
	if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(StringUtils::format("Sounds/backgroundmusic_%d.mp3", macaronIndex).c_str(),true);
}

void MacaronAnimLayer::wordMacaronAnim(int tag){

	CCLog("11111111111111111111111111111111word_anim/word_ani_%d_%d_%02d_1.png", macaronNum, tag / 100, tag % 100);

	bool act = false;
	switch (macaronNum)
	{
	case 1:
		if ((tag == 208) || (tag == 212) || (tag == 303) || (tag == 308))
			act = true;
		break;
	case 2:
		if ((tag == 209) || (tag == 212) || (tag == 301) || (tag == 308))
			act = true;
		break;
	case 3:
		if ((tag == 103) || (tag == 204) || (tag == 210))
			act = true;
		break;
	default:
		break;
	}

	if (act){
		getChildByTag(1)->setVisible(false);
		if (getChildByTag(2) != NULL)
			removeChildByTag(2);
		Size size = Director::getInstance()->getVisibleSize();
		Sprite* macaron = Sprite::create(StringUtils::format("word_anim/word_ani_%d_%d_%02d_1.png", macaronNum, tag / 100, tag % 100));
		macaron->setScale(0.5f, 0.5f);
		macaron->setAnchorPoint(Point(0.0f, 0.5f));
		macaron->setPosition(0.0f, size.height / 2);
		MacaronAnimLayer::addChild(macaron);
		macaron->setTag(2);

		//basic animatioin
		auto animMa = CCAnimation::create();
		animMa->setDelayPerUnit(0.4);
		animMa->addSpriteFrameWithFileName(StringUtils::format("word_anim/word_ani_%d_%d_%02d_1.png", macaronNum, tag / 100, tag % 100));
		animMa->addSpriteFrameWithFileName(StringUtils::format("word_anim/word_ani_%d_%d_%02d_2.png", macaronNum, tag / 100, tag % 100));
		auto anim = CCAnimate::create(animMa);

		macaron->runAction(anim);
		unschedule(schedule_selector(MacaronAnimLayer::wordSchedule));
		this->schedule(schedule_selector(MacaronAnimLayer::wordSchedule), 0.9f);




	}
}
void MacaronAnimLayer::wordSchedule(float delta){
	removeChildByTag(2);
	getChildByTag(1)->setVisible(true);

}

bool MacaronAnimLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    return true;
}

void MacaronAnimLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Point location = touch->getLocation();

	int position = 400;

	float loc = location.x - position + macaronSize.width / 2;
	if ((loc > 0) && (loc < macaronSize.width))
	{
		int index = rand() % 3 + 1;
		createMacaron(index);
	}
}

