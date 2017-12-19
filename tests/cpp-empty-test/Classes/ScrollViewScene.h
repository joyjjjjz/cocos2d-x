//
//  ScrollViewScene.h
//  ScrollView
//
//  Created by Tom on 12-6-4.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ScrollView_ScrollViewScene_h
#define ScrollView_ScrollViewScene_h

#include "cocos2d.h"

USING_NS_CC;

class ScrollViewScene: public Scene
{

public:
	ScrollViewScene();
	~ScrollViewScene();

	virtual bool init();

	CREATE_FUNC(ScrollViewScene);
};

#endif
