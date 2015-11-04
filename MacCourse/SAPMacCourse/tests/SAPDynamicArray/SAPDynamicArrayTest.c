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
    unsigned long numberOfElementsToAdd = 20;
    int multiplicatorFromStrategy = 2;
    
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");
    assert(testStringObject);
    SAPDynamicArrayAddObject(testDynamicArray, testStringObject);
    //after first add allocatedCount should be 1
    assert(1 == SAPDynamicArrayCapacity(testDynamicArray));
    unsigned long allocatedCounter = 1;
    unsigned long elementsCounter = 1;
    while (elementsCounter < numberOfElementsToAdd) {
        
        if (elementsCounter * multiplicatorFromStrategy == allocatedCounter * multiplicatorFromStrategy) {
            allocatedCounter *= multiplicatorFromStrategy;
        }
        elementsCounter++;
        SAPDynamicArrayAddObject(testDynamicArray, testStringObject);
        assert(elementsCounter == SAPDynamicArrayCount(testDynamicArray));
        assert(allocatedCounter == SAPDynamicArrayCapacity(testDynamicArray));
    }
    
    for (unsigned long counter = numberOfElementsToAdd; counter > 0; counter--) {
        SAPDynamicArrayRemoveByIndex(testDynamicArray, counter - 1);
    }
    
    SAPObjectRelease(testDynamicArray);
    SAPObjectRelease(testStringObject);
}

void SAPPerformDynamicArraySettingValueTest(void) {
    unsigned long numberOfElementsToAdd = 10000;
    int testIndex = 50;
    
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");
    assert(testStringObject);
    SAPString *testStringObject2 = SAPStringCreate("string2");
    assert(testStringObject2);
    for (unsigned long counter = 0; counter < numberOfElementsToAdd; counter++) {
        SAPDynamicArrayAddObject(testDynamicArray, testStringObject);
    }
    SAPDynamicArraySetValueAtIndex(testDynamicArray, testStringObject2, testIndex);
    assert(testStringObject2 == SAPDynamicArrayValueAtIndex(testDynamicArray, testIndex));
    assert(50 == SAPDynamicArrayIndexOfValue(testDynamicArray, testStringObject2));
    SAPObjectRelease(testDynamicArray);
    SAPObjectRelease(testStringObject);
    SAPObjectRelease(testStringObject2);
}

void SAPPerformAllDynamicArrayTests(void) {
    printf("===Perform SAPArray tests ===\n");
    SAPPerformDynamicArrayReallocatingTest();
    SAPPerformDynamicArraySettingValueTest();
    printf("OK\n");
}
