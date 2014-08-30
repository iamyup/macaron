#ifndef __MACARON_ANIM_LAYER_H__
#define __MACARON_ANIM_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class MacaronAnimLayer : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	void basicMacaron();

	cocos2d::Sprite* basicMa;
	
	void rainbowMacaron();
	cocos2d::Sprite* rainbow;
	
	//change
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	float touchst, touchen;
	
	CREATE_FUNC(MacaronAnimLayer);
};

#endif // __HELLOWORLD_SCENE_H__
