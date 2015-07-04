//
//  PanelSprite.cpp
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/30.
//
//

#include "PanelSprite.h"

USING_NS_CC;

PanelSprite::PanelSprite() {
    
}

PanelSprite::~PanelSprite() {
    
}

PanelSprite *PanelSprite::create() {
    PanelSprite *panelSprite = new PanelSprite();
    
    if (panelSprite && panelSprite->initWithFile("trax_panel1.png")) {
        panelSprite->autorelease();
        panelSprite->initOptions();
        panelSprite->addEvents();
        return panelSprite;
    }

    CC_SAFE_DELETE(panelSprite);
    return NULL;
}

void PanelSprite::initOptions() {
    this->status = 0;
    
    Size originalSize1 = this->getContentSize();
    Size targetSize = Size(100, 100);
    this->cocos2d::Node::setScale((targetSize.width / originalSize1.width), (targetSize.height / originalSize1.height));

}

void PanelSprite::addEvents() {
    this->setRotatePanelEvent();
}

void PanelSprite::setChangePanelEvent() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        PanelSprite *target = static_cast<PanelSprite*>(event->getCurrentTarget());
        
        target->getEventDispatcher()->pauseEventListenersForTarget(target);
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto halfRotateAction = RotateBy::create(0.5, Vec3(0, 90, 0));
            CallFunc *replaceImageAction = CallFunc::create([target]() {
                if (target->status == 0) {
                    target->setTexture("trax_panel2.png");
                } else if (target->status == 1) {
                    target->setTexture("trax_panel1.png");
                }
                target->status = (target->status + 1) % 2;
            });
            
            CallFunc *resumeAction = CallFunc::create([target]() {
                target->getEventDispatcher()->resumeEventListenersForTarget(target);
            });
            
            Sequence *seq = Sequence::create(halfRotateAction, replaceImageAction, halfRotateAction, resumeAction, NULL);
            target->runAction(seq);
            
            return true;
        }
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
}

void PanelSprite::setRotatePanelEvent() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        PanelSprite *target = static_cast<PanelSprite*>(event->getCurrentTarget());
        
        target->getEventDispatcher()->pauseEventListenersForTarget(target);
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto rotateAction = RotateBy::create(0.5, Vec3(0, 0, 90));
            
            CallFunc *resumeAction = CallFunc::create([target]() {
                target->getEventDispatcher()->resumeEventListenersForTarget(target);
            });
            
            Sequence *seq = Sequence::create(rotateAction, resumeAction, NULL);
            target->runAction(seq);
            
            return true;
        }
        target->getEventDispatcher()->resumeEventListenersForTarget(target);
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
}
void PanelSprite::touchEvent(Touch *touch) {
    
}
