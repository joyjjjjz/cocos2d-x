//
//  TestLayer.h
//  ScrollView
//
//  Created by Tom on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ScrollView_TestLayer_h
#define ScrollView_TestLayer_h

#include "cocos2d.h"

USING_NS_CC;

class TestLayer: public cocos2d::Layer
{
public:
    TestLayer();
    ~TestLayer();
    
    virtual bool init();
    
    CREATE_FUNC(TestLayer);
    
    // 初始化相关
    virtual void onEnter();
    //virtual void onExit();
	virtual void onEnter();
    
    // 触摸事件相关
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent);
};

#endif
