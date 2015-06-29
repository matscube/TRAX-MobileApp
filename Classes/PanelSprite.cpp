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
    
}

void PanelSprite::addEvents() {
    
}

void PanelSprite::touchEvent(Touch *touch) {
    
}
