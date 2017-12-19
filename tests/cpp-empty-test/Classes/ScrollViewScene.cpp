//
//  ScrollViewScene.cpp
//  MyScrollView
//
//  Created by Tom on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "ScrollViewScene.h"
#include "MyScrollView.h"
#include "TestLayer.h"

ScrollViewScene::ScrollViewScene()
{
}

ScrollViewScene::~ScrollViewScene()
{
}

bool ScrollViewScene::init()
{
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCScene::init());
		setContentSize(Size(200, 200));
		setColor(Color3B(rand() % 255, rand() % 255, rand() % 255));

		MyScrollView *scrollView = MyScrollView::create();
		Size winSize = Director::getInstance()->getWinSize();
		for (int i=0; i<10; ++i) {
			cocos2d::Layer *layer = TestLayer::create();
			layer->setAnchorPoint(Vec2());
			layer->setTag(i);
			scrollView->addPage2(layer);
		}

		this->addChild(scrollView);

		bRet = true;
	} while (0);

	return bRet;
}