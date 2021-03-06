//
//  Panel.h
//  SearchTest
//
//  Created by TakanoriMatsumoto on 2015/07/20.
//  Copyright (c) 2015年 TakanoriMatsumoto. All rights reserved.
//

#ifndef __SearchTest__Panel__
#define __SearchTest__Panel__

#include <stdio.h>

enum PanelOrientation {
    RedUpRight,
    RedUpLeft,
    RedDownRight,
    RedDownLeft,
    RedVertical,
    RedHorizontal
};

enum PanelColor {
    Red,
    White
};

class Panel {
public:
    PanelOrientation orientation;
    Panel(PanelOrientation _orientation);
};

#endif /* defined(__SearchTest__Panel__) */
