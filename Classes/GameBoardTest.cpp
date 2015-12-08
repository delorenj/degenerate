//
//  GameBoardTest.cpp
//
//
//  Created by Jarad DeLorenzo on 11/23/15.
//
//

#include "GameBoardTest.h"

USING_NS_CC;

Scene* GameBoardTest::createScene() {
    auto scene = Scene::create();
    auto layer = GameBoardTest::create();
    scene->addChild(layer);
    return scene;
}

bool GameBoardTest::init() {
    if(!Node::init()) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    return true;
}
