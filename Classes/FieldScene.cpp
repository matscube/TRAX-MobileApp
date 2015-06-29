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

    Size targetSize = Size(100, 100);
    
    auto p = PanelSprite::create();
    p->setPosition(Vec2(visibleSize.width/2 - 100 + origin.x, visibleSize.height/2 - 100 + origin.y));
    Size originalSizep = p->getContentSize();
    p->cocos2d::Node::setScale((targetSize.width / originalSizep.width), (targetSize.height / originalSizep.height));
    this->addChild(p, 0);
    

    auto panel1 = Sprite::create("trax_panel1.png");
    panel1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    Size originalSize1 = panel1->getContentSize();
    panel1->cocos2d::Node::setScale((targetSize.width / originalSize1.width), (targetSize.height / originalSize1.height));
    this->addChild(panel1, 0);
    
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(this);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);

            auto halfRotateAction = RotateBy::create(0.5, Vec3(0, 90, 0));
            CallFunc *replaceImageAction = CallFunc::create([target]() {
                             target->setTexture("trax_panel2.png");
            });
            Sequence *seq = Sequence::create(halfRotateAction, replaceImageAction, halfRotateAction, NULL);
            target->runAction(seq);

            return true;
        }
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, panel1);

    
    auto panel2 = Sprite::create("trax_panel2.png");
    panel2->setPosition(Vec2(visibleSize.width/2 + 100 + origin.x, visibleSize.height/2 + 100 + origin.y));
    Size originalSize2 = panel2->getContentSize();
    panel2->cocos2d::Node::setScale((targetSize.width / originalSize2.width), (targetSize.height / originalSize2.height));
    this->addChild(panel2, 0);

    auto listener2 = EventListenerTouchOneByOne::create();
    listener2->setSwallowTouches(this);
    
    listener2->onTouchBegan = [](Touch* touch, Event* event) {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto halfRotateAction = RotateBy::create(0.5, Vec3(0, 90, 0));
            CallFunc *replaceImageAction = CallFunc::create([target]() {
                target->setTexture("trax_panel1.png");
            });
            Sequence *seq = Sequence::create(halfRotateAction, replaceImageAction, halfRotateAction, NULL);
            target->runAction(seq);
            
            return true;
        }
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, panel2);

    
    return true;
}

void FieldScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
