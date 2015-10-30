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
    assert(testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");

//    for (unsigned long counter = 0lu; counter < 100000; counter++) {
//        SAPDynamicArrayAddElement(testDynamicArray, testStringObject);
//    }
    SAPDynamicArrayAddElement(testDynamicArray, testStringObject);
    //after first add allocatedCount should be 1
    assert(1 == SAPDynamicArrayAllocatedCount(testDynamicArray));
    unsigned long allocatedCounter = 1;
    unsigned long elementsCounter = 1;
    while (elementsCounter < 20) {
        
        if (elementsCounter * 2 == allocatedCounter * 2) {
            allocatedCounter *=2;
        }
        elementsCounter++;
        SAPDynamicArrayAddElement(testDynamicArray, testStringObject);
        assert(elementsCounter == SAPDynamicArrayCount(testDynamicArray));
        assert(allocatedCounter == SAPDynamicArrayAllocatedCount(testDynamicArray));
    }
    
    for (unsigned long counter = 20lu; counter > 0lu; counter--) {
        SAPDynamicArrayRemoveByIndex(testDynamicArray, counter - 1);
    }

    SAPObjectRelease(testDynamicArray);
    SAPObjectRelease(testStringObject);
    printf("OK\n");
}

void SAPPerformAllDynamicArrayTests(void) {
    SAPPerformDynamicArrayReallocatingTest();
}
