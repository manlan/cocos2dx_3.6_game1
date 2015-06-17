#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "CityScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
//        glview = GLViewImpl::createWithRect("MyGame1", Rect(0, 0, 960, 640));
        director->setOpenGLView(glview);
    }

    // 设置分辨率
//    Vec2 size = CCDirector::sharedDirector()->getVisibleSize();
    Vec2 size = CCDirector::getInstance()->getVisibleSize();
    
    // ==1 新的适配屏幕
    if (size.y/size.x < 640.0/960.0) {
        float designHeight = 640.0;
//        director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);
        director->getOpenGLView()->setDesignResolutionSize(size.y/designHeight * size.x, designHeight,  ResolutionPolicy::FIXED_HEIGHT);
    }else{
        float designWidth = 960.0;
        director->getOpenGLView()->setDesignResolutionSize(designWidth, 640, ResolutionPolicy::SHOW_ALL);
    }
    
    // ==2 老的适配屏幕
//    if (size.y/size.x < 640.0/960.0) {
//        float designHeight = 640.0;
//        glview->setDesignResolutionSize(size.height/designHeight * size.x, designHeight, kResolutionFixedHeight);
//    }else{
//        float designWidth = 960.0;
//        glview->setDesignResolutionSize(designWidth, 640, kResolutionShowAll);
//    }
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
//    auto scene = HelloWorld::createScene();
    auto scene = CityScene::createScene();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
