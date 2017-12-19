//
//  TestLayer.cpp
//  ScrollView
//
//  Created by Tom on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "TestLayer.h"

TestLayer::TestLayer()
{
}

TestLayer::~TestLayer()
{
}

bool TestLayer::init()
{
	bool bRet = false;

	do {
		//CC_BREAK_IF(!CCLayerColor::initWithColor(ccc4(rand() % 255, rand() % 255, rand() % 255, 255)));
		Layer::init();

		setColor(Color3B(rand() % 255, rand() % 255, rand() % 255));
		setContentSize(Size(480, 320));

		bRet = true;
	} while (0);

	return bRet;
}

void TestLayer::onEnter()
{
	CCLayer::onEnter();
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

//void TestLayer::onExit()
//{
//	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
//	//CCLayer::onExit();
//}
//
bool TestLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
	CCLOG("I am %d", getTag());

	return true;
}

void TestLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void TestLayer::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void TestLayer::onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

