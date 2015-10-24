//
//  SAPDynamicArrayTest.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "SAPDynamicArrayTest.h"
#include "SAPDynamicArray.h"
#include "SAPString.h"


void SAPPerformDynamicArrayTest(void) {
    printf("===Perform SAPArray tests ===\n");
    
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(NULL != testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");
    SAPDynamicArrayAddElement(testDynamicArray, testStringObject);
    printf("OK\n");
}