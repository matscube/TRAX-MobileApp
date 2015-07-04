//
//  FieldScene.cpp
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/18.
//
//

#include "FieldScene.h"
#include "PanelSprite.h"
#include "PanelImage.h"

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
    
    addEvents();
    
    initPanelSelector();
    
    return true;
}

void FieldScene::addEvents() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        
        target->getEventDispatcher()->pauseEventListenersForTarget(target);
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto p3 = PanelSprite::create();
            p3->setPosition(Vec2(locationInNode.x, locationInNode.y));
            target->addChild(p3, 0);
            target->nextPanel = p3;

            target->getEventDispatcher()->resumeEventListenersForTarget(target);

            return true;
        }
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
        return false;
    };
 
    

    listener1->onTouchMoved = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            if (target->nextPanel != nullptr) {
                target->nextPanel->setPosition(locationInNode);
            }
        }
    };
    
    listener1->onTouchEnded = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel = nullptr;
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
    };

    listener1->onTouchCancelled = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel->removeFromParent();
        target->nextPanel = nullptr;
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);

    addSelectorListener();
}

void FieldScene::addSelectorListener() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        
        target->getEventDispatcher()->pauseEventListenersForTarget(target);
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto p3 = PanelSprite::create();
            p3->setPosition(Vec2(locationInNode.x, locationInNode.y));
            target->addChild(p3, 0);
            target->nextPanel = p3;
            
            target->getEventDispatcher()->resumeEventListenersForTarget(target);
            
            return true;
        }
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
        return false;
    };
    
    
    
    listener1->onTouchMoved = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            if (target->nextPanel != nullptr) {
                target->nextPanel->setPosition(locationInNode);
            }
        }
    };
    
    listener1->onTouchEnded = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel = nullptr;
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
    };
    
    listener1->onTouchCancelled = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel->removeFromParent();
        target->nextPanel = nullptr;
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
}

// MARK: - Panel Selector
void FieldScene::initPanelSelector() {
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Size visibleSize = Director::getInstance()->getVisibleSize();

    
    int panelSize = 100;
    int space = 10;
    int zIndex = 1;

    auto bg = Sprite::create();
    Rect rect = Rect(0, 0, panelSize * 2 + space * 3, visibleSize.height);
    bg->setTextureRect(rect);
    bg->setColor(Color3B::BLUE);
    bg->setPosition(Vec2(origin.x + rect.size.width / 2, origin.y + rect.size.height / 2));
    this->addChild(bg, zIndex);
    
    
    
    PanelImage *p = PanelImage::create(ParallelWhiteLT);
    p->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space - panelSize / 2));
    this->addChild(p, zIndex);

    PanelImage *p2 = PanelImage::create(ParallelWhiteRT);
    p2->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space - panelSize / 2));
    this->addChild(p2, zIndex);

    PanelImage *p3 = PanelImage::create(ParallelWhiteRD);
    p3->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space * 2 - panelSize - panelSize / 2));
    this->addChild(p3, zIndex);

    PanelImage *p4 = PanelImage::create(ParallelWhiteLD);
    p4->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space * 2 - panelSize - panelSize / 2));
    this->addChild(p4, zIndex);

    PanelImage *crossRV = PanelImage::create(CrossRedVertical);
    crossRV->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space * 3 - panelSize * 2 - panelSize / 2));
    this->addChild(crossRV, zIndex);
    
    PanelImage *crossRH = PanelImage::create(CrossRedHoritonztal);
    crossRH->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space * 3 - panelSize * 2 - panelSize / 2));
    this->addChild(crossRH, zIndex);

}


void FieldScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
