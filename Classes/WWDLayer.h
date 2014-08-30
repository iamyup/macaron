#ifndef __WWD_LAYER_H__
#define __WWD_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class WWDLayer : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	int i;
	void WordWho();
	void WordWhat();
	void WordDo();
	void whoEffect(Ref *sender);


	
	CREATE_FUNC(WWDLayer);
};

#endif // __HELLOWORLD_SCENE_H__
