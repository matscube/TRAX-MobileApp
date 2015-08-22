//
//  FieldScene.h
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/18.
//
//

#ifndef __TRAX_MobileApp__FieldScene__
#define __TRAX_MobileApp__FieldScene__

#include <stdio.h>
#include "PanelImage.h"

USING_NS_CC;

class FieldScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void addEvents();
    
    void addSelectorListener();
    
    void initPanelSelector();
    PanelImage *parallelWhiteLT;
    PanelImage *crossRV;
    
    void initPanelField();
    void initToolbar();

    // Add new panel
    private: PanelImage *nextPanel;
    
    // implement the "static create()" method manually
    CREATE_FUNC(FieldScene);
};

#endif /* defined(__TRAX_MobileApp__FieldScene__) */
