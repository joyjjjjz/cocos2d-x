//
//  MyScrollView.h
//  MyScrollView
//
//  Created by Tom on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ScrollView_ScrollView_h
#define ScrollView_ScrollView_h

#include "cocos2d.h"

USING_NS_CC;

const float WINDOW_WIDTH = 480.0f;
const float WINDOW_HEIGHT = 320.0f;

// 触摸误差
const int TOUCH_DELTA = 5;

class MyScrollView: public Layer
{
private:
    Vec2 m_TouchDownPoint;
    Vec2 m_TouchUpPoint;
    Vec2 m_TouchCurPoint;
    
private:
    int m_Page;
    int m_CurPage;
    
private:
    __Array *m_PageLayer;
    
private:
    void goToPage();
    
public:
    MyScrollView();
    ~MyScrollView();
    
    virtual bool init();
    
    CREATE_FUNC(MyScrollView);

public:
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
    
	void addPage2(cocos2d::Layer *pPageLayer);
};

#endif
