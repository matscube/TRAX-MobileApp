//
//  Tester.cpp
//  SearchTest
//
//  Created by TakanoriMatsumoto on 2015/07/24.
//  Copyright (c) 2015年 TakanoriMatsumoto. All rights reserved.
//

#include "Tester.h"
#include "Panel.h"
#include "Field.h"
#include <iostream>


void Tester::run_test() {
    std::cout << "Running Test...\n";
    
    Field *field = new Field();
    
    vector<vector<Panel> > panels;
    for (int y = 0; y < 10; y++) {
        vector<Panel> panelLine;
        for (int x = 0; x < 10; x++) {
            panelLine.push_back(Panel(PanelOrientation::RedDownLeft));
        }
        panels.push_back(panelLine);
    }
    field->setPanels(panels);

    field->searchTest();

}