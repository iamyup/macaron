#ifndef __RAP_LAYER_H__
#define __RAP_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class RapLayer : public LayerColor
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	Size visibleSize;
	Vec2 origin;

    void initBG();
	void wordMa();
	void wordCa();
	void wordRon();
    void wordMaCallback(Ref* pSender);
<<<<<<< HEAD

	void MaEffect(Ref *sender);
	void CaEffect(Ref *sender);
	void RonEffect(Ref *sender);

=======
    void wordCaCallback(Ref* pSender);
    void wordRonCallback(Ref* pSender);
    
	void whoEffect(Ref *sender);
	
>>>>>>> 1f2cf6f10bf460f25a9b4ccb8d3c26b528da72ae
	CREATE_FUNC(RapLayer);
private:
    int i;
};

#endif
