#ifndef __ERASER_SCENE_H__
#define __ERASER_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class EraserScene : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
	// implement the "static node()" method manually
	CREATE_FUNC(EraserScene);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);

	void eraseByBlend();
	void eraseByColorMask();
private:
	cocos2d::CCRenderTexture* pRTex;
	cocos2d::CCDrawNode* pEraser;
};

#endif // __ERASER_SCENE_H__
