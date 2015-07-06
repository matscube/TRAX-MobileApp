//
//  PanelImage.h
//  TRAX-MobileApp
//
//  Created by TakanoriMatsumoto on 2015/07/05.
//
//

#ifndef __TRAX_MobileApp__PanelImage__
#define __TRAX_MobileApp__PanelImage__

#include <stdio.h>

USING_NS_CC;

enum PanelImageType {
    ParallelWhiteLT,
    ParallelWhiteRT,
    ParallelWhiteLD,
    ParallelWhiteRD,
    CrossRedVertical,
    CrossRedHoritonztal
};

class PanelImage : public Sprite
{
public:
    PanelImage();
    ~PanelImage();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static PanelImage* create(PanelImageType type);
    
    void initOptions();
    bool installed;
    
    void addEvents();
    void touchEvent(Touch *touch);
};

#endif /* defined(__TRAX_MobileApp__PanelImage__) */
