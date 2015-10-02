//
//  SAPLesson1Tests.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//
#include <stdio.h>
#include <assert.h>
#include "SAPMamaOrPapa.h"
#include "SAPPrintTypeSize.h"


# pragma mark-
# pragma mark Private implementations

int SAPPerformTestPrintTypeSize(void){
    SAPPrintTypeSize();
    
    return 0; //success
}

int SAPPerformTestDefineParent(void){
    int testParameterMamaPapa = 30;
    int testParameterPapa = 10;
    int testParameterMama = 9;
    int testParameterOutOfCondition = 11;
    parents result;
    printf("================================\n");
    printf("Define parent Testing: \n");
    printf("Try to define with %d variable paramter. Suppose mamapapa. \n", testParameterMamaPapa);
    result = SAPDefineParent(testParameterMamaPapa);
    assert(kSAPMamapapa == result);
    printf("mamapapa test result : SUCCESS\n");
    printf("Try to define with %d variable paramter. Suppose papa. \n", testParameterPapa);
    result = SAPDefineParent(testParameterPapa);
    assert(kSAPPapa == result);
    printf("papa test result : SUCCESS\n");
    printf("Try to define with %d variable value. Suppose mama. \n", testParameterMama);
    result = SAPDefineParent(testParameterMama);
    assert(kSAPMama == result);
    printf("mama test result : SUCCESS\n");
    printf("Try to define with %d variable value. Suppose suppose nothing bat return value 0. \n", testParameterOutOfCondition);
    result = SAPDefineParent(testParameterOutOfCondition);
    assert(kSAPOutOfCondition == result);
    printf("outOfCondition test result : SUCCESS\n");
    
    return 0;
}

int SAPPeformTestDefineParentInLoop(void){
    printf("================================\n");
    printf("DefineParent testing in loop \n");
    int iterationAmount = 1000;
    parents parent = kSAPOutOfCondition;
    for (int i = 0; i < iterationAmount; i++) {
        parent = SAPDefineParent(i);
        printf("Input %d output %s\n", i, getParentName(parent));
    }
    
    return 0;
}