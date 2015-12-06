//
//  DebugScene.h
//
//
//  Created by Jarad DeLorenzo on 11/23/15.
//
//

#ifndef ____DebugScene__
#define ____DebugScene__

#include "cocos2d.h"

class DebugScene : public cocos2d::Layer {

public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(DebugScene);

    virtual void returnToGame(cocos2d::Ref* pSender);
    
};

#endif /* defined(____DebugScene__) */
