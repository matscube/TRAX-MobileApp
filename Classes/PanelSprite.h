//
//  PanelSprite.h
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/06/30.
//
//

#ifndef __TRAX_MobileApp__PanelSprite__
#define __TRAX_MobileApp__PanelSprite__

#include <stdio.h>

USING_NS_CC;

class PanelSprite : public Sprite
{
public:
    PanelSprite();
    ~PanelSprite();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static PanelSprite* create();
    
    int status; // 0 or 1
    
    void initOptions();
    
    void addEvents();
    void touchEvent(Touch *touch);
};

#endif /* defined(__TRAX_MobileApp__PanelSprite__) */
