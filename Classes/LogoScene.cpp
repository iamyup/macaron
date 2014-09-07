#include "LogoScene.h"
#include "GameScene.h"
USING_NS_CC;

bool LogoScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Size winSize = Director::getInstance()->getWinSize();
	Sprite* pBackgroundSprite = Sprite::create("img_logo.png");
	pBackgroundSprite->setAnchorPoint(Point(0.5f, 0.0));
	pBackgroundSprite->setPosition(winSize.width / 2, winSize.height / 2 + 200);
	addChild(pBackgroundSprite);

	SpriteBatchNode* spritebatch = SpriteBatchNode::create("character_anim/macaron.png");

	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("character_anim/macaron.plist");

	Sprite* macaron = Sprite::createWithSpriteFrameName("macaron1-1.png");
	macaron->setAnchorPoint(Point(0.0f, 0.0f));
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
	
	//background
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sounds/backgroundmusic_1.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sounds/backgroundmusic_2.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Sounds/backgroundmusic_3.mp3");


    schedule(schedule_selector(LogoScene::replaceScene), 1.0f);
    return true;
}

Scene* LogoScene::createScene()
{
    Scene* pScene = Scene::create();
    LogoScene* pLayer = LogoScene::create();

    pScene->addChild(pLayer);
    
    return pScene;
}

void LogoScene::replaceScene(float dt)
{
    auto newScene = GameScene::createScene();
    auto transition = TransitionFade::create(1.0f, newScene);
    Director::getInstance()->replaceScene(transition);
}