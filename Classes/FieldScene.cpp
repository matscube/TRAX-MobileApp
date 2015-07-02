//
//  FieldScene.cpp
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/18.
//
//

#include "FieldScene.h"
#include "PanelSprite.h"

USING_NS_CC;

Scene* FieldScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FieldScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool FieldScene::init() {
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(100, 100, 100, 255)) ) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto p = PanelSprite::create();
    p->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(p, 0);
    
    auto p2 = PanelSprite::create();
    p2->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 - 100 + origin.y));
    this->addChild(p2, 0);

    auto p3 = PanelSprite::create();
    p3->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + 100 + origin.y));
    this->addChild(p3, 0);
    
    return true;
}

void FieldScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
