//
//  SAPLesson1Tests.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include "SAPLesson1Tests.h"

# pragma mark-
# pragma mark Private implementations

int SAPTestPrintTypesSize(){
    SAPPrintTypesSize();
    
    return 0; //success
}

int SAPTest1DefineMamaOrPapa(){
    int testParameterMamaPapa = 30;
    int testParameterPapa = 10;
    int testParameterMama = 9;
    int testParameterOutOfCondition = 11;
    parents result;
    printf("================================\n");
    printf("Define mama or papa Testing: \n");
    printf("Try to define with %d variable paramter. Suppose mamapapa. \n", testParameterMamaPapa);
    result = SAPDefineMamaOrPapa(testParameterMamaPapa);
    assert(result == mamapapa);
    printf("mamapapa test result : SUCCESS\n");
    printf("Try to define with %d variable paramter. Suppose papa. \n", testParameterPapa);
    result = SAPDefineMamaOrPapa(testParameterPapa);
    assert(result == papa);
    printf("papa test result : SUCCESS\n");
    printf("Try to define with %d variable value. Suppose mama. \n", testParameterMama);
    result = SAPDefineMamaOrPapa(testParameterMama);
    assert(result == mama);
    printf("mama test result : SUCCESS\n");
    printf("Try to define with %d variable value. Suppose suppose nothing bat return value 0. \n", testParameterOutOfCondition);
    result = SAPDefineMamaOrPapa(testParameterOutOfCondition);
    assert(result == outOfCondition);
    printf("outOfCondition test result : SUCCESS\n");
    
    return 0;
}

int SAPTest2DefineMamaOrPapa(){
    
    printf("================================\n");
    printf("DefineMamaOrPapa testing #2\n");
    int iterationAmount = 1000;
    parents parent = outOfCondition;
    for (int i = 0; i < iterationAmount; i++) {
        parent = SAPDefineMamaOrPapa(i);
        printf("Input %d output %s\n", i, getParentName(parent));
    }
    
    return 0;
}