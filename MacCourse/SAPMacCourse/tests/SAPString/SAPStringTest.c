//
//  SAPStringTest.c
//  MacCourse
//
//  Created by S A P on 10/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "SAPStringTest.h"
#include "SAPString.h"

void SAPPerformAllSAPStringTests(void) {
    printf("===Perform SAPString tests ===\n");
    SAPString *testString = SAPStringCreate("my test string bla bla");
    //not NULL after creation
    assert(NULL != testString);
    //after creation retainCount must be 1
    assert(1 == SAPObjectRetainCount(testString));
    //value must be "my test string bla bla"
    assert(0 == strcmp("my test string bla bla", SAPStringValue(testString)));
    //change value to "my test string 2"
    SAPStringSetValue(testString, "my test string 2");
    assert(0 == strcmp("my test string 2", SAPStringValue(testString)));
    //letght of value "my test string 2" is 16
    assert(16 == SAPStringLength(testString));
    //test print
    SAPStringSetValue(testString, "this string must be printed\n");
    SAPStringPrint(testString);
    SAPObjectRelease(testString);
    //retain count is 0
    assert(0 == SAPObjectRetainCount(testString));
    printf("OK\n");
}