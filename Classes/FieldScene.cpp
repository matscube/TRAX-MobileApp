//
//  FieldScene.cpp
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/18.
//
//

#include "FieldScene.h"

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
bool FieldScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Size targetSize = Size(100, 100);

    auto panel1 = Sprite::create("trax_panel1.png");
    panel1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    Size originalSize1 = panel1->getContentSize();
    panel1->cocos2d::Node::setScale((targetSize.width / originalSize1.width), (targetSize.height / originalSize1.height));
    this->addChild(panel1, 0);

    auto panel2 = Sprite::create("trax_panel2.png");
    panel2->setPosition(Vec2(visibleSize.width/2 + origin.x + 200, visibleSize.height/2 + origin.y + 200));
//    panel2->setScale(0.5);
    panel2->setContentSize(Size(50, 50));
    this->addChild(panel2, 0);
    
    
    //Size tTargetSize = Size( 100.0f, 200.0f );
/*    Size tSizeOrig = tSprite->getContentSize();
    tSprite->setScale( ( tTargetSize.width / tSizeOrig.width ), ( tTargetSize.height / tSizeOrig.height ) );*/

    
    return true;
}


void FieldScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
