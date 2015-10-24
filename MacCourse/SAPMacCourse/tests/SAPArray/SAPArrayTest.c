//
//  SAPArrayTest.c
//  MacCourse
//
//  Created by Student 111 on 10/23/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPArray.h"
#include "stdio.h"

void SAPPerformAllSAPArrayTests(void) {
    printf("===Perform SAPArray tests ===\n");
    SAPArray *testSAPArray = SAPArrayCreate();
    assert(1 == SAPObjectRetainCount(testSAPArray));
    uint index = 10;
    int value = 5;
    SAPArraySetValueAtIndex(testSAPArray, &value, index);
    int result = *(int*)SAPArrayValueAtIndex(testSAPArray, index);
    assert(value == result);
    SAPArraySetValueAtIndex(testSAPArray, &value, index + 1);
    assert(2 == SAPArrayNotNullElementsCount(testSAPArray));
    SAPObjectRelease(testSAPArray);
    assert(0 == SAPObjectRetainCount(testSAPArray));
    assert(NULL == SAPArrayValueAtIndex(testSAPArray, index));
    printf("OK\n");
}