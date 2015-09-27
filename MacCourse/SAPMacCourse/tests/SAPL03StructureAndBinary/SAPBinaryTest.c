//
//  SAPBinaryTest.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/27/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPBinaryTest.h"
#include "SAPBinaryData.h"

void SAPPerformTestPrintBitsOfAnyTypeNumber(){
    printf("====================BINARY==============\n");
    int value = 100500;
    void* valuePointer = &value;
    SAPPrintBitsOfAnyTypeNumber(valuePointer, sizeof(value));
}

