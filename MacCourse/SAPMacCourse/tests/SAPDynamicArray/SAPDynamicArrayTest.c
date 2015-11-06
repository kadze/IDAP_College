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
        SAPDynamicArrayRemoveObjectAtIndex(testDynamicArray, counter - 1);
        elementsCounter--;
        assert(SAPDynamicArrayCount(testDynamicArray) == elementsCounter);
    }
    
    assert(0 == SAPDynamicArrayCount(testDynamicArray));
    assert(0 == SAPDynamicArrayCapacity(testDynamicArray));
    
    SAPObjectRelease(testDynamicArray);
    SAPObjectRelease(testStringObject);
}

void SAPPerformDynamicArraySettingValueTest(void) {
    unsigned long numberOfElementsToAdd = 10000;
    int testIndex = 10000;
    
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");
    assert(testStringObject);
    SAPString *testStringObject2 = SAPStringCreate("string2");
    assert(testStringObject2);
    for (unsigned long counter = 0; counter < numberOfElementsToAdd; counter++) {
        SAPDynamicArrayAddObject(testDynamicArray, testStringObject);
    }
    //setting value at element number 10001 (index 10000)
    SAPDynamicArrayAddObject(testDynamicArray, testStringObject2);
    assert(testIndex == SAPDynamicArrayIndexOfObject(testDynamicArray, testStringObject2));
    assert(testStringObject2 == SAPDynamicArrayObjectAtIndex(testDynamicArray, testIndex));
    
    SAPObjectRelease(testDynamicArray);
    SAPObjectRelease(testStringObject);
    SAPObjectRelease(testStringObject2);
}

void SAPPerformDynamicArrayRemoveObjectAtIndexTest() {
    unsigned long numberOfElementsToAdd = 10;
    int testIndex = 4;
    SAPDynamicArray *testDynamicArray = SAPDynamicArrayCreate();
    assert(testDynamicArray);
    SAPString *testStringObject = SAPStringCreate("ssttrriinngg");
    assert(testStringObject);
    for (unsigned long counter = 0; counter < numberOfElementsToAdd; counter++) {
        SAPDynamicArrayAddObject(testDynamicArray, testStringObject);
    }
    unsigned long countBefore = SAPDynamicArrayCount(testDynamicArray);
    SAPDynamicArrayRemoveObjectAtIndex(testDynamicArray, testIndex);
    unsigned long countAfter = SAPDynamicArrayCount(testDynamicArray);
    //count of elements should decrement ( - 1)
    assert(countBefore == countAfter + 1);
    //all elements in allocated space after last element (index == count - 1) should be NULL
    for (unsigned long index = countAfter; index < SAPDynamicArrayCapacity(testDynamicArray); index++) {
        //assert(NULL == SAPDynamicArrayObjectAtIndex(testDynamicArray, index)); //fall index out of boundary
        void **objects = testDynamicArray->_objects;
        void *val = testDynamicArray->_objects[index];
        assert(NULL == val);
    }
}

void SAPPerformAllDynamicArrayTests(void) {
    printf("===Perform SAPDynamicArray tests ===\n");
//    SAPPerformDynamicArrayReallocatingTest();
//    SAPPerformDynamicArraySettingValueTest();
    SAPPerformDynamicArrayRemoveObjectAtIndexTest();
    printf("OK\n");
}
