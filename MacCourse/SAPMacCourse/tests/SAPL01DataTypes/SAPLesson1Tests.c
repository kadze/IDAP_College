//
//  SAPLesson1Tests.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include "SAPLesson1Tests.h"


int SAPTestPrintTypesSize(){
    SAPPrintTypesSize();
    
    return 0; //success
}

int SAPTestDefineMamaOrPapa(){
    printf("Define mama or papa Testing: \n");
    printf("Try to define with 30 variable value. Suppose mamapapa. \n");
    SAPDefineMamaOrPapa(30);
    printf("Try to define with 10 variable value. Suppose papa. \n");
    SAPDefineMamaOrPapa(10);
    printf("Try to define with 9 variable value. Suppose mama. \n");
    SAPDefineMamaOrPapa(9);
    printf("Try to define with 11 variable value. Suppose suppose nothing bat return value 0. \n");
    int returnValue = SAPDefineMamaOrPapa(11);
    printf("returnvalue = %d\n", returnValue);
    return 0;//success
}