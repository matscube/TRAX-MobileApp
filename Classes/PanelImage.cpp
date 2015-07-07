//
//  PanelImage.cpp
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/07/05.
//
//

#include "PanelImage.h"
USING_NS_CC;

PanelImage::PanelImage() {
    installed = false;
}

PanelImage::~PanelImage() {
    
}

PanelImage *PanelImage::create(PanelImageType type) {
    PanelImage *panelImage = new PanelImage();
    
    std::string fileName;
    int rotation;
    switch (type) {
        case ParallelWhiteLT:
            fileName = "trax_panel1.png";
            rotation = -1;
            break;
        case ParallelWhiteRT:
            fileName = "trax_panel1.png";
            rotation = 0;
            break;
        case ParallelWhiteRD:
            fileName = "trax_panel1.png";
            rotation = 1;
            break;
        case ParallelWhiteLD:
            fileName = "trax_panel1.png";
            rotation = 2;
            break;
        case CrossRedVertical:
            fileName = "trax_panel2.png";
            rotation = 0;
            break;
        case CrossRedHoritonztal:
            fileName = "trax_panel2.png";
            rotation = 1;
            break;
            
        default:
            break;
    }

    
    if (panelImage && panelImage->initWithFile(fileName)) {
        panelImage->autorelease();
        panelImage->initOptions();
        panelImage->addEvents();
        
        panelImage->setRotation(90 * rotation);
        return panelImage;
    }
    
    CC_SAFE_DELETE(panelImage);
    return NULL;
}

void PanelImage::initOptions() {
    
    Size originalSize1 = this->getContentSize();
    Size targetSize = Size(100, 100);
    this->cocos2d::Node::setScale((targetSize.width / originalSize1.width), (targetSize.height / originalSize1.height));
    
}

void PanelImage::addEvents() {
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        PanelImage *target = static_cast<PanelImage*>(event->getCurrentTarget());
        
        if (!target->installed) return false;
        
        target->getEventDispatcher()->pauseEventListenersForTarget(target);
        
        Point locationInNode = target->convertToNodeSpace(touch->getLocation());
        Size s = target->getContentSize();
        Rect rect = Rect(0, 0, s.width, s.height);
        log("target: x = %f, y = %f", locationInNode.x, locationInNode.y);
        
        if (rect.containsPoint(locationInNode)) {
            log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
            
            auto rotateAction = RotateBy::create(0.2, Vec3(0, 0, 90));
            
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

void PanelImage::touchEvent(Touch *touch) {
    
}
