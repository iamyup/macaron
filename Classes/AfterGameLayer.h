#ifndef __AFTERGAME_LAYER_H__
#define __AFTERGAME_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class AfterGameLayer : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	void setCenterImage();
	void setMenuRight();

	
	CREATE_FUNC(AfterGameLayer);
};

#endif // __AFTERGAME_LAYER_H__
