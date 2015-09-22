//
//  main.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/15/15
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include "SAPLesson1Tests.h"
#include "SAPMamaOrPapa.h"



int main(int argc, const char * argv[]) {

    //testing
    SAPTestPrintTypesSize();
    SAPTestDefineMamaOrPapa();
    
    //loop
    int iterationAmount = 1000;
    for (int i = 0; i < iterationAmount; i++) {
        SAPDefineMamaOrPapa(i);
    }
    
    return 0;
}


