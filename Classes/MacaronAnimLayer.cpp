#include "MacaronAnimLayer.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace cocos2d;

// on "init" you need to initialize your instance
bool MacaronAnimLayer::init()
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
    return true;
}

void MacaronAnimLayer::createMacaron(int macaronIndex)
{
    m_spritebatch->removeAllChildren();

    Size size = Director::getInstance()->getVisibleSize();
    Sprite* macaron = Sprite::createWithSpriteFrameName(StringUtils::format("character_anim/macaron%d_1.png", macaronIndex));
     macaron->setScale(0.5f, 0.5f);
    macaron->setAnchorPoint(Point(0.0f, 0.5f));
    macaron->setPosition(0.0f, size.height/2);

    macaronSize = macaron->getBoundingBox().size;
    m_spritebatch->addChild(macaron);

	Vector<SpriteFrame*> animFrames(3);
    for (int i = 1; i <= 3; i++)
    {
        SpriteFrame* frame = m_cache->getSpriteFrameByName(StringUtils::format("macaron%d_%d.png", macaronIndex, i));
        animFrames.pushBack(frame);
    }
	if (macaronIndex == 3)
	{
		SpriteFrame* frame = m_cache->getSpriteFrameByName(StringUtils::format("macaron%d_4.png", macaronIndex));
		animFrames.pushBack(frame);
	}

    Animation* anim = Animation::createWithSpriteFrames(animFrames, 0.2f);
    macaron->runAction(RepeatForever::create(Animate::create(anim)));
	
	//music
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(StringUtils::format("Sounds/backgroundmusic_%d.mp3", macaronIndex).c_str());
}

bool MacaronAnimLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	Point location = touch->getLocation();
    return true;
}

void MacaronAnimLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Point location = touch->getLocation();

	if (location.x > 0 && location.x < macaronSize.width)
	{
		int index = rand() % 2 + 1;
		createMacaron(index);
	}
}
