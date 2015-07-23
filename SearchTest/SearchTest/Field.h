//
//  Field.h
//  SearchTest
//
//  Created by TakanoriMatsumoto on 2015/07/21.
//  Copyright (c) 2015年 TakanoriMatsumoto. All rights reserved.
//

#ifndef __SearchTest__Field__
#define __SearchTest__Field__

#include <stdio.h>
#include "Panel.h"
#include <vector>

using namespace::std;

class Field {
    vector<Panel> panels;
    
public:
    void setPanels(vector<Panel> _panels);
    void searchTest();
};

#endif /* defined(__SearchTest__Field__) */
