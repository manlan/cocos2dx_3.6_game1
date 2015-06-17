//
// Created by Mac on 15/6/16.
//


#ifndef __CityScene_H_
#define __CityScene_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio::timeline;


class CityScene : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(CityScene);

    // ==
    void Nodes();

    void b1Click(Ref *ref, TouchEventType touchType);

    // == tmx
    void initTMX();
    TMXTiledMap _tileMap;
};


#endif //__CityScene_H_
