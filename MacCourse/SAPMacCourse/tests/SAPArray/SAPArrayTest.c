//
//  SAPArrayTest.c
//  MacCourse
//
//  Created by Student 111 on 10/23/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPArray.h"

void SAPPerformAllSAPArrayTests(void) {
    SAPArray *testSAPArray = SAPArrayCreate();
    assert(1 == SAPObjectRetainCount(testSAPArray));
    uint index = 10;
    int value = 5;
    SAPArraySetValueAtIndex(testSAPArray, &value, index);
    int result = (int)SAPArrayValueAtIndex(testSAPArray, 10);
    assert(5 == result);
    
}