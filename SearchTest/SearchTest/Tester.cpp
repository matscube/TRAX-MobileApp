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
    
    vector<Panel> panels;
    panels.push_back(Panel(PanelOrientation::RedDownLeft));
    field->setPanels(panels);

    field->searchTest();

}