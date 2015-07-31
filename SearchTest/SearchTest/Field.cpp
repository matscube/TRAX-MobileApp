//
//  Field.cpp
//  SearchTest
//
//  Created by TakanoriMatsumoto on 2015/07/21.
//  Copyright (c) 2015年 TakanoriMatsumoto. All rights reserved.
//

#include "Field.h"

Field::Field() {

}

void Field::searchTest() {
    long ySize = panels.size();
    long xSize = panels[0].size();
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            
        }
    }
}

void Field::searchLoop(Panel start, Panel current) {
    
}

void Field::setPanels(vector<vector<Panel> > _panels) {
    panels = _panels;
}