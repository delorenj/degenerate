//
//  DebugScene.cpp
//
//
//  Created by Jarad DeLorenzo on 11/23/15.
//
//

#include "DebugScene.h"
#include <string>
#include <sstream>

USING_NS_CC;


template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}
Scene* DebugScene::createScene() {
    auto scene = Scene::create();
    auto layer = DebugScene::create();
    scene->addChild(layer);
    return scene;
}

bool DebugScene::init() {
    if(!Layer::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    Point center = Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    
    std::string res = to_string(visibleSize.width) + "x" + to_string(visibleSize.height);
    
    Label* resolutionLabel = Label::createWithSystemFont(res, "Arial", 80);
    resolutionLabel->setPosition(Vec2(center));
    
    this->addChild(resolutionLabel);
    
    // Init keyboard listener stuff
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch* touch, Event* event){
        auto thing = static_cast<DebugScene*>(event->getCurrentTarget());
        thing->returnToGame(thing);
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
    return true;
}

void DebugScene::returnToGame(cocos2d::Ref* pSender) {
    Director::getInstance()->popScene();
}
