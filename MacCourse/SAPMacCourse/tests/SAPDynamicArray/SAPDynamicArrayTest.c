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


void SAPPerformDynamicArrayReallocatingTest(void) {
    printf("===Perform SAPArray tests ===\n");
    
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(NULL != testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");

    SAPDynamicArrayAdd(testDynamicArray, testStringObject);
    //after first add allocatedCount should be 1
    assert(1 == SAPDynamicArrayAllocatedCount(testDynamicArray));
    uint counter = 1;
    //static const uint kSAPSizeMultiplyUntil = 200000;
    //until this value allocated count should double (multiplicator == 2)
    //after this value alocatedCount should increment
    uint counter2 = 1;
    while (counter < 200000) {
        
        if (counter2 * 2 == counter * 2) {
            counter *=2;
        }
        counter2++;
        SAPDynamicArrayAdd(testDynamicArray, testStringObject);
        assert(counter2 == SAPDynamicArrayCount(testDynamicArray));
        assert(counter == SAPDynamicArrayAllocatedCount(testDynamicArray));
    }
//    for (uint counter = 1; counter < 10; counter++) {
//        SAPDynamicArrayAdd(testDynamicArray, testStringObject);
//    }
    //test until ten million
    while (counter < 1000000) {
        <#statements#>
    }
    printf("OK\n");
}

void SAPPerformAllDynamicArrayTests(void) {
    SAPPerformDynamicArrayReallocatingTest();
}
