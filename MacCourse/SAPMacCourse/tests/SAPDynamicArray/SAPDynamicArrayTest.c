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
    unsigned long counter = 1;
    //static const uint kSAPSizeMultiplyUntil = 200000;
    //until this value allocated count should double (multiplicator == 2)
    unsigned long counter2 = 1;
    while (counter < 100) {//200000) {
        
        if (counter2 * 2 == counter * 2) {
            counter *=2;
        }
        counter2++;
        SAPDynamicArrayAdd(testDynamicArray, testStringObject);
        assert(counter2 == SAPDynamicArrayCount(testDynamicArray));
        assert(counter == SAPDynamicArrayAllocatedCount(testDynamicArray));
    }
//    //after this value alocatedCount should increment with step 100000
//    //static const uint kSAPSizeIncrement     = 100000;
//    //test until more then ten million after increment
//    while (counter < 10000000) {
//        if (counter2 + 100000 == counter + 100000) {
//            counter += 100000;
//        }
//        counter2++;
//        SAPDynamicArrayAdd(testDynamicArray, testStringObject);
//        assert(counter2 == SAPDynamicArrayCount(testDynamicArray));
//        assert(counter == SAPDynamicArrayAllocatedCount(testDynamicArray));
//    }
    
    for (unsigned long index = SAPDynamicArrayCount(testDynamicArray) - 1
         ; 0 < index; index--) {
        SAPDynamicArrayRemoveByIndex(testDynamicArray, index);
    }
    assert(0 == SAPDynamicArrayCount(testDynamicArray));
    printf("OK\n");
}

void SAPPerformAllDynamicArrayTests(void) {
    SAPPerformDynamicArrayReallocatingTest();
}
