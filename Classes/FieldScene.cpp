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
    initPanelField();
    
    
    return true;
}

void FieldScene::addEvents() {
    addSelectorListener();
}

void FieldScene::addSelectorListener() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();

        Rect rectLT = target->parallelWhiteLT->getBoundingBox();
        Rect rectRT = target->parallelWhiteRT->getBoundingBox();
        Rect rectLD = target->parallelWhiteLD->getBoundingBox();
        Rect rectRD = target->parallelWhiteRD->getBoundingBox();
        Rect rectRV = target->crossRV->getBoundingBox();
        Rect rectRH = target->crossRH->getBoundingBox();
        int zIndex = 1;
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rectLT.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(ParallelWhiteLT);
            p->setPosition(Vec2(rectLT.origin.x + rectLT.size.width / 2, rectLT.origin.y + rectLT.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        } else if (rectRT.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(ParallelWhiteRT);
            p->setPosition(Vec2(rectRT.origin.x + rectRT.size.width / 2, rectRT.origin.y + rectRT.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        } else if (rectLD.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(ParallelWhiteLD);
            p->setPosition(Vec2(rectLD.origin.x + rectLD.size.width / 2, rectLD.origin.y + rectLD.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        } else if (rectRD.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(ParallelWhiteRD);
            p->setPosition(Vec2(rectRD.origin.x + rectRD.size.width / 2, rectRD.origin.y + rectRD.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        } else if (rectRH.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(CrossRedHoritonztal);
            p->setPosition(Vec2(rectRH.origin.x + rectRH.size.width / 2, rectRH.origin.y + rectRH.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        } else if (rectRV.containsPoint(locationInNode)) {
            PanelImage *p = PanelImage::create(CrossRedVertical);
            p->setPosition(Vec2(rectRV.origin.x + rectRV.size.width / 2, rectRV.origin.y + rectRV.size.height / 2));
            target->addChild(p, zIndex);
            target->nextPanel = p;
            
            return true;
        }
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
                double x = ((int)locationInNode.x / 100) * 100 + 50;
                double y = ((int)locationInNode.y / 100) * 100 + 50;
                Point targetPoint = Point(x, y);
                target->nextPanel->setPosition(targetPoint);
            }
        }
    };
    listener1->onTouchEnded = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel->installed = true;
        target->nextPanel = nullptr;
    };
    listener1->onTouchCancelled = [](Touch* touch, Event* event) {
        FieldScene *target = static_cast<FieldScene*>(event->getCurrentTarget());
        target->nextPanel->removeFromParent();
        target->nextPanel = nullptr;
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
    
    
    
    parallelWhiteLT = PanelImage::create(ParallelWhiteLT);
    parallelWhiteLT->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space - panelSize / 2));
    this->addChild(parallelWhiteLT, zIndex);
    


    parallelWhiteRT = PanelImage::create(ParallelWhiteRT);
    parallelWhiteRT->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space - panelSize / 2));
    this->addChild(parallelWhiteRT, zIndex);

    parallelWhiteRD = PanelImage::create(ParallelWhiteRD);
    parallelWhiteRD->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space * 2 - panelSize - panelSize / 2));
    this->addChild(parallelWhiteRD, zIndex);

    parallelWhiteLD = PanelImage::create(ParallelWhiteLD);
    parallelWhiteLD->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space * 2 - panelSize - panelSize / 2));
    this->addChild(parallelWhiteLD, zIndex);

    crossRV = PanelImage::create(CrossRedVertical);
    crossRV->setPosition(Vec2(origin.x + space + panelSize / 2, origin.y + visibleSize.height - space * 3 - panelSize * 2 - panelSize / 2));
    this->addChild(crossRV, zIndex);
    
    crossRH = PanelImage::create(CrossRedHoritonztal);
    crossRH->setPosition(Vec2(origin.x + space * 2 + panelSize + panelSize / 2, origin.y + visibleSize.height - space * 3 - panelSize * 2 - panelSize / 2));
    this->addChild(crossRH, zIndex);

}

void FieldScene::initPanelField() {
 //   CCDrawNode *node = CCDrawNode::create();
   // node->drawSegment(ccp(0, winSize.height*.5), ccp(winSize.width, winSize.height*.5), 1, ccc4FFromccc3B(ccWHITE));
    for (int x = 0; x < 10; x++) {
        DrawNode *node = DrawNode::create();
        node->drawSegment(Vec2(x * 100, 0), Vec2(x * 100, 1000), 1, Color4F::GREEN);
        this->addChild(node);
    }
    for (int y = 0; y < 10; y++) {
        DrawNode *node = DrawNode::create();
        node->drawSegment(Vec2(0, y * 100), Vec2(1000, y * 100), 1, Color4F::GREEN);
        this->addChild(node);
    }

}

void FieldScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
