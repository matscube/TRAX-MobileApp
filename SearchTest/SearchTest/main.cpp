//
//  main.cpp
//  SearchTest
//
//  Created by TakanoriMatsumoto on 2015/07/19.
//  Copyright (c) 2015年 TakanoriMatsumoto. All rights reserved.
//

#include <iostream>
#include "Field.h"
#include "Tester.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Field *field = new Field();
    field->searchTest();
    
    Tester::run_test();
    
    return 0;
}
