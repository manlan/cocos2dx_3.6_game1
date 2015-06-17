//
// Created by Mac on 15/6/16.
//

#include "CityScene.h"
#include "HelloWorldScene.h"

Scene *CityScene::createScene() {
    auto scene = Scene::create();
    auto layer = CityScene::create();

    scene->addChild(layer);

    return scene;
}

bool CityScene::init() {
    if (!Layer::init()) {
        return false;
    }

    this->Nodes();
    return true;
};

void CityScene::b1Click(Ref *ref, TouchEventType touchType) {
    CCLOG("CityLayer b1Click");

    auto Hello = HelloWorld::createScene();

//    Director::getInstance()->pushScene(Hello);
//    Director::getInstance()->popScene();
    Director::getInstance()->runWithScene(Hello);

}

void CityScene::Nodes() {
    auto rootNode = CSLoader::createNode("MainScene.csb");
    rootNode->setAnchorPoint(Vec2::ZERO);
    this->addChild(rootNode);

    //获取节点
    auto t1 = (ui::Text *) (rootNode->getChildByName("t1"));
    t1->setString("CityLayer");

    auto b1 = (ui::Button *) (rootNode->getChildByName("b1"));
    b1->setScale(3);
//    b1->setPosition(Vec2::ZERO);
    b1->setPosition(Vec2(100, 200));
    b1->addTouchEventListener(this, toucheventselector(CityScene::b1Click));


}
