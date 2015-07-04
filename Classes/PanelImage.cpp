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
}

void PanelImage::touchEvent(Touch *touch) {
    
}
