#include "MyScrollView.h"
#include "TestLayer.h"

MyScrollView::MyScrollView()
{
    m_Page = 0;
    m_CurPage = 0;
    m_PageLayer = __Array::createWithCapacity(5);
    m_PageLayer->retain();
}

MyScrollView::~MyScrollView()
{
    m_PageLayer->removeAllObjects();
    m_PageLayer->release();
}

bool MyScrollView::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
		onEnter();
        bRet = true;
    } while (0);
    
    return bRet;
}

void MyScrollView::onEnter()
{
    CCLayer::onEnter();
    //CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void MyScrollView::onExit()
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool MyScrollView::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    m_TouchDownPoint = Director::getInstance()->convertToGL(pTouch->getLocationInView());
    m_TouchCurPoint = m_TouchDownPoint;
    
    return true;
}

void MyScrollView::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    // 移动
    Vec2 touchPoint = Director::getInstance()->convertToGL(pTouch->getLocationInView());
    Vec2 posPoint = Vec2(getPositionX() + touchPoint.x - m_TouchCurPoint.x, getPositionY());
    setPosition(posPoint);
    m_TouchCurPoint = touchPoint;
}

void MyScrollView::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    m_TouchUpPoint = Director::getInstance()->convertToGL(pTouch->getLocationInView());
    
	// 计算按下和抬起的偏移量
	int offset = (m_TouchUpPoint.x - m_TouchDownPoint.x) * (m_TouchUpPoint.x - m_TouchDownPoint.x) + (m_TouchUpPoint.y - m_TouchDownPoint.y) * (m_TouchUpPoint.y - m_TouchDownPoint.y);
	if (offset < (TOUCH_DELTA * TOUCH_DELTA)) {
		// 点击
		// 向子Layer发送Click消息
		((Layer*) m_PageLayer->objectAtIndex(m_CurPage))->onTouchBegan(pTouch, pEvent);
	}
	else {
		// 滑动结束
		offset = getPositionX() - m_CurPage * (-WINDOW_WIDTH);
		if (offset > WINDOW_WIDTH / 2) {
			// 上一页
			if (m_CurPage > 0) {
				--m_CurPage;
			}
		}
		else if (offset < -WINDOW_WIDTH / 2) {
			// 下一页
			if (m_CurPage < (m_Page - 1)) {
				++m_CurPage;
			}
		}

		// 执行跳转动画
		goToPage();
	}
}

void MyScrollView::onTouchCancelled(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void MyScrollView::goToPage()
{
    MoveTo *moveTo = MoveTo::create(0.2f, Vec2(-m_CurPage * WINDOW_WIDTH, 0));
    this->runAction(moveTo);
}

void MyScrollView::addPage2(cocos2d::Layer *pPageLayer)
{
    if (pPageLayer) {
        // 设置成一页大小
        pPageLayer->setContentSize(CCSizeMake(WINDOW_WIDTH, WINDOW_HEIGHT));
        pPageLayer->setPosition(ccp(WINDOW_WIDTH * m_Page, 0));
        this->addChild(pPageLayer);
        // 添加到页
        m_PageLayer->addObject(pPageLayer);
        m_Page = m_PageLayer->count();
    }
}








