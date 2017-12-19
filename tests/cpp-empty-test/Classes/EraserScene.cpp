#include "EraserScene.h"

USING_NS_CC;

Scene* EraserScene::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    EraserScene *layer = EraserScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EraserScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	this->setTouchMode(kCCTouchesOneByOne);
	this->setTouchEnabled(true);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    MenuItemImage *pCloseItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(EraserScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto pMenu = Menu::create(pCloseItem, NULL);
    pMenu->setPosition(0, 0);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

	Point center = ccp(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
    Sprite* pSprite = Sprite::create("HelloWorld.png");
    pSprite->setPosition(center);
    this->addChild(pSprite, 0);

	pEraser = DrawNode::create();
	pEraser->drawDot(ccp(0, 0), 5, ccc4f(0, 0, 0, 0));
	pEraser->retain();

	pRTex = RenderTexture::create(visibleSize.width, visibleSize.height);
	pRTex->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	this->addChild(pRTex, 10);

	Sprite* pBg = Sprite::create("dirt.png");
	pBg->setAnchorPoint(ccp(0.5,0.5));
	pBg->setPosition(center);
	pRTex->begin();
	pBg->visit();
	pRTex->end();
	
    return true;
}

bool EraserScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void EraserScene::onTouchMoved(Touch *touch, Event *unused_event)
{
	CCPoint touchPoint = touch->getLocation();

	pEraser->setPosition(touchPoint);
	eraseByBlend();
	//eraseByColorMask();

	//CCLOG("(%f, %f)", touchPoint.x, touchPoint.y);
}

void EraserScene::eraseByBlend()
{
	ccBlendFunc blendFunc = { GL_ONE, GL_ZERO };
	pEraser->setBlendFunc(blendFunc);
	pRTex->begin();
	pEraser->visit();
	pRTex->end();
}

void EraserScene::eraseByColorMask()
{
	//ccBlendFunc blendFunc = { GL_ZERO, GL_ZERO };
	//pEraser->setBlendFunc(blendFunc);
	pRTex->begin();
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_TRUE);
	pEraser->visit();
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	pRTex->end();
}

void EraserScene::menuCloseCallback(CCObject* pSender)
{
	CC_SAFE_RELEASE(pEraser);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
