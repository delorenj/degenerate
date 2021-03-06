#include "AppDelegate.h"
#include "GameBoardTest.h"
#include "util.h"

USING_NS_CC;

static cocos2d::Size ultra4kResolutionSize = cocos2d::Size(2160,4096);
static cocos2d::Size ipadHDResolutionSize = cocos2d::Size(1536,2048);
static cocos2d::Size nexus5ResolutionSize = cocos2d::Size(1080,1920);
static cocos2d::Size ipadResolutionSize = cocos2d::Size(768,1024);
static cocos2d::Size iphoneHD5ResolutionSize = cocos2d::Size(640,1136);
static cocos2d::Size iphoneHDResolutionSize = cocos2d::Size(640,960);
static cocos2d::Size iphoneResolutionSize = cocos2d::Size(320,480);

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

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::create("Degenerate");
#else
        glview = GLViewImpl::create("Degenerate");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    auto screenSize = glview->getFrameSize();
    auto fileUtils = FileUtils::getInstance();
    std::vector<std::string> resDirOrders;

    if(screenSize.width == ultra4kResolutionSize.width || screenSize.height == ultra4kResolutionSize.width
       ) {
        CCLOG("ultra4kResolutionSize");
        resDirOrders.push_back("ultra4k");
        resDirOrders.push_back("ipadhd");
        resDirOrders.push_back("nexus5");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(ultra4kResolutionSize.width, ultra4kResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.width == ipadHDResolutionSize.width || screenSize.height == ipadHDResolutionSize.width
       ) {
        CCLOG("ipadHDResolutionSize");
        resDirOrders.push_back("ipadhd");
        resDirOrders.push_back("nexus5");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(ipadHDResolutionSize.width, ipadHDResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.height == nexus5ResolutionSize.height || screenSize.width == nexus5ResolutionSize.height
       ) {
        CCLOG("nexus5ResolutionSize");
        resDirOrders.push_back("nexus5");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(ipadHDResolutionSize.width, ipadHDResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.width == ipadResolutionSize.width || screenSize.height == ipadResolutionSize.width
       ) {
        CCLOG("ipadResolutionSize");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(ipadResolutionSize.width, ipadResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.width == iphoneHD5ResolutionSize.width || screenSize.height == iphoneHD5ResolutionSize.width
       ) {
        CCLOG("iphoneHD5ResolutionSize");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(iphoneHD5ResolutionSize.width, iphoneHD5ResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.width == iphoneHDResolutionSize.width || screenSize.height == iphoneHDResolutionSize.width
       ) {
        CCLOG("iphoneHDResolutionSize");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(iphoneHDResolutionSize.width, iphoneHDResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    if(screenSize.width == iphoneResolutionSize.width || screenSize.height == iphoneResolutionSize.width
       ) {
        CCLOG("iphoneResolutionSize");
        resDirOrders.push_back("iphone");
        glview->setDesignResolutionSize(iphoneResolutionSize.width, iphoneResolutionSize.height, ResolutionPolicy::NO_BORDER);
    }

    fileUtils->setSearchPaths(resDirOrders);

    register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = GameBoardTest::createScene();

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
