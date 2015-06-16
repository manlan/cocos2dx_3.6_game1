#include "HelloWorldScene.h"


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
    
    // 获取节点
    auto t1 = (ui::Text *)(rootNode->getChildByName("t1"));
    t1->setString("t1_t1");

    auto b1 = (ui::Button *)(rootNode->getChildByName("b1"));
    b1->setScale(5);
    b1->setPosition(Vec2(300, 400));
//    b1->addTouchEventListener(CC_CALLBACK_1(HelloWorld::b1Click, this));
    
    b1->addTouchEventListener([=](Ref* pSender,Widget::TouchEventType type){
        // 获得文本框
//        Text* text =static_cast<Text*>(rootNode->getChildByName("Label_2"));
//        text->setScale(2);
        switch (type) {
            case Widget::TouchEventType::BEGAN:
//                text->setString("BEGAN");
                break;
            case Widget::TouchEventType::MOVED:
//                text->setString("MOVED");
                break;
            case Widget::TouchEventType::ENDED:
//                text->setString("ENDED");
                CCLOG("ended");
                break;
            case Widget::TouchEventType::CANCELED:
//                text->setString("CANCELED");
                break;
            default:
                break;
        }
    });
    
    return true;
}

void HelloWorld::b1Click(cocos2d::Ref *ref, ui::TouchEventType touchType)
{
    CCLOG("b1Click");
    
}



