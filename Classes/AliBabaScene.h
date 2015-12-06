//
//  AliBabaScene.h
//  
//
//  Created by Jarad DeLorenzo on 11/23/15.
//
//

#ifndef ____AliBabaScene__
#define ____AliBabaScene__

#include "cocos2d.h"

class AliBabaScene : public cocos2d::Layer {
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(AliBabaScene);
    
    cocos2d::Sprite* skybox;
    cocos2d::Sprite* fg;
    
    void showDebugScreen(cocos2d::Ref* pSender);
};

#endif /* defined(____AliBabaScene__) */
