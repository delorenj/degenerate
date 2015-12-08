//
//  GameGrid.h
//
//
//  Created by Jarad DeLorenzo.
//
//

#ifndef ____GameGrid____
#define ____GameGrid____

#include "cocos2d.h"

class GameGrid : public cocos2d::GridBase {

public:
    GameGrid();
    virtual ~GameGrid();

    virtual bool init();

    CREATE_FUNC(GameGrid);
};

#endif /* defined(____GameGrid____) */