#ifndef __MACARON_ANIM_LAYER_H__
#define __MACARON_ANIM_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class MacaronAnimLayer : public cocos2d::LayerColor
{
public:
    static const int GREEN_MACARON = 1;
    static const int RAINBOW_MACARON = 2;

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init(int index);

	// implement the "static create()" method manually
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

    void createMacaron(int macaronIndex);
    static MacaronAnimLayer* create(int macaronIndex)
    {
        MacaronAnimLayer *pRet = new MacaronAnimLayer();
        if (pRet && pRet->init(macaronIndex))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

	//word anim
	void wordMacaronAnim(int tag);
	int macaronNum;
    
	//change
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	bool touchmacaron;

private:
    SpriteBatchNode* m_spritebatch;
    SpriteFrameCache* m_cache;
    Size macaronSize;
};

#endif // __HELLOWORLD_SCENE_H__
