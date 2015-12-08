//
//  GameBoardTest.h
//
//
//  Created by Jarad DeLorenzo.
//
//

#ifndef ____GameBoardTest____
#define ____GameBoardTest____

#include "cocos2d.h"
#include "GameGrid.h"

class GameBoardTest : public cocos2d::Node {

public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(GameBoardTest);

    GameGrid* pGrid;

};

#endif /* defined(____GameBoardTest____) */