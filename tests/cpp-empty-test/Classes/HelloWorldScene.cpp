#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "cocos/ui/UIScrollView.h"
#include "cocos/ui/UIText.h"
#include "cocos/ui/UIListView.h"

USING_NS_CC;
using namespace ui;


Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                    "CloseNormal.png",
    //                                    "CloseSelected.png",
    //                                    CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    //
    //closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));

    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, nullptr);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...

     //add a label shows "Hello World"
     //create and initialize a label
    
    //auto label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    //
    //// position the label on the center of the screen
    //label->setPosition(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height);

    //// add the label as a child to this layer
    //this->addChild(label, 1);

	this->listViewTest();
	//this->scrollViewTest();
	//this->spriteTest();
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


USING_NS_CC;
ui::Text* allocText(const std::string &text)
{
	auto textWidget = ui::Text::create();
	textWidget->setText(text);
	textWidget->setFontName("Marker Felt");
	textWidget->setFontSize(30);
	textWidget->setColor(Color3B(159, 168, 176));

	return textWidget;
}

void HelloWorld::listViewTest()
{
	ui::ListView* listView = ui::ListView::create();
	//SCROLLVIEW_DIR_VERTICAL  SCROLLVIEW_DIR_HORIZONTAL   
	//listView->setDirection(ui::SCROLLVIEW_DIR_VERTICAL);
	listView->setTouchEnabled(true);
	//listView->setBounceEnabled(true);
	//listView->setBackGroundImage("green_edit.png");
	//listView->setBackGroundImageScale9Enabled(true);
	listView->setSize(Size(480, 260));
	//listView->setPosition(Point(widgetSize.width / 2.0f, widgetSize.height / 2.0f));
	//listView->addEventListenerListView(this, listvieweventselector(LayoutTest::selectedItemEvent));

	for (int i=0; i<20; i++)
	{
		auto textWidget = allocText("listview ......" + std::to_string(i));
		listView->addChild(textWidget);
	}
	addChild(listView);
}

void HelloWorld::scrollViewTest()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size scollFrameSize = Size(visibleSize.width - 30.f, visibleSize.height - 10.f);
	auto scrollView = ui::ScrollView::create();
	scrollView->setContentSize(scollFrameSize);

	auto containerSize = Size(scollFrameSize.width, scollFrameSize.height*2);
	scrollView->setInnerContainerSize(containerSize);

	scrollView->setLayoutType(Layout::Type::VERTICAL);

	for (int i = 0; i < 20; i++) {
		auto textWidget = allocText("Hello......" + std::to_string(i));
		scrollView->addChild(textWidget);
	}
	addChild(scrollView);
	//scrollView->scrollToBottom(100, true);
}

void HelloWorld::spriteTest()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *sp = Sprite::create("HelloWorld.png");
	sp->setPosition(Point(visibleSize.width * .5, visibleSize.height * .5));
	this->addChild(sp, 1);
};