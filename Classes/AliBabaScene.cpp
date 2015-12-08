//
//  AliBabaScene.cpp
//  
//
//  Created by Jarad DeLorenzo on 11/23/15.
//
//

#include "AliBabaScene.h"
#include "DebugScene.h"

USING_NS_CC;

Scene* AliBabaScene::createScene() {
    auto scene = Scene::create();
    auto layer = AliBabaScene::create();
    scene->addChild(layer);
    return scene;
}

bool AliBabaScene::init() {
    if(!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    
    // Init background
    skybox = Sprite::create("skybox.png");
    skybox->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(skybox, -1);
    
    // Init snowy ground
    fg = Sprite::create("fg.png");
    fg->setPosition(Point(visibleSize.width/2, fg->getBoundingBox().size.height/2));
    this->addChild(fg, 1);
        
    // Init keyboard listener stuff
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch* touch, Event* event){
        auto thing = static_cast<AliBabaScene*>(event->getCurrentTarget());
        thing->showDebugScreen(thing);
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
    
    return true;
}

void AliBabaScene::showDebugScreen(cocos2d::Ref* pSender) {
    auto scene = DebugScene::createScene();
    Director::getInstance()->pushScene(scene);
}
